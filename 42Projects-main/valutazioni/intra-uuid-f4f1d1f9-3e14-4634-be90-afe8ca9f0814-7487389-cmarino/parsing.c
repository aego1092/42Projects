/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 07:53:52 by cmarino           #+#    #+#             */
/*   Updated: 2026/07/17 10:49:39 by cmarino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	fill_from_str(const char *str, int *numbers, int *idx)
{
	int		pos;
	char	buf[32];

	pos = 0;
	while (str[pos])
	{
		if (!extract_token(str, &pos, buf))
			break ;
		if (ft_atoi_check(buf, &numbers[*idx]) == 0)
			return (0);
		(*idx)++;
	}
	return (1);
}

static int	*fill_numbers( char **argv, int start, int argc, int size)
{
	int	*numbers;
	int	i;
	int	idx;

	numbers = malloc(sizeof(int) * size);
	if (!numbers)
		return (NULL);
	i = start;
	idx = 0;
	while (i < argc)
	{
		if (!fill_from_str(argv[i], numbers, &idx))
		{
			free(numbers);
			return (NULL);
		}
		i++;
	}
	return (numbers);
}

static t_stack	*build_stack(int *numbers, int size)
{
	t_stack	*a;
	int		i;

	a = stack_init();
	if (!a)
		return (NULL);
	i = size - 1;
	while (i >= 0)
	{
		stack_push(a, numbers[i]);
		i--;
	}
	return (a);
}

t_stack	*parse_args(int argc, char **argv, int *flag)
{
	int		*numbers;
	t_stack	*a;
	int		start;
	int		size;

	start = get_start(argc, argv, flag);
	size = count_total_numbers(argv, start, argc);
	if (size <= 0)
		return (NULL);
	numbers = fill_numbers(argv, start, argc, size);
	if (!numbers)
		error_exit();
	if (has_duplicate(numbers, size))
	{
		free(numbers);
		error_exit();
	}
	a = build_stack(numbers, size);
	free(numbers);
	if (!a)
		error_exit();
	return (a);
}
