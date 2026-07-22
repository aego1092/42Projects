/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 14:57:29 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/06/22 08:30:51 by ddi-nico         ###   ########.fr       */
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
// size_t	ft_strlen(const char *s);
// char	*ft_strdup(const char *s);
#include "libft.h"

static void	free_mtrx(char **mtrx);
static int	countword(char const *s, char c);
static void	allocate_mtrx(char **mtrx, char const *s, char c);
static void	insert_mtrx(char **mtrx, char const *s, char c);

static void	free_mtrx(char **mtrx)
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
F_countword => ritorna il numero di parole divise da un separatore 
1st IF nel while =>  c_char aumenta se troviamo un non separatore
2nd IF nel while =>  c_word aumenta se abbiamo trovato caratteri prima
	del separatore o se il carattere successivo e terminatore 
*/
static int	countword(char const *s, char c)
{
	int	i;
	int	c_char;
	int	c_word;

	i = 0;
	c_char = 0;
	c_word = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
			c_char++;
		if (c_char > 0 && (s[i] == c || s[i + 1] == '\0'))
		{
			c_word++;
			c_char = 0;
		}
		i++;
	}
	return (c_word);
}

/*
F_allocatematrix =>alloca memoria per le k sottostringhe
che conterranno le parole divise da separatore
2nd IF nel while =>allochiamo le sottostringhe di x byte date
da c_char (invece di aumentare c_word come in F_countword) 
Null terminiamo la matrice
*/
static void	allocate_mtrx(char **mtrx, char const *s, char c)
{
	int	i;
	int	k;
	int	c_char;

	i = 0;
	k = 0;
	c_char = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
			c_char++;
		if (c_char > 0 && (s[i] == c || s[i + 1] == '\0'))
		{
			mtrx[k] = (char *) malloc ((c_char + 1) * sizeof (char));
			if (!mtrx[k])
				return (free_mtrx(mtrx));
			k++;
			c_char = 0;
		}
		i++;
	}
	mtrx[k] = NULL;
}

/*
F_insert_mtrx => inserisco nelle sottostringhe allocate 
i caratteri c_char delle k parole
1st IF nel while => inserisco il carattere nella riga colonna corretta
2nd IF nel while => appena trovo separatore con c_char
	metto il terminator della parola e mi sposto di riga nella matrice
*/
static void	insert_mtrx(char **mtrx, char const *s, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
			mtrx[k][j++] = s[i];
		if (j > 0 && (s[i] == c || s[i + 1] == '\0'))
		{
			mtrx[k][j] = '\0';
			k++;
			j = 0;
		}
		i++;
	}
}

/*
void	insert_mtrx(char **mtrx, char const *s, char c)
{
	int	i;
	int	j;
	int	c_char;
	int	k;

	i = 0;
	k = 0;
	j = 0;
	c_char = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			mtrx[k][j] = s[i];
			j++;
			c_char++;
		}
		if (c_char > 0 && (s[i] == c || s[i + 1] == '\0'))
		{
			mtrx[k][j] = '\0';
			k++;
			j = 0;
			c_char = 0;
		}
		i++;
	}
}
*/
/*
ritorna una matrice (ptr di ptr) che contiene in ogni riga le parole divise 
dal separatore (senza separatori) e infine un NULL a chiusura matrice
*/
char	**ft_split(const char *s, char c)
{
	char		**mtrx;
	int			c_word;

	c_word = countword(s, c);
	mtrx = (char **) malloc (sizeof (char *) * (c_word + 1));
	if (!mtrx)
		return (malloc(0));
	allocate_mtrx(mtrx, s, c);
	insert_mtrx(mtrx, s, c);
	return (mtrx);
}

/*
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
*/
