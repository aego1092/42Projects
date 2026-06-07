/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 21:12:06 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/06/07 11:34:29 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

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
