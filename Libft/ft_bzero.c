/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 20:15:42 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/06/01 09:47:42 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
#include <string.h>
/**/
void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		*(ptr + i) = '\0';
		i++;
	}
}
*/
/*
int	main(void)
{
	char	str1[10] = "Hello";
	char	str2[10] = "Hello";
	size_t	i;

	printf("--- TEST FT_BZERO ---\n");
	
	ft_bzero(str1, 3);
	bzero(str2, 3);

	i = 0;
	while (i < 5)
	{
		printf("Byte %zu -> ft_bzero: %d | bzero originale: %d\n", 
				i, str1[i], str2[i]);
		i++;
	}

	if (memcmp(str1, str2, 10) == 0)
		printf("\n Successo! Il comportamento è identico a bzero.\n");
	else
		printf("\n Errore! I comportamenti differiscono.\n");

	return (0);
}
*/
