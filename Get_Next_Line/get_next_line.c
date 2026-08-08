/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 12:25:25 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/08/08 20:06:58 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	separator_finder(char **stash, ssize_t *bytes_read, int fd, char *buf)
{
	while (ft_strchr(*stash, '\n') == NULL && *bytes_read > 0)
	{
		*bytes_read = read(fd, buf, BUFFER_SIZE);
		if (*bytes_read < 0)
		{
			free(buf);
			free(*stash);
			*stash = NULL;
			return;
		}
		buf[*bytes_read] = '\0';
		*stash = ft_strjoin(*stash, buf);
	}
	free(buf);
return;
}

void	str_before_separator(char *stash, size_t i, char **line)
{
	size_t		j;
	
	if (stash[i] == '\n')
		i++;
	*line = malloc((i + 1) * sizeof(char));
	if (!(*line))
		return;
	j = 0;
	while (j < i)
	{
		(*line)[j] = stash[j];
		j++;
	}
	(*line)[j] = '\0';
	return;
}

//|| (fd >= OPEN_MAX) nel primo if
char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*buf;
	ssize_t		bytes_read;
	char		*line;
	size_t		i;
	char		*new_stash;

	
	if ((fd < 0) || (BUFFER_SIZE <= 0) || (BUFFER_SIZE > INT_MAX))
		return (NULL);
	buf = (char *)malloc(((size_t)BUFFER_SIZE + 1) * sizeof(char));
	if (buf == NULL)
		return (NULL);
	bytes_read = 1;
	separator_finder(&stash, &bytes_read, fd, buf);
	if (stash == NULL || stash[0] == '\0')
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	i = 0;
	while (stash[i] != '\0' && stash[i] != '\n')
		i++;
	line = NULL;
	str_before_separator(stash, i, &line);
	if (!line)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	if (stash[i] == '\n')
		i++;
	if (stash[i] != '\0')
	{
		new_stash = ft_strdup(&stash[i]);
		free(stash);
		stash = new_stash;
	}
	else
	{
		free(stash);
		stash = NULL;
	}
	return (line);
}

// while (ft_strchr(stash, '\n') == NULL && bytes_read > 0)
	// {
	// 	bytes_read = read(fd, buf, BUFFER_SIZE);
	// 	if (bytes_read < 0)
	// 	{
	// 		free(buf);
	// 		free(stash);
	// 		stash = NULL;
	// 		return (NULL);
	// 	}
	// 	buf[bytes_read] = '\0';
	// 	stash = ft_strjoin(stash, buf);
	// }
	// free(buf);

		
	// if (stash[i] == '\n')
	// 	i++;
	// line = malloc((i + 1) * sizeof(char));
	// if (!line)
	// {
	// 	free(stash);
	// 	stash = NULL;
	// 	return (NULL);
	// }
	// j = 0;
	// while (j < i)
	// {
	// 	line[j] = stash[j];
	// 	j++;
	// }
	// line[j] = '\0';