/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 13:43:59 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/06/02 21:35:51 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>

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
/**/
int main(void)
{
    char src [] = "parola";
    char dst_ft []= "librone"; 
    // char *dst_or [] = "librone"; 

    ft_strlcpy(dst_ft, src, 1);
    // strlcpy(dst_or, src_str, 1);

    printf("Sorgente:  %s\n", src);
    printf("ft_memcpy: %s\n", dst_ft);
    // printf("memcpy:    %s\n", dst_or);
}
/**/
