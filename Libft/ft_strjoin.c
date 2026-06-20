/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 09:49:30 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/06/20 10:02:58 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
SYNOPSIS
     char *ft_strjoin(char const *s1, char const *s2);

DESCRIPTION
     Alloca e restituisce una nuova stringa, risultato della concatenazione 
     di 's1' e 's2'.

RETURN VALUE
     La nuova stringa. NULL se l'allocazione fallisce.

LIMIT CASES
     - Se 's1' o 's2' sono NULL, il comportamento dipende dalla difesa inserita 
       (si protegge ritornando NULL o trattandoli come stringhe vuote).
*/
#include <stddef.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str_memory;

	if (!s1 || !s2)
		return (NULL);
	str_memory = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(*s1));
	if (str_memory == NULL)
		return (NULL);
	ft_memcpy(str_memory, s1, ft_strlen(s1));
	ft_memcpy((str_memory + ft_strlen(s1)), s2, ft_strlen(s2));
	str_memory[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	return (str_memory);
}
