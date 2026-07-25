/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 21:48:37 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/06/21 10:12:48 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
NAME
    ft_strmapi — crea una nuova stringa applicando una funzione a 
	ogni carattere

LIBRARY
    Libreria di Utilità Standard (libft)

SYNOPSIS
    #include "libft.h"

    char *ft_strmapi(char const *s, char (*f)(unsigned int, char));

DESCRIPTION
    La funzione ft_strmapi() applica la funzione 'f' a ciascun carattere della
    stringa 's' passandone l'indice. Crea una nuova stringa (allocata 
	tramite malloc) per raccogliere i risultati dei successivi utilizzi di 'f'.

RETURN VALUE
     La nuova stringa creata. NULL se l'allocazione di memoria fallisce.

LIMIT CASES
     - Se 's' o 'f' sono NULL, restituisce NULL.
     - Se la malloc fallisce, restituisce NULL.
*/
#include "libft.h"
// Una funzione d'esempio da passare a ft_strmapi
/*char	f_esempio(unsigned int i, char c)
{
	// Se l'indice è pari, trasforma in maiuscolo (se è una lettera minuscola)
	if (i % 2 == 0 && (c >= 'a' && c <= 'z'))
		return (c - 32);
	return (c);
}
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			str;
	char			*ptr_str;

	ptr_str = &str;
	if (!s || !f)
		return (NULL);
	ptr_str = (char *)malloc(sizeof(str) * (ft_strlen(s) + 1));
	if (!ptr_str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ptr_str[i] = f(i, s[i]);
		i++;
	}
	ptr_str[i] = '\0';
	return (ptr_str);
}

/*
int	main(void)
{
	char	*str = "ciao";
	char	*risultato;

	risultato = ft_strmapi(str, f_esempio);
	printf("%s\n", risultato); // Stamperà "CiAo"
	free(risultato);
	return (0);
}
*/
