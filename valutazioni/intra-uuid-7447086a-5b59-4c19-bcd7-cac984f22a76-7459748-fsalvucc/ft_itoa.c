/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalvucc <fsalvucc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 17:13:20 by fsalvucc          #+#    #+#             */
/*   Updated: 2026/06/07 14:14:48 by fsalvucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	ft_msize(long n)
{
	size_t	nbr;

	if (n == 0)
		return (1);
	nbr = 0;
	while (n > 0)
	{
		nbr++;
		n = n / 10;
	}
	return (nbr);
}

static void	ft_fillstr(char *str, long n, int index, int sign)
{
	if (sign)
		str[0] = '-';
	else if (n == 0)
	{
		str[0] = '0';
		return ;
	}
	while (n > 0)
	{
		index--;
		str[index] = n % 10 + 48;
		n = n / 10;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	nbr;
	long	numb;
	int		sign;

	sign = 0;
	numb = n;
	if (numb < 0)
	{
		numb = -numb;
		sign = 1;
	}
	nbr = ft_msize(numb) + sign;
	str = (char *)ft_calloc((nbr + 1), sizeof(char));
	if (!str)
		return (NULL);
	ft_fillstr(str, numb, nbr, sign);
	return (str);
}
