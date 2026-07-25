/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 11:49:34 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/06/21 07:58:21 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
NAME
     ft_memmove — copia un'area di memoria (gestisce le sovrapposizioni)

LIBRARY
     Libreria di Utilità Standard (libft)

SYNOPSIS
     #include "libft.h"

     void *ft_memmove(void *dest, const void *src, size_t n);

DESCRIPTION
     La funzione ft_memmove() copia 'n' byte dall'area 'src' all'area 'dest'.
     A differenza di ft_memcpy(), permette la sovrapposizione tra le aree: la 
     copia avviene in modo sicuro (leggendo al contrario se dest > src).

RETURN VALUE
     Ritorna il puntatore a 'dest'.

LIMIT CASES
     - Gestisce l'overlap senza corrompere i dati.
     - Se entrambi i puntatori sono NULL, restituisce NULL.
*/
/*
#include <stdio.h>
#include <string.h>
*/
//#include <stddef.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr_dest;
	const unsigned char	*ptr_src;
	size_t				i;

	ptr_dest = (unsigned char *)dest;
	ptr_src = (const unsigned char *)src;
	if (ptr_dest < ptr_src)
	{
		i = 0;
		while (i < n)
		{
			*(ptr_dest + i) = *(ptr_src + i);
			i++;
		}
	}
	else if (ptr_dest > ptr_src)
	{
		i = n ;
		while (i > 0)
		{
			i--;
			*(ptr_dest + i) = *(ptr_src + i);
		}
	}
	return (dest);
}

// main per test
/*
int main(void)
{
    char *src_str = NULL;
    char *dest_ft = NULL; 
    // char *dest_or = NULL; 

    ft_memmove(dest_ft, src_str, 1);
    // memmove(dest_or, src_str, 1);

    printf("Sorgente:  %s\n", src_str);
    printf("ft_memmove: %s\n", dest_ft);
    // printf("memmove:    %s\n", dest_or);
}
*/
