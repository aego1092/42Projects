/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 20:46:20 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/06/11 22:09:07 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*memchr(const void *s, int c, size_t n)
{
	unsigned char	*t;
	size_t			i;

	if (n == 0)
		return (NULL);

		*t = (unsigned char *)s;
	while ((*(unsigned char*)s != (unsigned char)c) && i < n)
	{
		(unsigned char*)(s + i);
		i++;
	}
	return(s + i)
}
