/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 12:38:32 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/06/23 11:55:10 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
NAME
     ft_atoi — converte una stringa in un intero

LIBRARY
     Libreria di Utilità Standard (libft)

SYNOPSIS
     #include "libft.h"

     int ft_atoi(const char *nptr);

DESCRIPTION
     La funzione ft_atoi() converte la parte iniziale della stringa
     puntata da 'nptr' in un valore intero (int). Salta gli spazi
     iniziali, gestisce il segno e converte le cifre successive.

RETURN VALUE
     Ritorna l'intero convertito, o 0 se non trova cifre valide.

LIMIT CASES
     - Se la stringa è vuota o ha solo spazi, ritorna 0.
     - Gestisce l'overflow/underflow standard basico.
     - Se 'nptr' è NULL, causa Segmentation Fault.
*/
/*
#include <stdio.h>
#include <stdlib.h>
*/

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	res = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\r'
		|| str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
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
