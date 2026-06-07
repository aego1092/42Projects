/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 21:12:06 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/06/07 12:30:33 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
#include <bsd/string.h>
*/

#include <stddef.h>
/*
size_t  strlcat(char *dst, const char *src, size_t size);
*/
size_t	ft_strlen(const char *s);

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
