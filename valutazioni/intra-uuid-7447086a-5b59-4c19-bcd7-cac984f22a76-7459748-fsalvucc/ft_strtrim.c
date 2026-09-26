/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalvucc <fsalvucc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 21:56:33 by fsalvucc          #+#    #+#             */
/*   Updated: 2026/06/06 18:01:23 by fsalvucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_set(char const c, char const *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	chk;
	size_t	len;

	chk = 0;
	len = ft_strlen(s1);
	while ((ft_set(s1[chk], set) != 0) && s1[chk])
		chk++;
	while ((ft_set(s1[len - 1], set) == 1) && len > chk)
		len--;
	str = ft_calloc(((len - chk) + 1), sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, (s1 + (chk)), (len - chk + 1));
	return (str);
}
