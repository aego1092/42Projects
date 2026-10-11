/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel_to_snake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 12:50:14 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/08/13 15:03:48 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	camel_to_snake(int argc, char **argv)
{
	int	i;

	if (argc != 2)
		return ;
	i = 0;
	while (argv[1][i])
	{
		if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
		{
			write(1, "_", 1);
			argv[1][i] += 32;
		}
		write(1, &argv[1][i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	camel_to_snake(argc, argv);
	write(1, "\n", 1);
	return (0);
}


