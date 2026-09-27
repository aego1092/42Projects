/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 19:26:43 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/06/21 10:07:43 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
NAME
     ft_putendl_fd — scrive una stringa seguita da un newline su un fd dato

LIBRARY
     Libreria di Utilità Standard (libft)

SYNOPSIS
     #include "libft.h"

     void ft_putendl_fd(char *s, int fd);

DESCRIPTION
     La funzione ft_putendl_fd() invia la stringa 's' al file descriptor
     specificato da 'fd', seguita da un carattere di nuova linea ('\n').

RETURN VALUE
     Nessuno.

LIMIT CASES
     - Se 's' è NULL, la funzione potrebbe andare in crash prima di scrivere
       il newline.
*/
#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (s)
	{
		ft_putstr_fd(s, fd);
		write(fd, "\n", 1);
	}
}
/*
void main()
{
	ft_putendl_fd("ciao", 1);
}
*/
