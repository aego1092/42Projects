/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 13:00:00 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/08/09 13:00:00 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	if (size > 0)
	{
		if (ft_strlen(src) < size)
			ft_memmove(dst, src, ft_strlen(src) + 1);
		else
		{
			ft_memmove(dst, src, size - 1);
			*(dst + size - 1) = '\0';
		}
	}
	return (ft_strlen(src));
}

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
		i = n;
		while (i > 0)
		{
			i--;
			*(ptr_dest + i) = *(ptr_src + i);
		}
	}
	return (dest);
}
