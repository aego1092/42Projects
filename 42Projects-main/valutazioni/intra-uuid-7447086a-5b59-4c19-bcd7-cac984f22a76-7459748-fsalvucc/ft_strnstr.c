/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalvucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 12:03:05 by fsalvucc          #+#    #+#             */
/*   Updated: 2026/06/04 18:59:59 by fsalvucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	nb;
	size_t	i;

	nb = 0;
	if (!little[nb])
		return ((char *)big);
	while (big[nb] && nb < len)
	{
		i = 0;
		while ((little[i]) && (little[i] == big[nb + i])
			&& (nb + i < len))
		{
			i++;
		}
		if (i == ft_strlen(little))
			return ((char *)big + nb);
		else
			nb++;
	}
	return (NULL);
}
