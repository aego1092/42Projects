/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 11:49:45 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/06/02 17:33:27 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//check if a variable belong to ASCII (A, ..., Z) or (a, ..., z) or (1, ...,9)
int	ft_isalpha(int p);
int	ft_isdigit(int p);

int	ft_isalnum(int p)
{
	if (ft_isalpha(p) || ft_isdigit(p))
		return (1);
	else
		return (0);
}
// Main for quick check
/*
int	main(void)
{
	char	test1 = 'B';
	ft_isalpha(test1);
}
*/
// MAIN for comparative test of isalnum and ft_isalnum
/*
#include <stdio.h>
#include <ctype.h>
*/
/*
int	main(void)
{
	char	test1 = '\0';
	char	test2 = '/';
	char	test3 = '1';
	char	test4 = '9';
	char	test5 = ':';
	char	test6 = '@';
	char	test7 = 'A';
	char	test8 = 'Z';
	char	test9 = '[';
	char	test10 = 96;
	char	test11 = 'a';
	char	test12 = 'z';
	char	test13 = '{';
	char	test14 = 127;

	if (isalpha((unsigned char)test1) == 0)
		printf("carattere '%c' non è lettera\n", test1);
	else if (ft_isalpha((unsigned char)test1) == 0)
		printf("carattere '%c' non è lettera\n", test1);
	else
		printf("carattere '%c'è lettera\n", test1);
	if (isdigit((unsigned char)test2) == 0)
		printf("il carattere '%c' non è un numero\n", test2);
	else if (ft_isdigit((unsigned char)test2) == 0)
		printf("carattere '%c' non è numero\n", test2);
	else
		printf("il carattere '%c' è un numero\n", test2);
	if (isdigit((unsigned char)test3) == 0)
		printf("il carattere '%c' non è un numero\n", test3);
	else if (ft_isdigit((unsigned char)test3) == 0)
		printf("carattere '%c' non è numero\n", test3);
	else
		printf("il carattere '%c' è un numero\n", test3);
	if (isdigit((unsigned char)test4) == 0)
		printf("il carattere '%c' non è un numero\n", test4);
	else if (ft_isdigit((unsigned char)test4) == 0)
		printf("carattere '%c' non è numero\n", test4);
	else
		printf("il carattere '%c' è un numero\n", test4);
	if (isdigit((unsigned char)test5) == 0)
		printf("il carattere '%c' non è un numero\n", test5);
	else if (ft_isdigit((unsigned char)test5) == 0)
		printf("carattere '%c' non è numero\n", test5);
	else
		printf("il carattere '%c' è un numero\n", test5);
	if (isalpha((unsigned char)test6) == 0)
		printf("carattere '%c' non è lettera\n", test6);
	else if (ft_isalpha((unsigned char)test6) == 0)
		printf("carattere '%c' non è lettera\n", test6);
	else
		printf("carattere '%c'è lettera\n", test6);
	if (isalpha((unsigned char)test7) == 0)
		printf("carattere '%c' non è lettera\n", test7);
	else if (ft_isalpha((unsigned char)test7) == 0)
		printf("carattere '%c' non è lettera\n", test7);
	else
		printf("carattere '%c'è lettera\n", test7);
	if (isalpha((unsigned char)test8) == 0)
		printf("carattere '%c' non è lettera\n", test8);
	else if (ft_isalpha((unsigned char)test8) == 0)
		printf("carattere '%c' non è lettera\n", test8);
	else
		printf("carattere '%c'è lettera\n", test8);
	if (isalpha((unsigned char)test9) == 0)
		printf("carattere '%c' non è lettera\n", test9);
	else if (ft_isalpha((unsigned char)test9) == 0)
		printf("carattere '%c' non è lettera\n", test9);
	else
		printf("carattere '%c'è lettera\n", test9);
	if (isalpha((unsigned char)test10) == 0)
		printf("carattere '%c' non è lettera\n", test10);
	else if (ft_isalpha((unsigned char)test10) == 0)
		printf("carattere '%c' non è lettera\n", test10);
	else
		printf("carattere '%c'è lettera\n", test10);
	if (isalpha((unsigned char)test11) == 0)
		printf("carattere '%c' non è lettera\n", test11);
	else if (ft_isalpha((unsigned char)test11) == 0)
		printf("carattere '%c' non è lettera\n", test11);
	else
		printf("carattere '%c'è lettera\n", test11);
	if (isalpha((unsigned char)test12) == 0)
		printf("carattere '%c' non è lettera\n", test12);
	else if (ft_isalpha((unsigned char)test12) == 0)
		printf("carattere '%c' non è lettera\n", test12);
	else
		printf("carattere '%c'è lettera\n", test12);
	if (isalpha((unsigned char)test13) == 0)
		printf("carattere '%c' non è lettera\n", test13);
	else if (ft_isalpha((unsigned char)test13) == 0)
		printf("carattere '%c' non è lettera\n", test13);
	else
		printf("carattere '%c'è lettera\n", test13);
	if (isalpha((unsigned char)test14) == 0)
		printf("carattere '%c' non è lettera\n", test14);
	else if (ft_isalpha((unsigned char)test14) == 0)
		printf("carattere '%c' non è lettera\n", test14);
	else
		printf("carattere '%c'è lettera\n", test14);
	return (0);
}
*/
