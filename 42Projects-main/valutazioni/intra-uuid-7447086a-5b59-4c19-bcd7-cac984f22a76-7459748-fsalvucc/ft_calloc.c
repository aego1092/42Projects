/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalvucc <fsalvucc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 19:01:30 by fsalvucc          #+#    #+#             */
/*   Updated: 2026/06/05 16:21:44 by fsalvucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*str;
	size_t	nbr;

	if (nmemb == 0 || size == 0)
		return (str = malloc(nmemb * size));
	if (size > (SIZE_MAX / nmemb))
		return (NULL);
	nbr = size * nmemb;
	str = (char *)malloc(nbr * sizeof(char));
	if (str)
	{
		ft_bzero(str, nbr);
		return (&str[0]);
	}
	return (NULL);
}
