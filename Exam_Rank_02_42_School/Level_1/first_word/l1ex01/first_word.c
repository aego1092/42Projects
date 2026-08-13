/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 09:25:42 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/08/13 10:51:33 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	first_word(int argc, char **argv)
{
	int	i;

	i = 0;
	// if (argv[1][i] == '\0')
	// {
	// 	write(1, "\n", 1);
	// 	return ;
	// }
	while(argv[1][i] == ' ' || argv[1][i] == '\t')
		i++;
	while(argv[1][i] != ' ' && argv[1][i] != '\t' && argv[1][i] != '\0')
	{
		write(1, &argv[1][i], 1);
		i++;		
	}
	write(1, "\n", 1);
	return ;
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		first_word(argc, argv);
	write(1, "\n", 1);
	return(0);
}