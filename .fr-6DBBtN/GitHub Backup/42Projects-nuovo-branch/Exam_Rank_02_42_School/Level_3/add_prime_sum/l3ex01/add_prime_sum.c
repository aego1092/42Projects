/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 15:05:57 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/08/13 15:48:02 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void putnbr(int	n)
{
	char	c;
	if (n / 10 > 0)
		putnbr(n / 10);
	c = ((n % 10) + '0');
	write(1, &c, 1);
	return ;
}

int ft_atoi(char *str) {
  int i;
  int nbr;

  i = 0;
  nbr = 0;
  while (str[i]) {
    if (str[i] < '0' || str[i] > '9')
      return (-1);
    nbr = nbr * 10 + (str[i] - '0');
    i++;
  }
  return (nbr);
}

int	add_prime_sum(int	n)
{
	int	i;
	int sum;

	i = 1;
	sum = 0;
	while(i <= n)
	{
		if (n % i == 0)
			sum += i;	
		i++;
	}
	return(sum);
}

int	main (int argc, char** argv)
{
	
	if (argc == 2)
		if (add_prime_sum(ft_atoi(argv[1])) == 1)
			return (1);
		else
			putnbr(add_prime_sum(ft_atoi(argv[1])));
	else
	{
		write(1, "0\n", 2);
	}
	return (0);
}