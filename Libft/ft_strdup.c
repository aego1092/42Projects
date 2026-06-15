/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 13:11:57 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/06/15 14:47:19 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
