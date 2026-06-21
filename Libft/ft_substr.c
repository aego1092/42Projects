/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 14:51:01 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/06/21 08:14:35 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
SYNOPSIS
     char *ft_substr(char const *s, unsigned int start, size_t len);

DESCRIPTION
     Alloca (con malloc) e restituisce una stringa estratta da 's'. La nuova 
     stringa inizia dall'indice 'start' e ha una lunghezza massima di 'len'.

RETURN VALUE
     La sottostringa. NULL se l'allocazione fallisce.

LIMIT CASES
     - Se 'start' è maggiore della lunghezza di 's', ritorna una stringa vuota 
       allocata (contenente solo '\0').
     - Se 'len' è maggiore della stringa disponibile a partire da 'start', la 
       sottostringa viene troncata alla fine di 's'.
*/

/*
#include <stddef.h>
#include <stdlib.h> 
size_t	ft_strlen(const char *s);
*/
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_substr_start_after_str_end(char const *s);
char	*ft_substr_len_over_str_end(char const *s, unsigned int start,
			unsigned int s_lenght);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	s_lenght;
	char			*substr_memory;

	if (!s)
		return (NULL);
	s_lenght = ft_strlen(s);
	if ((start > s_lenght))
		substr_memory = ft_substr_start_after_str_end(s);
	else if ((s_lenght - start) < len)
		substr_memory = ft_substr_len_over_str_end(s, start, s_lenght);
	else
	{
		substr_memory = malloc((len + 1) * sizeof(*s));
		if (substr_memory == NULL)
			return (NULL);
		ft_memcpy(substr_memory, &s[start], len);
		substr_memory[len] = '\0';
	}
	return (substr_memory);
}

char	*ft_substr_start_after_str_end(char const *s)
{
	char	*substr_memory;

	substr_memory = malloc((0 + 1) * sizeof(*s));
	if (substr_memory == NULL)
		return (NULL);
	substr_memory[0] = '\0';
	return (substr_memory);
}

char	*ft_substr_len_over_str_end(char const *s, unsigned int start,
	unsigned int s_lenght)
{
	char	*substr_memory;

	substr_memory = malloc(((s_lenght - start) + 1) * sizeof(*s));
	if (substr_memory == NULL)
		return (NULL);
	ft_memcpy(substr_memory, &s[start], (s_lenght - start));
	substr_memory[s_lenght - start] = '\0';
	return (substr_memory);
}
