/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 14:51:01 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/06/15 20:43:57 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h> 

size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	s_length;
	char			*substr_memory;

	s_length = ft_strlen(s);
	substr_memory = malloc((len + 1) * sizeof(*s));
	if (substr_memory == NULL)
		return (NULL);
	ft_memcpy(substr_memory, &s[start], len);
	substr_memory[len] = '\0';
	return (substr_memory);
}
