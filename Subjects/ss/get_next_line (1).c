/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 12:25:25 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/08/09 14:41:05 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*init_stash_and_buf(char **stash, char **buf)
{
	*buf = (char *)malloc(((size_t)BUFFER_SIZE + 1) * sizeof(char));
	if (*buf == NULL)
		return (NULL);
	if (*stash == NULL)
		*stash = ft_strdup("");
	if (*stash == NULL)
	{
		free(*buf);
		*buf = NULL;
		return (NULL);
	}
	return (*buf);
}

void	separator_finder(char **stash, ssize_t *bytes_read, int fd, char *buf)
{
	char	*tmp_stash;

	while (*stash && ft_strchr(*stash, '\n') == NULL && *bytes_read > 0)
	{
		*bytes_read = read(fd, buf, BUFFER_SIZE);
		if (*bytes_read < 0)
		{
			free(buf);
			free(*stash);
			*stash = NULL;
			return ;
		}
		buf[*bytes_read] = '\0';
		tmp_stash = *stash;
		*stash = ft_strjoin(tmp_stash, buf);
	}
	free(buf);
	if (*stash != NULL && (*stash)[0] == '\0')
	{
		free(*stash);
		*stash = NULL;
	}
	return ;
}

void	str_before_separator(char *stash, size_t i, char **line)
{
	size_t		j;

	if (stash == NULL)
		return ;
	if (stash[i] == '\n')
		i++;
	*line = malloc((i + 1) * sizeof(char));
	if ((*line) == NULL)
		return ;
	j = 0;
	while (j < i)
	{
		(*line)[j] = stash[j];
		j++;
	}
	(*line)[j] = '\0';
	return ;
}

void	str_after_separator(char **stash, size_t i)
{
	char		*new_tmp_stash;

	if (stash == NULL || *stash == NULL)
		return ;
	if ((*stash)[i] == '\n')
		i++;
	if ((*stash)[i] != '\0')
	{
		new_tmp_stash = ft_strdup(&(*stash)[i]);
		free((*stash));
		(*stash) = new_tmp_stash;
	}
	else
	{
		free((*stash));
		(*stash) = NULL;
	}
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*buf;
	ssize_t		bytes_read;
	char		*line;
	size_t		i;

	if ((fd < 0) || (BUFFER_SIZE <= 0) || (BUFFER_SIZE > INT_MAX))
		return (NULL);
	if (init_stash_and_buf(&stash, &buf) == NULL)
		return (NULL);
	bytes_read = 1;
	separator_finder(&stash, &bytes_read, fd, buf);
	if (stash == NULL)
		return (NULL);
	i = 0;
	while (stash[i] != '\0' && stash[i] != '\n')
		i++;
	str_before_separator(stash, i, &line);
	if (!line)
		return (free(stash), stash = NULL, NULL);
	str_after_separator(&stash, i);
	return (line);
}
