/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake_to_camel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 16:39:55 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/08/22 17:13:01 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	snake_to_camel(char	*str)
{
	int i;

	i = 0;
	while (str[i])
	{
		// if (i == 0)
		// {
		// 	write(1, &str[i], 1);
		// 	i++;
		// }
		if (str[i] == '_')
		{
			i++;
			if (str[i] >= 'a' && str[i] <= 'z')
			{
				str[i] = str[i] - 32;
				// write(1, &str[i], 1);
			}
			// else
			// write(1, &str[i], 1);
		}
		// else 
		write(1, &str[i], 1);
		i++;
	}
	return ;
}

int	main(int	argc, char	**argv)
{
	if (argc == 2 && argv[1][0])
		snake_to_camel(argv[1]);
	write(1, "\n", 1);
		return (0);
}