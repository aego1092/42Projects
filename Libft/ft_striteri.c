/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 20:06:15 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/06/21 10:11:37 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
NAME
     ft_striteri — applica una funzione a ogni carattere di una str (in-place)

LIBRARY
     Libreria di Utilità Standard (libft)

SYNOPSIS
     #include "libft.h"

     void ft_striteri(char *s, void (*f)(unsigned int, char*));

DESCRIPTION
     La funzione ft_striteri() attraversa la stringa 's' e applica 
	 la funzione 'f' a ciascun carattere, passandone l'indice come primo 
	 argomento e l'indirizzo del carattere stesso come secondo argomento. 
	 Modifica la stringa originale.

RETURN VALUE
     Nessuno.

LIMIT CASES
     - Se 's' o 'f' sono NULL, la funzione deve interrompersi immediatamente
       per evitare un Segmentation Fault.
*/
#include "libft.h"
/*
void	function(unsigned int par1, char *par2)
{
	*par2 += par1;
}
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*
int main()
{
	char str[] = "abc";
		
	ft_striteri(str, function);
	printf("%s", str);
}
*/
