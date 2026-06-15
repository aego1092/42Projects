/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalvucc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 18:33:37 by fsalvucc          #+#    #+#             */
/*   Updated: 2026/06/01 21:10:50 by fsalvucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*p;

	p = (char *)s;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return (&p[i]);
		else
			i++;
	}
	if (s[i] == (char)c)
		return (&p[i]);
	else
		return (NULL);
}
