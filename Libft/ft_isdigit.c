/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 10:37:45 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/05/31 11:47:55 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
#include <ctype.h>
*/
//verifica se parametro appartene ad (1 -9)
int	ft_isdigit(int p)
{
	if (p >= '0' && p <= '9')
		return (1);
	return (0);
}
// MAIN con test di isdigit e ft_isdigit
/*
int	main(void)
{
	char	test1;
	char	test2;
	char	test3;
	char	test4;
	char	test5;
	char	test6;

	test1 = '\0';
	test2 = '/';
	test3 = '1';
	test4 = '9';
	test5 = ':';
	test6 = 127;
	if (isdigit((unsigned char)test1) == 0)
		printf("il carattere '%c' non è un numero\n", test1);
	else
		printf("il carattere '%c' è un numero\n", test1);
	if (isdigit((unsigned char)test2) == 0)
		printf("il carattere '%c' non è un numero\n", test2);
	else
		printf("il carattere '%c' è un numero\n", test2);
	if (isdigit((unsigned char)test3) == 0)
		printf("il carattere '%c' non è un numero\n", test3);
	else
		printf("il carattere '%c' è un numero\n", test3);
	if (isdigit((unsigned char)test4) == 0)
		printf("il carattere '%c' non è un numero\n", test4);
	else
		printf("il carattere '%c' è un numero\n", test4);
	if (isdigit((unsigned char)test5) == 0)
		printf("il carattere '%c' non è un numero\n", test5);
	else
		printf("il carattere '%c' è un numero\n", test5);
	if (isdigit((unsigned char)test6) == 0)
		printf("il carattere '%c' non è un numero\n", test6);
	else
		printf("il carattere '%c' è un numero\n", test6);
	if (ft_isdigit((unsigned char)test1) == 0)
		printf("il carattere '%c' non è un numero\n", test1);
	else
		printf("il carattere '%c' è un numero\n", test1);
	if (ft_isdigit((unsigned char)test2) == 0)
		printf("il carattere '%c' non è un numero\n", test2);
	else
		printf("il carattere '%c' è un numero\n", test2);
	if (ft_isdigit((unsigned char)test3) == 0)
		printf("il carattere '%c' non è un numero\n", test3);
	else
		printf("il carattere '%c' è un numero\n", test3);
	if (ft_isdigit((unsigned char)test4) == 0)
		printf("il carattere '%c' non è un numero\n", test4);
	else
		printf("il carattere '%c' è un numero\n", test4);
	if (ft_isdigit((unsigned char)test5) == 0)
		printf("il carattere '%c' non è un numero\n", test5);
	else
		printf("il carattere '%c' è un numero\n", test5);
	if (ft_isdigit((unsigned char)test6) == 0)
		printf("il carattere '%c' non è un numero\n", test6);
	else
		printf("il carattere '%c' è un numero\n", test6);
}
*/
