/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcorasan <kcorasan@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 17:18:09 by kcorasan          #+#    #+#             */
/*   Updated: 2026/06/20 17:18:09 by kcorasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	lend;
	size_t	lens;
	size_t	i;

	lend = 0;
	while (lend < dstsize && dst[lend])
		lend++;
	lens = ft_strlen(src);
	if (lend == dstsize)
		return (dstsize + lens);
	i = 0;
	while (lend + i + 1 < dstsize && src[i])
	{
		dst[lend + i] = src[i];
		i++;
	}
	dst[lend + i] = '\0';
	return (lend + lens);
}
