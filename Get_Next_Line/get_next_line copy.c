/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 12:25:25 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/08/08 18:53:37 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//ssize_t read(int fildes, void *buf, size_t nbyte)

char	*get_next_line(int fd)
{
	if ((fd < 0) || (fd >= OPEN_MAX) || (BUFFER_SIZE <= 0) || (BUFFER_SIZE > INT_MAX))
		return (NULL);
	static char	*stash = NULL;
	char	*buf;
	
	buf = (char *)malloc(((size_t)BUFFER_SIZE + 1) * sizeof(char));
    if (buf == NULL)
        return (NULL);	
	ssize_t	bytes_read;
	
	bytes_read = 1;
	while (ft_strchr(stash, '\n') == NULL && bytes_read > 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buf);
			free(stash);
			stash = NULL;
			return (NULL);
		}
		buf[bytes_read] = '\0';
		stash = ft_strjoin(stash, buf);
	}
	// 1. Il buffer di lettura non serve più, lo liberiamo subito
    free(buf);
    // 2. IF DI CONTROLLO: Se non abbiamo niente in stash (EOF o file vuoto)
    if (stash == NULL || stash[0] == '\0')
    {
        free(stash);
        stash = NULL;
        return (NULL);
    }
    // 3. Se superiamo l'if, significa che in stash c'è ancora del testo da restituire!
    // ... qui estrai la riga e pulisci lo stash ...
	
	char	*line;
// 1. Trova la lunghezza della riga da estrarre (incluso '\n' se c'è)
	size_t i = 0;
	while (stash[i] != '\0' && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++; // Includiamo il '\n' nella riga

	// 2. Alloca 'line' (i + 1 per il '\0' finale)
	line = malloc((i + 1) * sizeof(char));
	if (!line)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	// 3. Copia i caratteri da stash a line
	size_t j = 0;
	while (j < i)
	{
		line[j] = stash[j];
		j++;
	}
	line[j] = '\0';

	// 4. Aggiorna 'stash' con la rimanenza dopo la riga estratta
	// (Se resta qualcosa dopo stash[i], crea un nuovo stash, altrimenti liberalo)
	char *new_stash;
	if (stash[i] != '\0')
	{
		// ft_strdup è perfetta per salvare la parte rimanente della stringa!
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
