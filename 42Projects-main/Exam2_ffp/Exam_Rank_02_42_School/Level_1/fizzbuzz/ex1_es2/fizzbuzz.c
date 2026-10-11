/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 16:33:25 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/08/12 16:55:15 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	fizzbuzz(int n)
{
	if ((n % 15) == 0)
	{
		write(1, "fizzbuzz", 8);
	}
	else if ((n % 3) == 0)
	{
		write(1, "fizz", 4);
	}
	else if ((n % 5) == 0)
	{
		write(1, "buzz", 4);
	}
	else
	{
		// Gestione dei numeri da 1 a 99
		if (n >= 10)
		{
			ft_putchar((n / 10) + '0'); // Stampa la cifra delle decine
		}
		ft_putchar((n % 10) + '0');     // Stampa la cifra delle unità
	}
	ft_putchar('\n');
}

int	main(void)
{
	int	i;

	i = 1;
	while (i <= 100)
	{
		fizzbuzz(i);
		i++;
	}
	return (0);
}