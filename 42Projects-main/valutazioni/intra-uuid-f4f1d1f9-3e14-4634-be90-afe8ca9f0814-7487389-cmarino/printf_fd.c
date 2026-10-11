/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 14:03:12 by cmarino           #+#    #+#             */
/*   Updated: 2026/07/20 14:03:15 by cmarino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* legge un eventuale ".N" dopo il '%' e fa avanzare *fmt.
 * ritorna la precisione trovata, oppure -1 se non presente. */
static int	ft_parse_precision(const char **fmt)
{
	int	precision;

	precision = -1;
	if (**fmt == '.')
	{
		(*fmt)++;
		precision = 0;
		while (**fmt >= '0' && **fmt <= '9')
		{
			precision = precision * 10 + (**fmt - '0');
			(*fmt)++;
		}
	}
	return (precision);
}

static int	ft_handle_format(const char **fmt, va_list args, int fd)
{
	int	precision;

	precision = ft_parse_precision(fmt);
	if (**fmt == 'd' || **fmt == 'i')
		return (ft_putnbr_base_fd((long)va_arg(args, int), fd));
	else if (**fmt == 'u')
		return (ft_putunbr_fd((unsigned long)va_arg(args, unsigned int), fd));
	else if (**fmt == 's')
		return (ft_putstr_fd(va_arg(args, char *), fd));
	else if (**fmt == 'c')
		return (ft_putchar_fd((char)va_arg(args, int), fd));
	else if (**fmt == 'f')
		return (ft_putfloat_fd(va_arg(args, double), precision, fd));
	else if (**fmt == '%')
		return (ft_putchar_fd('%', fd));
	else
		return (0);
}

int	ft_printf_fd(int fd, const char *format, ...)
{
	va_list		args;
	int			count;
	const char	*p;

	va_start(args, format);
	count = 0;
	p = format;
	while (*p)
	{
		if (*p == '%' && *(p + 1))
		{
			p++;
			count += ft_handle_format(&p, args, fd);
			p++;
		}
		else
		{
			count += ft_putchar_fd(*p, fd);
			p++;
		}
	}
	va_end(args);
	return (count);
}
