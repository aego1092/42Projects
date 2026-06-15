/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giupalum <giupalum@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 17:35:26 by giupalum          #+#    #+#             */
/*   Updated: 2026/06/15 18:45:46 by giupalum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmeb, size_t size)
{
	void	*dst;
	size_t	tot_size;

	tot_size = nmeb * size;
	if (size != 0 && tot_size / size != nmeb)
		return (NULL);
	dst = malloc(tot_size);
	if (!dst)
		return (NULL);
	ft_bzero(dst, tot_size);
	return (dst);
}
