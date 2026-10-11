/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 11:16:17 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/07/26 17:39:44 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(va_list *args)
{
	char	c;
	int		bytes_printed;

	c = (char)va_arg(*args, int);
	bytes_printed = write(1, &c, 1);
	return (bytes_printed);
}

int	ft_print_str(va_list *args)
{
	char	*str;
	int		len;

	str = va_arg(*args, char *);
	if (!str)
		return (write(1, "(null)", 6));
	len = 0;
	while (str[len])
	{
		if (write(1, &str[len], 1) < 0)
			return (-1);
		len++;
	}
	return (len);
}
