/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 18:13:26 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/06/21 07:55:30 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
NAME
     ft_calloc — alloca memoria dinamica inizializzata a zero

LIBRARY
     Libreria di Utilità Standard (libft)

SYNOPSIS
     #include "libft.h"

     void *ft_calloc(size_t nmemb, size_t size);

DESCRIPTION
     La funzione ft_calloc() alloca memoria per un array di 'nmemb'
     elementi di 'size' byte ciascuno. La memoria viene azzerata.

RETURN VALUE
     Ritorna il puntatore alla memoria. Ritorna NULL se fallisce
     o se il prodotto 'nmemb * size' genera un overflow.

LIMIT CASES
     - Se 'nmemb' o 'size' è 0, ritorna un puntatore valido unico
       passabile a free(), oppure NULL.
*/
/*
#include <stddef.h>
#include <stdlib.h>
*/
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n);

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb == 0 || size == 0)
		return (ptr = malloc(nmemb * size));
	if ((nmemb != 0) && size > ((size_t) - 1) / nmemb)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ptr = ft_memset(ptr, '\0', (nmemb * size));
	return ((void *)ptr);
}
/*
int main(void)
{
    int     *array;
    size_t  n_elementi = 5;
    size_t  i;

    printf("Richiedo memoria per %zu interi usando ft_calloc..\n", n_elementi);

    // Allocazione di un array di 5 interi
    array = (int *)ft_calloc(n_elementi, sizeof(int));

    // 1. Controllo di sicurezza: verifichiamo se l'allocazione è andata 
    // a buon fine
    if (array == NULL)
    {
        printf("Errore: ft_calloc ha restituito NULL!\n");
        return (1);
    }

    // 2. Dimostrazione dell'azzeramento
    // Stampiamo i valori SENZA averli prima modificati. 
    // Dovrebbero essere tutti rigorosamente 0.
    printf("Contenuto dell'array appena allocato:\n");
    i = 0;
    while (i < n_elementi)
    {
        printf("array[%zu] = %d\n", i, array[i]);
        i++;
    }

    // 3. Modifichiamo i valori giusto per usarli
    printf("\nAssegno dei valori all'array...\n");
    i = 0;
    while (i < n_elementi)
    {
        array[i] = (i + 1) * 10; // 10, 20, 30, 40, 50
        printf("array[%zu] impostato a = %d\n", i, array[i]);
        i++;
    }

    // 4. Liberiamo sempre la memoria allocata
    free(array);
    printf("\nMemoria liberata correttamente.\n");

    return (0);
}*/
