/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 17:03:05 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/06/21 07:57:41 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
NAME
     ft_memcmp — confronta due blocchi di memoria

LIBRARY
     Libreria di Utilità Standard (libft)

SYNOPSIS
     #include "libft.h"

     int ft_memcmp(const void *s1, const void *s2, size_t n);

DESCRIPTION
     La funzione ft_memcmp() confronta i primi 'n' byte delle aree di memoria
     's1' e 's2' byte per byte.

RETURN VALUE
     Ritorna un intero minore, uguale o maggiore di zero se i primi 'n' byte 
     di 's1' sono rispettivamente minori, uguali o maggiori di quelli di 's2'.

LIMIT CASES
     - Il confronto è fatto tra 'unsigned char'.
     - Se 'n' è 0, ritorna 0.
*/
//#include <stddef.h>
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*t1;
	const unsigned char	*t2;
	size_t				i;

	t1 = (const unsigned char *)s1;
	t2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (t1[i] == t2[i])
			i++;
		else
			return (t1[i] - t2[i]);
	}
	return (0);
}
