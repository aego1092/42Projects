/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 15:01:46 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/06/02 17:33:32 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//check if a variable belong to ASCII
int	ft_isascii(int p)
{
	if (p >= 0 && p <= 127)
		return (1);
	else
		return (0);
}
// Main for quick check
/*
int	main(void)
{
	char	test1 = 'B';
	ft_isalpha(test1);
}
*/
/*
#include <stdio.h>
*/
/*
int	main(void)
{
	int	i;
	int	res;

	i = -10;
	printf("--- TEST FT_ISASCII (STILE 42) ---\n");
	while (i <= 140)
	{
		res = ft_isascii(i);
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
*/
