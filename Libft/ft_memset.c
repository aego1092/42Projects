/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 19:25:15 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/06/22 19:04:39 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
NAME
     ft_memset — riempie la memoria con un byte costante

LIBRARY
     Libreria di Utilità Standard (libft)

SYNOPSIS
     #include "libft.h"

     void *ft_memset(void *s, int c, size_t n);

DESCRIPTION
     La funzione ft_memset() riempie i primi 'n' byte dell'area di memoria 
     puntata da 's' con il byte costante 'c' (convertito in unsigned char).

RETURN VALUE
     Ritorna un puntatore all'area di memoria 's'.

LIMIT CASES
     - Se 's' è NULL e 'n' è maggiore di 0, si verifica un Segmentation Fault.
     - Se 'n' è uguale a 0, la funzione non esegue alcuna operazione.
*/
/*
#include <stdio.h>
#include <string.h>
*/
//#include <stddef.h>
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	if (s == NULL)
        return (NULL);
	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		*(ptr + i) = c;
		i++;
	}
	return (s);
}
/*
int	main(void)
{
	char	buffer[] = "Hello!!!!";
	ft_memset(buffer, 'A', 5);
}
*/
/*
int main(void)
{
	printf("--- TEST 1: Stringhe (Caratteri) ---\n");
	char buffer1[10] = "Hello!!!!";
	char buffer2[10] = "Hello!!!!";

	memset(buffer1, 'A', 5);
	ft_memset(buffer2, 'A', 5);

	printf("Originale: %s\n", buffer1);
	printf("La tua   : %s\n", buffer2);

	if (strcmp(buffer1, buffer2) == 0)
		printf("Result: SUCCESS \n\n");
	else
		printf("Result: FAILURE \n\n");


	printf("--- TEST 2: Azzeramento Array di Interi ---\n");
	int arr1[5] = {1, 2, 3, 4, 5};
	int arr2[5] = {1, 2, 3, 4, 5};

	memset(arr1, 0, sizeof(arr1));
	ft_memset(arr2, 0, sizeof(arr2));

	int i = 0;
	int uguali = 1;
	while (i < 5)
	{
		if (arr1[i] != arr2[i])
			uguali = 0;
		i++;
	}

	if (uguali)
		printf("Result: SUCCESS \n");
	else
		printf("Result: FAILURE \n");

	return (0);
}
*/
