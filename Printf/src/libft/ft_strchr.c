/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 14:13:34 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/06/21 08:07:57 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
NAME
     ft_strchr — localizza la prima occorrenza di un carattere in una stringa

LIBRARY
     Libreria di Utilità Standard (libft)

SYNOPSIS
     #include "libft.h"

     char *
     ft_strchr(const char *s, int c);

DESCRIPTION
     La funzione ft_strchr() scansiona la stringa puntata da s alla ricerca
     della prima occorrenza del carattere c (convertito in un char).
     
     Il carattere nullo di terminazione ('\0') è considerato a tutti gli
     effetti parte della stringa; pertanto, se c è '\0', la funzione 
     scansiona la stringa fino al termine e restituisce un puntatore al
     carattere di chiusura.

RETURN VALUE
     La funzione ft_strchr() restituisce un puntatore al carattere trovato
     all'interno della stringa s. Se il carattere c non viene rinvenuto,
     la funzione restituisce NULL.

LIMIT CASES
     - Se 'c' è '\0', ritorna il puntatore al termine di 's'.
     - Se 's' è NULL, causa Segmentation Fault.
*/
/*
#include <string.h>
#include <stdio.h>
*/
//#include <stddef.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (*(s + i) != '\0')
	{
		if (*(s + i) == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if ((char)c == '\0')
		return ((char *)(s + i));
	return (NULL);
}
/*
int main(void)
{
    int k;
    char    n[] = "Marghe";

    k = 'r';
    printf("ft_strchr: %s\n", ft_strchr(n, k));
    return (0);
}
*/
