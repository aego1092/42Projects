/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 21:12:06 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/06/06 17:55:41 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
size_t	ft_strlen(const char *s);

size_t  ft_strlcat(char *dst, const char *src, size_t size)
{
    size_t  dst_len;
    size_t  i;
    size_t  j;

    dst_len = ft_strlen(dst);
    src_len = ft_strlen(src);

    if (size <= ft_strlen(dst))
        return(size + ft_strlen(src));
    else if (size < ft_strlen(dst_len) + ft_strlen(src) +1)
    {
        i = ft_strlen(dst);
        j = 0;
        while (i < size - 1)
        {
            *(dst + i) = *(src + j);
            i++;
            j++;
        }
        *(dst + i) = '\0';
    }
    else
    {
        i = ft_strlen(dst);
        j = 0;
        while (i < ft_strlen(dst_len) + ft_strlen(src))
        {
            *(dst + i) = *(src + j);
            i++;
            j++;
        }
        *(dst + i) = '\0';
    }
    return(ft_strlen(dst) + ft_strlen(src));
}
