/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 10:55:04 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/08/13 11:24:30 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	num_to_char(int	n)
{
	char c;
	
	if ((n / 10) > 0)
		num_to_char(n / 10);
	c = (n%10) + 48;
		write (1, &c, 1);
	return ;
}

void	fizzbuzz(int	n)
{
	if ((n % 15) == 0)
		write(1,"fizzbuzz\n", 9);
	else if ((n % 5) == 0)
		write(1,"buzz\n", 5);
	else if ((n % 3) == 0)
		write(1,"fizz\n", 5);
	else
	{
		num_to_char(n);
		write (1, "\n", 1);
	}
		return ;
}

int main()
{
	int a;
	
	a = 1;
	while (a <= 100)
	{
		fizzbuzz(a);
		a++;
	}
	return (0);
}