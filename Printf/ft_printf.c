/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 11:15:51 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/07/25 19:32:31 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *stampa, ...)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < ft_strlen(stampa))
	{
		if (stampa[i] != '%')
		{
			j++;
			if (++j == strlen(stampa))
				write(1, stampa, j);
		}
		else
		{
			ft_print(stampa, j);
			j = 0;
			ft_print_conversion();
		}
		i++;
	}
	return ();	
}

//xxx
int main()
{
	const char a[] = "ciao";

	ft_printf(a, 4);
	//printf(a);
	return (0);
}