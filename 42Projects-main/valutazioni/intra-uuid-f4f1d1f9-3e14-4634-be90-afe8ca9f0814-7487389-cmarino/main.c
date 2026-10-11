/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 12:28:25 by cmarino           #+#    #+#             */
/*   Updated: 2026/07/19 12:28:29 by cmarino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_bench(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ps_strncmp(argv[i], "--bench", 7) == 0 && argv[i][7] == '\0')
			return (1);
		i++;
	}
	return (0);
}

static void	run_sort(t_stack *a, t_stack *b, t_bench *bench, int flag)
{
	if (flag == 1)
	{
		bench->strategy = "Simple / O(n^2)";
		sort_simple(a, b, bench);
	}
	if (flag == 2)
	{
		bench->strategy = "Medium / O(n*sqrt(n))";
		sort_medium(a, b, bench);
	}
	if (flag == 3)
	{
		bench->strategy = "Complex / O(n log n)";
		sort_complex(a, b, bench);
	}
	if (flag == 4 || flag == 0)
		sort_adaptive(a, b, bench);
}

static int	init_all(t_stack *a, t_stack **b, t_bench **bench)
{
	*b = stack_init();
	if (!*b)
	{
		stack_free(a);
		error_exit();
	}
	*bench = bench_init();
	if (!*bench)
	{
		stack_free(a);
		stack_free(*b);
		error_exit();
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_bench	*bench;
	int		flag;
	int		bench_mode;

	if (argc < 2)
		return (0);
	bench_mode = is_bench(argc, argv);
	a = parse_args(argc, argv, &flag);
	if (!a)
		error_exit();
	init_all(a, &b, &bench);
	if (!is_sorted(a))
	{
		bench->disorder = compute_disorder(a);
		normalize(a);
		run_sort(a, b, bench, flag);
	}
	if (bench_mode)
		bench_print(bench);
	stack_free(a);
	stack_free(b);
	free(bench);
	return (0);
}
