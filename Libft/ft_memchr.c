/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 20:46:20 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/06/20 19:14:34 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
NAME
     ft_memchr — cerca un byte in un'area di memoria

LIBRARY
     Libreria di Utilità Standard (libft)

SYNOPSIS
     #include "libft.h"

     void *ft_memchr(const void *s, int c, size_t n);

DESCRIPTION
     La funzione ft_memchr() cerca la prima occorrenza di 'c'
     (come unsigned char) nei primi 'n' byte di 's'.

RETURN VALUE
     Ritorna il puntatore al byte trovato, o NULL se assente.

LIMIT CASES
     - Se 'n' è 0, ritorna NULL senza leggere la memoria.
     - Se 's' è NULL e 'n' > 0, causa Segmentation Fault.
*/

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*t;
	size_t			i;

	t = (unsigned char *)s;
	i = 0;
	if (n == 0)
		return (NULL);
	while (i < n)
	{
		if (t[i] == (unsigned char)c)
			return ((void *)&t[i]);
		else
			i++;
	}
	return (NULL);
}
