/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 17:50:28 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/06/08 13:58:23 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <string.h>
#include <stdio.h>
*/
#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (*(s + i) != '\0')
		i++;
	while (i > 0)
	{
		if (*(s + i) == (char)c)
			return ((char *)(s + i));
		i--;
	}
	if (*(s + i) == (char)c)
		return ((char *)(s + i));
	return (NULL);
}
/* per lavorare solo con i puntatori
char	*ft_strrchr(const char *s, int c)
{
	const char	*last_occurrence;

	while (*s != '\0')
	{
		if (*s == (char)c)
			last_occurrence = s;
		s++;
	}
	if ((char)c == '\0')
		return ((char *)(s));
}
*/
//
/*
int main(void)
{
    int k;
    char    n[] = "Margherita";

    k = 'r';
    printf("ft_strchr: %s\n", ft_strrchr(n, k));
    return (0);
}
*/
