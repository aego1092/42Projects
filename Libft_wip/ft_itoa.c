/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 10:14:41 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/06/22 10:44:01 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	integer_len(int n);
static void	ft_putnbr_in_itoa(char *str, int n, int len);

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = integer_len(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	ft_putnbr_in_itoa(str, n, len);
	return (str);
}

static int	integer_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
	{
		len = 1;
		if (n == 0)
			return (len);
		n = -n;
	}
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static void	ft_putnbr_in_itoa(char *str, int n, int len)
{
	if (n == 0)
	{
		str[0] = '0';
		return ;
	}
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (n != 0)
	{
		len--;
		str[len] = (n % 10) + '0';
		n /= 10;
	}
}
