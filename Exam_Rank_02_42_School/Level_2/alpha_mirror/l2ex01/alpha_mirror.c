/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 11:57:30 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/08/13 12:42:49 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	alpha_mirror(int argc, char **argv)
{
	if (argc == 2)
	{
		int 	i;
		char	c;
		
		i = 0;
		while (argv[1][i])
		{
			if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
			{
				c = 'a' + (25 - (argv[1][i] - 'a'));
				write(1, &c,1);
			}
			else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
			{
				c = 'A' + (25 - (argv[1][i] - 'A'));
				write(1, &c,1);	
			}
			else
			write(1, &(argv[1][i]),1);
			i++;
		}
	}
	write(1, "\n", 1);		
	return ;
}

int	main(int argc, char **argv)
{
	alpha_mirror(argc, argv);
	return (0);
}