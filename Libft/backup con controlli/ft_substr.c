/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 14:51:01 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/06/15 20:18:54 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h> 

size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_substr_start_after_str_end(char const *s, unsigned int start,
			size_t len);
char	*ft_substr_len_over_str_end(char const *s, unsigned int start,
			size_t len, unsigned int s_lenght);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	s_lenght;
	char			*substr_memory;

	if (!s)
		return (NULL);
	s_lenght = ft_strlen(s);
	if ((start > s_lenght))
		substr_memory = ft_substr_start_after_str_end(s, start, len);
	else if ((s_lenght - start) < len)
		substr_memory = ft_substr_len_over_str_end(s, start, len, s_lenght);
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

char	*ft_substr_start_after_str_end(char const *s, unsigned int start,
	size_t len)
{
	char	*substr_memory;

	substr_memory = malloc((0 + 1) * sizeof(*s));
	if (substr_memory == NULL)
		return (NULL);
	substr_memory[0] = '\0';
	return (substr_memory);
}

char	*ft_substr_len_over_str_end(char const *s, unsigned int start,
	size_t len, unsigned int s_lenght)
{
	char	*substr_memory;

	substr_memory = malloc(((s_lenght - start) + 1) * sizeof(*s));
	if (substr_memory == NULL)
		return (NULL);
	ft_memcpy(substr_memory, &s[start], (s_lenght - start));
	substr_memory[s_lenght - start] = '\0';
	return (substr_memory);
}
