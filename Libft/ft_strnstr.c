/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 18:09:37 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/06/14 12:37:00 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	lenght_little;

	i = 0;
	lenght_little = ft_strlen(little);
	if (*little == '\0')
		return ((char *)big);
	if (len < lenght_little)
		return (NULL);
	while ((i + lenght_little <= len) && *(big + i) != '\0')
	{
		if ((*(big + i) == *(little + 0))
			&& (ft_strncmp((big + i), little, lenght_little)) == 0)
		{
			return ((char *)(big + i));
		}
		i++;
	}
	return (NULL);
}
