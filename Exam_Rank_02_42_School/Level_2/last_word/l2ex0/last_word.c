/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 14:42:22 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/08/22 15:23:02 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	last_word(char	*str)
{
	int	i;
	int j;
	i = 0;
	while (str[i])
		i++;
	i--;
	
	
	while (str [i] != ' ' || str [i] != '\t')
	{
		i--;
	}
	j = i;
	while (str [i] != ' ' && str [i] != '\t' && i >= 0)
	{
		i--;
	}
	i++;
	while (i <= j)
	{
		write(1, &str[i], 1);
		i++;
	}
	return ;
}


int	main(int	argc, char	**argv)
{
	if (argc == 2  && argv[1][0])
		last_word(argv[1]);
	write(1,"\n",1);
	return (0);
}
