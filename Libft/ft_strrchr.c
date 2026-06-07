/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 17:50:28 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/06/07 18:08:00 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <string.h>
#include <stdio.h>
*/
char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (*(s + i) != '\0')
		i++;
	while (i >= 0)
	{
		if (*(s + i) == (char)c)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}
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
