/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 21:12:06 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/06/21 08:09:59 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
NAME
     ft_strlcat — concatena stringhe con limite di dimensione

LIBRARY
     Libreria di Utilità Standard (libft)

SYNOPSIS
     #include "libft.h"

     size_t ft_strlcat(char *dst, const char *src, size_t size);

DESCRIPTION
     La funzione ft_strlcat() concatena 'src' alla fine di 'dst'
     fino a un massimo di (size - strlen(dst) - 1) caratteri.
     Garantisce sempre la terminazione con '\0'.

RETURN VALUE
     Ritorna la lunghezza iniziale di 'dst' più quella di 'src'.
     Se non trova '\0' in 'size' byte, ritorna (size + src_len).

LIMIT CASES
     - Se 'size' <= dst_len, non modifica dst e ritorna la somma
       di 'size' e della lunghezza di 'src'.
*/
/*
#include <stdio.h>
#include <bsd/string.h>
*/
/*
#include <stddef.h>
size_t	ft_strlen(const char *s);
*/
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_initial_len;
	size_t	i;

	dst_initial_len = ft_strlen(dst);
	if (size <= ft_strlen(dst))
		return (size + ft_strlen(src));
	else
	{
		i = 0;
		while ((dst_initial_len + i < size -1) && (*(src + i) != '\0'))
		{
			*(dst + dst_initial_len + i) = *(src + i);
			i++;
		}
		*(dst + dst_initial_len + i) = '\0';
	}
	return (dst_initial_len + ft_strlen(src));
}

/*
int main(void)
{
    char src [] = "parola";
    char dst_ft [30]= "librone"; 
    char dst_or [30] = "librone"; 

	
    printf("ft_strlcat: %zu\n", ft_strlcat(dst_ft, src, 13));
	printf("strlcat:    %zu\n", strlcat(dst_or, src, 13));

	return (0);
}
*/
//printf("Stringa finale (dst_ft):  %s\n", dst); to be inserted before return
