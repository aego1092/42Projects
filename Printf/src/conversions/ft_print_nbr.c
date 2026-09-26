/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 11:16:49 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/07/26 16:37:13 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nbr(va_list *args)
{
	int		n;
	int		count;
	long	nbr;

	n = va_arg(*args, int);
	nbr = n;
	count = 0;
	if (nbr < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		count++;
		nbr = -nbr;
	}
	return (count + ft_putnbr_base((unsigned long)nbr, "0123456789"));
}
