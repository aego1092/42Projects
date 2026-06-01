/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 10:35:14 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/05/31 11:20:37 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
#include <ctype.h>
*/
//verifica se parametro appartene ad (A-Z) oppure ad (a-z) 
int	ft_isalpha(int p)
{
	if ((p >= 65 && p <= 90) || (p >= 97 && p <= 122))
		return (1);
	else
		return (0);
}
// MAIN con test di isalpha e ft_isalpha
/*
int	main(void)
{
	char	test1 = '\0';
	char	test2 = '@';
	char	test3 = 'A';
	char	test4 = 'Z';
	char	test5 = '[';
	char	test6 = 96;
	char	test7 = 'a';
	char	test8 = 'z';
	char	test9 = '{';
	char	test10 = 127;

	if (isalpha((unsigned char)test1) == 0)
		printf("carattere '%c' non è lettera\n",test1);
	else if (ft_isalpha((unsigned char)test1) == 0)
		printf("carattere '%c' non è lettera\n",test1);
	else
		printf("carattere '%c'è lettera\n",test1);
	if (isalpha((unsigned char)test2) == 0)
		printf("carattere '%c' non è lettera\n",test2);
	else if (ft_isalpha((unsigned char)test2) == 0)
		printf("carattere '%c' non è lettera\n",test2);
	else
		printf("carattere '%c'è lettera\n",test2);
	if (isalpha((unsigned char)test3) == 0)
		printf("carattere '%c' non è lettera\n",test3);
	else if (ft_isalpha((unsigned char)test3) == 0)
		printf("carattere '%c' non è lettera\n",test3);
	else
		printf("carattere '%c'è lettera\n",test3);
	if (isalpha((unsigned char)test4) == 0)
		printf("carattere '%c' non è lettera\n",test4);
	else if (ft_isalpha((unsigned char)test4) == 0)
		printf("carattere '%c' non è lettera\n",test4);
	else
		printf("carattere '%c'è lettera\n",test4);
	if (isalpha((unsigned char)test5) == 0)
		printf("carattere '%c' non è lettera\n",test5);
	else if (ft_isalpha((unsigned char)test5) == 0)
		printf("carattere '%c' non è lettera\n",test5);
	else
		printf("carattere '%c'è lettera\n",test5);
	if (isalpha((unsigned char)test6) == 0)
		printf("carattere '%c' non è lettera\n",test6);
	else if (ft_isalpha((unsigned char)test6) == 0)
		printf("carattere '%c' non è lettera\n",test6);
	else
		printf("carattere '%c'è lettera\n",test6);
	if (isalpha((unsigned char)test7) == 0)
		printf("carattere '%c' non è lettera\n",test7);
	else if (ft_isalpha((unsigned char)test7) == 0)
		printf("carattere '%c' non è lettera\n",test7);
	else
		printf("carattere '%c'è lettera\n",test7);
	if (isalpha((unsigned char)test8) == 0)
		printf("carattere '%c' non è lettera\n",test8);
	else if (ft_isalpha((unsigned char)test8) == 0)
		printf("carattere '%c' non è lettera\n",test8);
	else
		printf("carattere '%c'è lettera\n",test8);
	if (isalpha((unsigned char)test9) == 0)
		printf("carattere '%c' non è lettera\n",test9);
	else if (ft_isalpha((unsigned char)test9) == 0)
		printf("carattere '%c' non è lettera\n",test9);
	else
		printf("carattere '%c'è lettera\n",test9);
	if (isalpha((unsigned char)test10) == 0)
		printf("carattere '%c' non è lettera\n",test10);
	else if (ft_isalpha((unsigned char)test10) == 0)
		printf("carattere '%c' non è lettera\n",test10);
	else
		printf("carattere '%c'è lettera\n",test10);
	return 0;
}
*/
