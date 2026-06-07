/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 11:39:56 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/06/07 12:29:31 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// librerie per testare
/*
#include <stdio.h>
#include <string.h>
*/
#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr_dest;
	const unsigned char	*ptr_src;
	size_t				i;

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
    char	*src_str = NULL;
    char	*dest_ft = NULL; 
    // char	*dest_or = NULL; 

    ft_memcpy(dest_ft, src_str, 1);
    // memcpy(dest_or, src_str, 1);

    printf("Sorgente:  %s\n", src_str);
    printf("ft_memcpy: %s\n", dest_ft);
    // printf("memcpy:    %s\n", dest_or);
}
*/