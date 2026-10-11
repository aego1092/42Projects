/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_fd_putfloat.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarino <cmarino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 14:14:12 by cmarino           #+#    #+#             */
/*   Updated: 2026/07/20 14:20:24 by cmarino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

unsigned long	ft_get_scale(int precision)
{
	unsigned long	scale;
	int				i;

	scale = 1;
	i = 0;
	while (i < precision)
	{
		scale *= 10;
		i++;
	}
	return (scale);
}

unsigned long	ft_round(double *frac, long *int_part, unsigned long scale)
{
	double	f;

	f = (*frac) * (double)scale + 0.5;
	if ((unsigned long)f >= scale)
	{
		(*int_part)++;
		f -= (double)scale;
	}
	return ((unsigned long)f);
}

int	ft_print_frac(unsigned long frac, unsigned long scale, int fd)
{
	int	count;

	count = 0;
	scale /= 10;
	while (scale > 0)
	{
		count += ft_putchar_fd('0' + ((frac / scale) % 10), fd);
		scale /= 10;
	}
	return (count);
}

int	ft_putfloat_fd(double nb, int precision, int fd)
{
	int				count;
	long			int_part;
	double			frac_part;
	unsigned long	scale;
	unsigned long	frac_rounded;

	count = 0;
	if (precision < 0)
		precision = 6;
	if (nb < 0)
	{
		count += ft_putchar_fd('-', fd);
		nb = -nb;
	}
	int_part = (long)nb;
	frac_part = nb - (double)int_part;
	scale = ft_get_scale(precision);
	frac_rounded = ft_round(&frac_part, &int_part, scale);
	count += ft_putnbr_base_fd(int_part, fd);
	if (precision > 0)
	{
		count += ft_putchar_fd('.', fd);
		count += ft_print_frac(frac_rounded, scale, fd);
	}
	return (count);
}
