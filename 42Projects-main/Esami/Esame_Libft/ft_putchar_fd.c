/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 18:37:24 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/06/21 10:06:53 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
NAME
     ft_putchar_fd — scrive un carattere su un file descriptor dato

LIBRARY
     Libreria di Utilità Standard (libft)

SYNOPSIS
     #include "libft.h"

     void ft_putchar_fd(char c, int fd);

DESCRIPTION
     La funzione ft_putchar_fd() invia il carattere 'c' al file descriptor
     specificato da 'fd'.

RETURN VALUE
     Nessuno.

LIMIT CASES
     - Se 'fd' non è valido o è chiuso, la scrittura fallisce silenziosamente
       (o imposta errno a seconda del sistema).
*/

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, sizeof(c));
}
/*
int main (void)
{
	ft_putchar_fd('k', 1);
}
	*/
