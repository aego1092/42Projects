/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 15:52:22 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/06/01 08:52:46 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**/
#include <stdio.h>
/**/
int	ft_isprint(int p)
{
	if (p >= 32 && p <= 126)
		return (1);
	else
		return (0);
}

/**/
int	main(void)
{
	int	i;
	int	res;

	i = -10;
	while (i <= 140)
	{
		res = ft_isprint(i);
		if (res == 1)
		{
			if (i >= 32 && i <= 126)
				printf("Valore %d ('%c'): ASCII (1)\n", i, i);
			else
				printf("Valore %d (Non stampabile): ASCII (1)\n", i);
		}
		else
		{
			printf("Valore %d: NON ASCII (0)\n", i);
		}
		i++;
	}
	return (0);
}
/**/
