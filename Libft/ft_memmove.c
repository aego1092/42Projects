/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 11:49:34 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/06/07 11:42:57 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
#include <string.h>
*/
#include <stddef.h>

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
