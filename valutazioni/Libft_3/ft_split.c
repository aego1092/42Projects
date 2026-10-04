/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalvucc <fsalvucc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 14:42:50 by fsalvucc          #+#    #+#             */
/*   Updated: 2026/06/06 18:03:44 by fsalvucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	ft_wcount(char const *s, char c)
{
	int		i;
	size_t	wc;

	i = 0;
	wc = 0;
	while (s[i])
	{
		if (s[i] != c && i == 0)
			wc++;
		else if ((s[i] == c && s[i + 1] != c) && (s[i + 1]) != '\0')
			wc++;
		i++;
	}
	return (wc);
}

static char	*ft_fillarr(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] != c && s[len])
		len++;
	return (ft_substr(s, 0, len));
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	wc;
	size_t	wc1;
	size_t	i;

	i = 0;
	wc1 = 0;
	wc = ft_wcount(s, c);
	str = (char **)ft_calloc((wc + 1), sizeof (char *));
	if (!str)
		return (NULL);
	while (s[i] && wc1 < wc)
	{
		while (s[i] == c && s[i])
			i++;
		str[wc1] = ft_fillarr(s + i, c);
		wc1++;
		while (s[i] != c && s[i])
			i++;
	}
	return (str);
}
