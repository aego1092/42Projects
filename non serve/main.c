/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 11:17:03 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/07/26 17:58:02 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	int	r1;
	int	r2;

	printf("==================================================\n");
	printf("               1. TEST CHAR & STRINGS             \n");
	printf("==================================================\n");
	r1 = printf("Orig: [%c] [%c] [%c]\n", 'a', '\0', 'Z');
	r2 = ft_printf("Mine: [%c] [%c] [%c]\n", 'a', '\0', 'Z');
	printf("Ret: Orig = %d | Mine = %d\n\n", r1, r2);

	r1 = printf("Orig: [%s] [%s]\n", "", (char *)NULL);
	r2 = ft_printf("Mine: [%s] [%s]\n", "", (char *)NULL);
	printf("Ret: Orig = %d | Mine = %d\n\n", r1, r2);

	printf("==================================================\n");
	printf("               2. TEST NUMERI (%%d / %%i)           \n");
	printf("==================================================\n");
	r1 = printf("Orig: [%d] [%i] [%d] [%d]\n", 0, 0, INT_MAX, INT_MIN);
	r2 = ft_printf("Mine: [%d] [%i] [%d] [%d]\n", 0, 0, INT_MAX, INT_MIN);
	printf("Ret: Orig = %d | Mine = %d\n\n", r1, r2);

	printf("==================================================\n");
	printf("               3. TEST UNSIGNED (%%u)             \n");
	printf("==================================================\n");
	r1 = printf("Orig: [%u] [%u] [%u]\n", 0, 4294967295U, -1);
	r2 = ft_printf("Mine: [%u] [%u] [%u]\n", 0, 4294967295U, -1);
	printf("Ret: Orig = %d | Mine = %d\n\n", r1, r2);

	printf("==================================================\n");
	printf("               4. TEST HEX (%%x / %%X)              \n");
	printf("==================================================\n");
	r1 = printf("Orig: [%x] [%X] [%x] [%X]\n", 0, 0, 42, 3735928559U);
	r2 = ft_printf("Mine: [%x] [%X] [%x] [%X]\n", 0, 0, 42, 3735928559U);
	printf("Ret: Orig = %d | Mine = %d\n\n", r1, r2);

	printf("==================================================\n");
	printf("               5. TEST POINTERS (%%p)              \n");
	printf("==================================================\n");
	int a = 42;
	r1 = printf("Orig: [%p] [%p] [%p]\n", (void *)&a, (void *)NULL, (void *)-1);
	r2 = ft_printf("Mine: [%p] [%p] [%p]\n", (void *)&a, (void *)NULL, (void *)-1);
	printf("Ret: Orig = %d | Mine = %d\n\n", r1, r2);

	printf("==================================================\n");
	printf("               6. TEST PERCENT & MIX              \n");
	printf("==================================================\n");
	r1 = printf("Orig: %%%%%% | %d%% %s\n", 42, "prova");
	r2 = ft_printf("Mine: %%%%%% | %d%% %s\n", 42, "prova");
	printf("Ret: Orig = %d | Mine = %d\n\n", r1, r2);

	return (0);
}