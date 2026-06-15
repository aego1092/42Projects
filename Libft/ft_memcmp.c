/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 17:03:05 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/06/15 21:46:21 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*t1;
    const unsigned char	*t2;
	size_t			i;

	t1 = (const unsigned char *)s1;
    t2 = (const unsigned char *)s2;
	i = 0;
	
	while (i < n)
	{
		if (t1[i] == t2[i])
			i++;
		else
			return (t1[i] - t2[i]);
	}
	return (0);
}
