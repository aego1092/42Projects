/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 13:11:57 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/06/20 18:35:50 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
NAME
     ft_strdup — duplica una stringa allocando memoria

LIBRARY
     Libreria di Utilità Standard (libft)

SYNOPSIS
     #include "libft.h"

     char *ft_strdup(const char *s);

DESCRIPTION
     La funzione ft_strdup() alloca con malloc() lo spazio per
     una copia di 's', vi copia il testo e lo restituisce.

RETURN VALUE
     Ritorna la nuova stringa duplicata, o NULL se fallisce.

LIMIT CASES
     - Se 's' è NULL, causa Segmentation Fault.
     - Se 's' è "", alloca 1 byte e ritorna una stringa vuota.
*/
#include <stddef.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

char	*ft_strdup(const char *s)
{
	size_t	s_lenght;
	char	*s_memory;

	s_lenght = ft_strlen(s);
	s_memory = malloc((s_lenght + 1) * sizeof(*s));
	if (s_memory == NULL)
		return (NULL);
	ft_strlcpy(s_memory, s, ((s_lenght + 1) * sizeof(*s)));
	return (s_memory);
}
