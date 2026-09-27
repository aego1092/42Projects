/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 19:41:53 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/06/21 10:07:53 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
NAME
     ft_putnbr_fd — scrive un intero su un file descriptor dato

LIBRARY
     Libreria di Utilità Standard (libft)

SYNOPSIS
     #include "libft.h"

     void ft_putnbr_fd(int n, int fd);

DESCRIPTION
     La funzione ft_putnbr_fd() converte l'intero 'n' in una stringa di caratteri
     e la invia al file descriptor specificato da 'fd'. Gestisce correttamente
     i numeri negativi.

RETURN VALUE
     Nessuno.

LIMIT CASES
     - Se 'n' è uguale a INT_MIN (-2147483648), deve essere gestito come caso
       speciale per evitare l'overflow da inversione di segno.
*/
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -1 * n;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	c = n % 10 + '0';
	write(fd, &c, 1);
}
/*
int	main()
{
	ft_putnbr_fd(12345, 1);
}
*/
