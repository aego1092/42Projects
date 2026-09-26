/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matozzi- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 19:03:15 by matozzi-          #+#    #+#             */
/*   Updated: 2026/07/19 19:07:49 by matozzi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_copy_join(char *result, char *s1, char *s2, int len2)
{
	int	i;
	int	j;

	i = 0;
	while (s1 && s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && j < len2)
	{
		result[i] = s2[j];
		i++;
		j++;
	}
	return (i);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*result;
	int		len1;
	int		len2;
	int		end;

	len1 = 0;
	if (s1)
		len1 = ft_strlen_gnl(s1);
	len2 = ft_strlen_gnl(s2);
	result = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!result)
		return (NULL);
	end = ft_copy_join(result, s1, s2, len2);
	result[end] = '\0';
	if (s1)
		free(s1);
	return (result);
}

static int	ft_read_and_join(int fd, char **stash, char *buffer)
{
	int	bytes_read;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read < 0)
	{
		free(*stash);
		*stash = NULL;
		return (-1);
	}
	if (bytes_read == 0)
		return (0);
	buffer[bytes_read] = '\0';
	*stash = ft_strjoin_gnl(*stash, buffer);
	if (!*stash)
		return (-1);
	return (1);
}

static char	*fill_stash(int fd, char *stash)
{
	char	*buffer;
	int		result;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (stash);
	while (!ft_strchr_gnl(stash, '\n'))
	{
		result = ft_read_and_join(fd, &stash, buffer);
		if (result <= 0)
			break ;
	}
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = fill_stash(fd, stash);
	if (!stash || !*stash)
		return (free(stash), stash = NULL, NULL);
	line = extract_line(stash);
	if (!line)
		return (free(stash), stash = NULL, NULL);
	tmp = stash;
	stash = update_stash(stash);
	free(tmp);
	return (line);
}
