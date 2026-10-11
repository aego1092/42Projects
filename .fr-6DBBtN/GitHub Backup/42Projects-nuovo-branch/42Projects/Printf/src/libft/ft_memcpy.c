/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 11:39:56 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/06/22 11:56:32 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
NAME
     ft_memcpy — copia un'area di memoria

LIBRARY
     Libreria di Utilità Standard (libft)

SYNOPSIS
     #include "libft.h"

     void *ft_memcpy(void *dest, const void *src, size_t n);

DESCRIPTION
     La funzione ft_memcpy() copia 'n' byte dall'area di memoria 'src' 
     all'area di memoria 'dest'. Le due aree NON devono sovrapporsi.

RETURN VALUE
     Ritorna il puntatore originale a 'dest'.

LIMIT CASES
     - Se 'dest' e 'src' si sovrappongono (overlap), il comportamento è 
       indefinito (usare ft_memmove in quel caso).
     - Se sia 'dest' che 'src' sono NULL, la funzione ritorna NULL.
     - Se solo uno dei due è NULL e 'n' > 0, crasha (Segmentation Fault).
*/
// librerie per testare
/*
#include <stdio.h>
#include <string.h>
//#include <stddef.h>*/
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr_dest;
	const unsigned char	*ptr_src;
	size_t				i;

	if (!dest && !src)
		return (NULL);
	ptr_dest = (unsigned char *)dest;
	ptr_src = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		*(ptr_dest + i) = *(ptr_src + i);
		i++;
	}
	return (dest);
}
// main per test
/*
int main(void)
{
    char	*src_str = "ciccio";
    char	*dest_ft = "ciao"; 
    char	*dest_or = "ciao"; 

    ft_memcpy(dest_ft, src_str, 0);
    memcpy(dest_or, src_str, 0);

    printf("Sorgente:  %s\n", src_str);
    printf("ft_memcpy: %s\n", dest_ft);
    printf("memcpy:    %s\n", dest_or);
}*/
