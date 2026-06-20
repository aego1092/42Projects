/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 20:15:42 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/06/02 18:20:04 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
NAME
     ft_bzero — scrive zeri in una stringa di byte

LIBRARY
     Libreria di Utilità Standard (libft)

SYNOPSIS
     #include "libft.h"

     void ft_bzero(void *s, size_t n);

DESCRIPTION
     La funzione ft_bzero() cancella i dati nei primi 'n' byte della memoria
     a partire dal punto indicato da 's', scrivendo zeri ('\0') in quell'area.

RETURN VALUE
     Nessun valore restituito.

LIMIT CASES
     - Simile a ft_memset: se 's' è NULL e 'n' > 0 -> Segmentation Fault.
*/
/*
#include <stdio.h>
#include <string.h>
*/
#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		*(ptr + i) = '\0';
		i++;
	}
}
/*
int	main(void)
{
	char	str1[10] = "Hello";
	ft_bzero(str1, 3);
}
*/
/*
int	main(void)
{
	// char	str1[10] = "Hello";
	// char	str2[10] = "Hello";
	// size_t	i;

	// printf("--- TEST FT_BZERO ---\n");
	
	// ft_bzero(str1, 3);
	// bzero(str2, 3);

	// i = 0;
	// while (i < 5)
	// {
	// 	// printf("Byte %zu -> ft_bzero: %d | bzero originale: %d\n", 
	// 			// i, str1[i], str2[i]);
	// 	i++;
	// }

	// if (memcmp(str1, str2, 10) == 0)
	// 	// printf("\n Successo! Il comportamento è identico a bzero.\n");
	// else
	// 	// printf("\n Errore! I comportamenti differiscono.\n");

	// return (0);
}
*/