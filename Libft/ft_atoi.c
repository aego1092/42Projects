/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 12:38:32 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/06/14 18:11:45 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
#include <stdlib.h>
*/

int	ft_atoi_helper(const char *nptr, int x, int y, int z);
int	ft_atoi_helper_spazi(const char *nptr, int *i, int *x);
int	ft_atoi_helper_segni(const char *nptr, int *i, int *y);
int	ft_atoi_helper_numeri(const char *nptr, int *i, int *z);

int	ft_atoi(const char *nptr)
{
	int	i;
	int	x;
	int	y;
	int	z;

	i = 0;
	x = 0;
	y = 0;
	z = 0;
	ft_atoi_helper_spazi(nptr, &i, &x);
	ft_atoi_helper_segni(nptr, &i, &y);
	ft_atoi_helper_numeri(nptr, &i, &z);
	if (z >= 1)
	{
		if (y == 1 && nptr[x + y - 1] == 45)
			return (-1 * ft_atoi_helper(nptr, x, y, z));
		return (ft_atoi_helper(nptr, x, y, z));
	}
	return (0);
}

int	ft_atoi_helper_spazi(const char *nptr, int *i, int *x)
{
	while (((nptr[*i] == 32) || ((nptr[*i] >= 9) && (nptr[*i] <= 13)))
		&& nptr[*i])
	{
		(*x)++;
		(*i)++;
	}
	return (0);
}

int	ft_atoi_helper_segni(const char *nptr, int *i, int *y)
{
	if (((nptr[*i] == 43) || (nptr[*i] == 45)) && nptr[*i])
	{
		(*y)++;
		(*i)++;
	}
	return (0);
}

int	ft_atoi_helper_numeri(const char *nptr, int *i, int *z)
{
	while (((nptr[*i] >= 48) && (nptr[*i] <= 57)) && nptr[*i])
	{
		(*z)++;
		(*i)++;
	}
	return (0);
}

int	ft_atoi_helper(const char *nptr, int x, int y, int z)
{
	if (z == 1)
		return (nptr[x + y + z -1] - 48);
	return ((nptr[x + y + z -1] - 48)
		+ 10 * ft_atoi_helper(nptr, x, y, (z - 1)));
}
/*
int main(void)
{
    printf("--- TEST FT_ATOI ---\n\n");

    // Test 2: Numero negativo standard
    printf("Test 2 [\"-42\"]:\n");
    printf("Originale: %d\n", atoi("-42"));
    printf("La tua  : %d\n\n", ft_atoi("-42"));

    // Test 3: Spazi iniziali (Tab, Newline, Spazi classici) e segno +
    printf("Test 3 [\" \\t\\n +567\"]:\n");
    printf("Originale: %d\n", atoi(" \t\n +567"));
    printf("La tua  : %d\n\n", ft_atoi(" \t\n +567"));

    // Test 4: Test con zeri iniziali
    printf("Test 4 [\"0000123\"]:\n");
    printf("Originale: %d\n", atoi("0000123"));
    printf("La tua  : %d\n\n", ft_atoi("0000123"));

    // Test 5: Lettere dopo i numeri (deve interrompersi al
	primo carattere non numerico)
    printf("Test 5 [\"-897ab54\"]:\n");
    printf("Originale: %d\n", atoi("-897ab54"));
    printf("La tua  : %d\n\n", ft_atoi("-897ab54"));

    // Test 6: Stringa che non comincia con un numero o segno valido
    printf("Test 6 [\"abc123\"]:\n");
    printf("Originale: %d\n", atoi("abc123"));
    printf("La tua  : %d\n\n", ft_atoi("abc123"));

    // Test 7: Stringa vuota
    printf("Test 7 [\"\"]:\n");
    printf("Originale: %d\n", atoi(""));
    printf("La tua  : %d\n\n", ft_atoi(""));

    return (0);
}
*/
