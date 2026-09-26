/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 19:16:28 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/06/21 10:07:32 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
NAME
     ft_putstr_fd — scrive una stringa su un file descriptor dato

LIBRARY
     Libreria di Utilità Standard (libft)

SYNOPSIS
     #include "libft.h"

     void ft_putstr_fd(char *s, int fd);

DESCRIPTION
     La funzione ft_putstr_fd() invia la stringa 's' al file descriptor
     specificato da 'fd'.

RETURN VALUE
     Nessuno.

LIMIT CASES
     - Se 's' è NULL, il comportamento è indefinito (può causare un
       Segmentation Fault a seconda dell'implementazione di ft_strlen).
     - Se 'fd' non è valido, la scrittura non ha luogo.
*/
#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}
/*
void main()
{
	ft_putstr_fd("ciao", 1);
}
*/
