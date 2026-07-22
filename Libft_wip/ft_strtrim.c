/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 16:56:54 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/06/21 08:13:45 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
NAME
     ft_strtrim — rimuove i caratteri esterni indicati in set

LIBRARY
     Libreria di Utilità Standard (libft)

SYNOPSIS
     #include "libft.h"

     char *ft_strtrim(char const *s1, char const *set);

DESCRIPTION
     La funzione ft_strtrim() alloca memoria e copia 's1' senza
     i caratteri di 'set' presenti all'inizio e alla fine.

RETURN VALUE
     Ritorna la stringa modificata, o NULL se la malloc fallisce.

LIMIT CASES
     - Se tutti i caratteri sono in 'set', alloca e ritorna "".
     - Se 's1' o 'set' sono NULL, causa solitamente un crash.
*/
/*
#include <stddef.h>
char	*ft_strchr(const char *s, int c);
*/
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	str = (char *)malloc(sizeof(*s1) * (end - start + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, &s1[start], end - start + 1);
	return (str);
}
