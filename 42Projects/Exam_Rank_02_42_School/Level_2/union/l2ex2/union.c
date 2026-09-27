/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/22 17:17:23 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/08/22 18:02:49 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	f_union(char	*stra, char	*strb)
{
	int	i;
	int	j;
	int	k;
	char	ascii[128];

	i = 0;
	j = 0;
	k = 0;
	while(i < 128)
	{
		ascii[i] = (char)i;
		i++;
	}

	while (stra[j])
	{
		if (ascii[(int)(stra[j])] != '\0')
		{
			write(1,&ascii[(int)(stra[j])],1);
			ascii[(int)(stra[j])] = '\0';
		}
		j++;
	}
	while (strb[k])
	{
		if (ascii[(int)(strb[k])] != '\0')
		{
			write(1,&ascii[(int)(strb[k])],1);
			ascii[(int)(strb[k])] = '\0';
		}
		k++;
	}	
	return ;
}

int	main(int	argc, char	**argv)
{
	if (argc == 3)
		f_union(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}