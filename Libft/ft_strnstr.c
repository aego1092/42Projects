/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/13 18:09:37 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/06/20 14:35:47 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** FT_STRNSTR  Biblioteca delle Funzioni di Libft
**
** NOME
**      ft_strnstr - localizza una sotto-stringa in una stringa
**                   a lunghezza limitata
**
** SINOPSI
**      #include "libft.h"
**
**      char *
**      ft_strnstr(const char *big, const char *little, size_t len);
**
** DESCRIZIONE
**      La funzione ft_strnstr() individua la prima occorrenza della stringa
**      'little' (terminata dal carattere nullo) all'interno della stringa
**      'big', dove non vengono cercati più di 'len' caratteri.
**
**      I caratteri che compaiono dopo il carattere '\0' non vengono cercati.
**      Poiché la funzione ft_strnstr() è una specifica API di tipo BSD,
**      dovrebbe essere usata solo quando la portabilità non è una priorità.
**
** VALORI DI RITORNO
**      Se 'little' è una stringa vuota, viene restituito 'big'.
**
**      Se 'little' non compare da nessuna parte in 'big' entro i primi 'len'
**      caratteri, viene restituito NULL.
**
**      Altrimenti, viene restituito un puntatore al primo carattere della prima
**      occorrenza di 'little' trovata.
**
** ESEMPI
**      Il seguente codice:
**
**            char *ptr = ft_strnstr("42 Network", "Net", 8);
**
**      Trova la sotto-stringa e assegna a 'ptr' il puntatore che punta alla
**      sotto-stringa "Network" dentro la stringa originale.
**
**      Il seguente codice invece:
**
**            char *ptr = ft_strnstr("42 Network", "Net", 5);
**
**      Restituisce NULL poiché, sebbene il match inizi all'indice 3, la sua
**      completa corrispondenza estenderebbe la ricerca oltre il limite di 5
**      caratteri specificato da 'len'.
**
** VEDI ANCHE
**      strstr(3), strchr(3), strrchr(3), memchr(3)
*/

#include <stddef.h>

size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	lenght_little;

	i = 0;
	lenght_little = ft_strlen(little);
	if (*little == '\0')
		return ((char *)big);
	if (len < lenght_little)
		return (NULL);
	while ((i + lenght_little <= len) && *(big + i) != '\0')
	{
		if ((*(big + i) == *(little + 0))
			&& (ft_strncmp((big + i), little, lenght_little)) == 0)
		{
			return ((char *)(big + i));
		}
		i++;
	}
	return (NULL);
}
