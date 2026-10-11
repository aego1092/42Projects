/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 15:52:22 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/06/20 18:34:07 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
NAME
     ft_isprint — verifica se un carattere è stampabile

LIBRARY
     Libreria di Utilità Standard (libft)

SYNOPSIS
     #include "libft.h"

     int ft_isprint(int c);

DESCRIPTION
     La funzione ft_isprint() controlla se il carattere 'c' è
     stampabile, incluso lo spazio (valori ASCII da 32 a 126).

RETURN VALUE
     Ritorna un valore diverso da 0 se vero, altrimenti 0.

LIMIT CASES
     - I caratteri di controllo (0-31 e 127) ritornano sempre 0.
*/

//check if a variable belong to ASCII and is printable (incl SPACE)
int	ft_isprint(int p)
{
	if (p >= 32 && p <= 126)
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>
*/
/*
int	main(void)
{
	int	i;
	int	res;

	i = -10;
	while (i <= 140)
	{
		res = ft_isprint(i);
		if (res == 1)
		{
			if (i >= 32 && i <= 126)
				printf("Valore %d ('%c'): ASCII (1)\n", i, i);
			else
				printf("Valore %d (Non stampabile): ASCII (1)\n", i);
		}
		else
		{
			printf("Valore %d: NON ASCII (0)\n", i);
		}
		i++;
	}
	return (0);
}
*/
