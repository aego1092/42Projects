/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 11:15:51 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/08/01 13:19:14 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_no_conversion(const char *stampa)
{
	int	len;

	len = (int)ft_strlen(stampa);
	if (write(1, stampa, len) == -1)
		return (-1);
	return (len);
}

int	ft_print_char_normal(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

static int	ft_print_with_conversions(const char *stampa, va_list *args)
{
	size_t	i;
	int		total_len;
	int		printed;

	i = 0;
	total_len = 0;
	while (stampa[i] != '\0')
	{
		if (stampa[i] == '%')
		{
			i++;
			if (stampa[i] == '\0')
				break ;
			printed = ft_print_dispatcher(stampa, &i, args);
		}
		else
			printed = ft_print_char_normal(stampa[i]);
		if (printed == -1)
			return (-1);
		total_len += printed;
		i++;
	}
	return (total_len);
}

int	ft_printf(const char *stampa, ...)
{
	va_list	args;
	int		total_printed;

	if (!stampa)
		return (-1);
	if (!ft_strchr(stampa, '%'))
		return (ft_print_no_conversion(stampa));
	va_start(args, stampa);
	total_printed = ft_print_with_conversions(stampa, &args);
	va_end(args);
	return (total_printed);
}
