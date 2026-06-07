/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 12:44:08 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/06/07 14:11:13 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <ctype.h>
#include <stdio.h>
*/
//switch lowercase (a, ..., z) to uppercase (A, ..., Z)
int	ft_toupper(int p)
{
	if (p >= 97 && p <= 122)
		return (p - 32);
	else
		return (p);
}
// Main for quick check
/*
int	main(void)
{
	char	test1 = 98;
	ft_toupper(test1);
    printf("ft_toupper: %d\n", ft_toupper(test1));
    printf("ft_toupper: %d\n", toupper(test1));
}
*/