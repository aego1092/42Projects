/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 13:43:59 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/06/16 12:06:15 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
NAME
     ft_strlcpy — copia una stringa con dimensione fissa del buffer di arrivo

LIBRARY
     Libreria di Utilità Standard (libft)

SYNOPSIS
     #include "libft.h"

     size_t ft_strlcpy(char *dst, const char *src, size_t size);

DESCRIPTION
     ft_strlcpy() copia fino a 'size - 1' caratteri dalla stringa 'src' a 
     'dst', terminando esplicitamente con un carattere nullo, a patto che 
     'size' sia maggiore di 0.

RETURN VALUE
     Ritorna la lunghezza totale della stringa che ha tentato di creare, ovvero
     la lunghezza di 'src'. Serve a rilevare un eventuale troncamento.

LIMIT CASES
     - Se 'size' è 0, la stringa 'dst' non viene toccata e non viene inserito 
       alcun carattere nullo, ma viene comunque restituito strlen(src).
*/
/*
#include <stdio.h>
*/
#include <stddef.h>

size_t	ft_strlen(const char *s);
void	*ft_memmove(void *dest, const void *src, size_t n);

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	if (size > 0)
	{
		if (ft_strlen(src) < size)
		{
			ft_memmove(dst, src, ft_strlen(src) + 1);
		}
		else
		{
			ft_memmove(dst, src, size - 1);
			*(dst + size -1) = '\0';
		}
	}
	return (ft_strlen(src));
}
/*
int main(void)
{
    char *src [] = "parola";
    char *dst_ft []= "librone"; 
    char *dst_or [] = "librone"; 

    ft_strlcat(dst_ft, src, 1);
    strlcat(dst_or, src, 1);

    printf("Sorgente:  %s\n", src);
    printf("ft_strlcpy: %s\n", dst_ft);
    printf("strlcpy:    %s\n", dst_or);
}
*/
