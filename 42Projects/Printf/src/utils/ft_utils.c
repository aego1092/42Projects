/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 11:17:03 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/07/26 16:44:43 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned long nbr, const char *base)
{
	unsigned long	base_len;
	int				count;
	int				ret;

	base_len = ft_strlen(base);
	count = 0;
	if (nbr >= base_len)
	{
		ret = ft_putnbr_base(nbr / base_len, base);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	if (write(1, &base[nbr % base_len], 1) == -1)
		return (-1);
	return (count + 1);
}
