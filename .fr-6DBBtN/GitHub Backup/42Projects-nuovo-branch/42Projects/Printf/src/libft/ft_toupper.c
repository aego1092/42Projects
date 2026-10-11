/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 12:44:08 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/06/21 08:15:02 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
NAME
     ft_toupperr — conversione di lettere in maiuscolo

LIBRARY
     Libreria di Utilità Standard (libft)

SYNOPSIS
     #include "libft.h"

     int ft_toupper(int c);

DESCRIPTION
     ft_toupper() converte una lettera minuscola nel corrispondente maiuscolo.

RETURN VALUE
     Se l'argomento è una lettera modificabile, viene ritornato il carattere 
     convertito; altrimenti viene ritornato il carattere 'c' invariato.
*/
/*
#include <ctype.h>
#include <stdio.h>
*/
//switch lowercase (a, ..., z) to uppercase (A, ..., Z)
int	ft_toupper(int p)
{
	if (p >= 97 && p <= 122)
		return (p - 32);
	else
		return (p);
}
// Main for quick check
/*
int	main(void)
{
	char	test1 = 98;
	ft_toupper(test1);
    printf("ft_toupper: %d\n", ft_toupper(test1));
    printf("ft_toupper: %d\n", toupper(test1));
}
*/
