/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dispatcher.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 11:16:49 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/08/01 13:33:51 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_dispatcher(const char *stampa, size_t *i, va_list *args)
{
	int							printed;
	int							printed_char;
	static const t_ptr_funct	conversion_list[256] = {
	['c'] = ft_print_char,
	['s'] = ft_print_str,
	['d'] = ft_print_nbr,
	['i'] = ft_print_nbr,
	['u'] = ft_print_unsigned,
	['x'] = ft_print_hex_low,
	['X'] = ft_print_hex_up,
	['p'] = ft_print_ptr,
	['%'] = ft_print_percent
	};

	if (conversion_list[(unsigned char)stampa[(*i)]] != NULL)
		return (conversion_list[(unsigned char)stampa[(*i)]](args));
	printed = ft_print_char_normal('%');
	if (printed == -1)
		return (-1);
	printed_char = ft_print_char_normal(stampa[*i]);
	if (printed_char == -1)
		return (-1);
	return (printed + printed_char);
}
