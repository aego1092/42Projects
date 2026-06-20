/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 14:57:29 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/06/20 18:49:52 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
NAME
     ft_split — divide una stringa in un array usando un delimitatore

LIBRARY
     Libreria di Utilità Standard (libft)

SYNOPSIS
     #include "libft.h"

     char **ft_split(char const *s, char c);

DESCRIPTION
     La funzione ft_split() alloca memoria e ritorna un array di stringhe
     ottenuto dividendo 's' usando il carattere 'c' come delimitatore.
     L'array di stringhe deve terminare con un puntatore NULL.

RETURN VALUE
     Ritorna l'array di nuove stringhe risultanti dal frazionamento.
     Ritorna NULL se l'allocazione di memoria fallisce.

LIMIT CASES
     - Se 's' non contiene 'c', ritorna un array con una copia di 's'
       e il puntatore NULL.
     - Se 's' è una stringa vuota, ritorna un array con solo il NULL.
     - Se 's' è NULL, la funzione causa solitamente un crash.
*/
// #include <stdlib.h>
// #include <stddef.h>
// #include <stdio.h>

#include "libft.h"

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);


void	free_mtrx(char **mtrx)
{
	int	i;

	i = 0;
	while (mtrx[i])
	{
		free(mtrx[i]);
		i++;
	}
	free(mtrx);
}
/*
ritorna il numero di parole divise da un separatore 
*/
int countword(char const *s, char c)
{
	int	i;
	int c_char;
	int c_word;

	i = 0;
	c_char = 0;
	c_word = 0;
	while (s[i] != '\0')
	{
		// c_char aumenta se troviamo un non separatore
		if (s[i] != c)
			c_char++;
		// c_word aumenta se abbiamo trovato caratteri prima
		//del separatore o se il carattere successivo e terminatore
		if (c_char > 0 && (s[i] == c || s[i+1] == '\0'))
		{
			c_word++;
			c_char = 0;
		}
		i++;
	}
	return(c_word);
}
// alloca memoria per le k sottostringhe che conterranno le parole divise da separatore
void allocate_mtrx(char **mtrx, char const *s, char c)
{
	int	i;
	int k;
	int c_char;

	i = 0;
	k = 0;
	c_char = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
			c_char++;
			// invece di aumentare c_word allochiamo le sottostringhe di x byte date da c_char
		if (c_char > 0 && (s[i] == c || s[i+1] == '\0'))
		{
			mtrx[k] = (char *) malloc ((c_char + 1)* sizeof(char));
			if(!mtrx[k])
			{
				free_mtrx(mtrx);
				return;
			}
			k++;
			c_char = 0;
		}
		i++;
	}
	// Null terminiamo la matrice
	mtrx[k] = NULL;
}
// inserisco nelle sottostringhe allocate i caratteri c_char delle k parole
void insert_mtrx(char **mtrx, char const *s, char c)
{
	int	i;
	int j;
	int c_char;
	int k;

	i = 0;
	k = 0;
	j = 0;
	c_char = 0;

	while (s[i] != '\0')
	{
		// inserisco il carattere nella riga colonna corretta
		if (s[i] != c)
		{
			mtrx[k][j] = s[i];
			j++;
			c_char++;
		}
		// appena trovo separatore con c_char
		// metto il terminator della parola
		// e mi sposto di riga nella matrice,
		if (c_char > 0 && (s[i] == c || s[i+1] == '\0'))
		{
			mtrx[k][j] = '\0';
			k++;
			j = 0;
			c_char = 0;
		}
		i++;
	}
}
// ritorna una matrice (ptr di ptr) che contiene in ogni riga le parole divise 
// dal separatore (senza separatori) e infine un NULL a chiusura matrice
char **ft_split(const char *s, char c)
{
	int c_word;
	char **mtrx;

	c_word = countword(s,c);
	mtrx = (char **) malloc (sizeof(char *) * (c_word + 1));
	if (!mtrx)
		return (NULL);
	allocate_mtrx(mtrx, s, c);
	insert_mtrx(mtrx, s, c);
	return (mtrx);
}

int main()
{
	char **mtrx = ft_split("abbatuta   tttt abbatutaabbatutaabbatuta", 't');

	int i = 0;
	while(mtrx[i])
	{
		printf("%s\n", mtrx[i]);
		i++;
	}
	free_mtrx(mtrx);
	// free(mtrx);
}

// char **ft_split(char const *s, char c)
// {
// 	size_t	i;
// 	size_t	i_p;
// 	char	*s_dup;

// 	if (!s)
// 		return (NULL);
// 	i = 0;
// 	i_p = 0;
// 	while(i < ft_strlen(s))
// 	{
// 		if((s[i] == c))
// 			i_p++;
// 		i++;
// 	}
// 	if (i_p == ft_strlen(s))
// 		return(NULL);
// }