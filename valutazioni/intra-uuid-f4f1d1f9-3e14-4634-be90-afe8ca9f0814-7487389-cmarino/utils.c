/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 11:48:18 by cmarino           #+#    #+#             */
/*   Updated: 2026/07/01 14:11:52 by cmarino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi_check(const char *str, int *result)
{
	long	n;
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	n = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		n = n * 10 + (str[i] - '0');
		if (n * sign > INT_MAX || n * sign < INT_MIN)
			return (0);
		i++;
	}
	*result = (int)(n * sign);
	return (1);
}

int	has_duplicate(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	ps_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i] || s1[i] == '\0')
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int	get_start(int argc, char **argv, int *flag)
{
	int	i;

	i = 1;
	*flag = 0;
	while (i < argc)
	{
		if (is_flag(argv[i]))
		{
			*flag = get_flag(argv[i]);
			i++;
		}
		else if (ps_strncmp(argv[i], "--bench", 7) == 0 && argv[i][7] == '\0')
		{
			i++;
		}
		else
			break ;
	}
	return (i);
}
