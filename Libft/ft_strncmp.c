/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 20:03:54 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/06/20 18:35:55 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
NAME
     ft_strncmp — confronta stringhe fino a un limite n

LIBRARY
     Libreria di Utilità Standard (libft)

SYNOPSIS
     #include "libft.h"

     int ft_strncmp(const char *s1, const char *s2, size_t n);

DESCRIPTION
     La funzione ft_strncmp() confronta 's1' e 's2' fino a un
     massimo di 'n' caratteri.

RETURN VALUE
     Ritorna un intero <, == o > di zero se 's1' è minore,
     uguale o maggiore di 's2'.

LIMIT CASES
     - Se 'n' è uguale a 0, ritorna 0.
     - Se una stringa finisce prima di 'n', il confronto si ferma.
*/
#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && i < n - 1)
	{
		if (s1[i] == s2[i])
			i++;
		else
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
