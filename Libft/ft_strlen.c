/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 16:16:24 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/06/02 17:52:16 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include <stddef.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
/*
int	main (void)
{
	char str[] = "parola";
	ft_strlen(str);
	printf("ft_strlen: %zu\n", ft_strlen(str));
}
*/
/*
#include <string.h>
#include <stdio.h>
int	main(void)
{
	char *str1 = "Hello, 42!";
	printf("--- TEST 1: Stringa Standard ---\n");
	printf("Stringa: \"%s\"\n", str1);
	printf("Originale `strlen`: %zu\n", strlen(str1));
	printf("ft_strlen: %zu\n", ft_strlen(str1));
	printf("\n");

	char *str2 = "";
	printf("--- TEST 2: Stringa Vuota ---\n");
	printf("Stringa: \"%s\"\n", str2);
	printf("Originale `strlen`: %zu\n", strlen(str2));
	printf("ft_strlen: %zu\n", ft_strlen(str2));
	printf("\n");

	char *str3 = "Char\t\n 42";
	printf("--- TEST 3: Caratteri Speciali (Tab, Newline) ---\n");
	printf("Originale `strlen`: %zu\n", strlen(str3));
	printf("ft_strlen: %zu\n", ft_strlen(str3));
	printf("\n");

	char *str4 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. "
	             "Sed do eiusmod tempor incididunt ut labore et dolore magna
				 aliqua.";
	printf("--- TEST 4: Stringa Lunga ---\n");
	printf("Originale `strlen`: %zu\n", strlen(str4));
	printf("ft_strlen: %zu\n", ft_strlen(str4));
	printf("\n");

	return (0);
}
*/
