/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matozzi- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 18:50:21 by matozzi-          #+#    #+#             */
/*   Updated: 2026/07/19 19:08:23 by matozzi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen_gnl(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr_gnl(char *s, char c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (s[i] == c)
		return (&s[i]);
	return (NULL);
}

char	*extract_line(char *stash)
{
	char	*container;
	int		i;
	int		j;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	container = malloc(sizeof(char) * (i + (stash[i] == '\n') + 1));
	if (!container)
		return (NULL);
	j = 0;
	while (j < i)
	{
		container[j] = stash[j];
		j++;
	}
	if (stash[i] == '\n')
		container[j++] = '\n';
	container[j] = '\0';
	return (container);
}

char	*update_stash(char *stash)
{
	int		i;
	int		h;
	char	*container2;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
		return (NULL);
	i++;
	container2 = malloc(ft_strlen_gnl(&stash[i]) + 1);
	if (!container2)
		return (NULL);
	h = 0;
	while (stash[i])
		container2[h++] = stash[i++];
	container2[h] = '\0';
	return (container2);
}
