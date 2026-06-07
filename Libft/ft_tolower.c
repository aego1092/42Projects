/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 13:54:51 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/06/07 14:09:57 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <ctype.h>
#include <stdio.h>
*/
//switch uppercase (A, ..., Z) to lowercase (a, ..., z)
int	ft_tolower(int p)
{
	if ((p >= 65 && p <= 90))
		return (p + 32);
	else
		return (p);
}
// Main for quick check
/*
int	main(void)
{
	char	test1 = 66;
	ft_tolower(test1);
    printf("ft_tolower: %d\n", ft_tolower(test1));
    printf("ft_tolower: %d\n", tolower(test1));
}
*/
