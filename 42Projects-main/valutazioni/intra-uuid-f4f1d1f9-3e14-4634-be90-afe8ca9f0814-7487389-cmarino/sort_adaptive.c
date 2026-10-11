/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtyhach <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 08:21:42 by mtyhach           #+#    #+#             */
/*   Updated: 2026/07/15 08:21:48 by mtyhach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_strategy(t_bench *bench, double disorder)
{
	if (!bench)
		return ;
	if (disorder < 0.2)
		bench->strategy = "Adaptive / O(n^2)";
	else if (disorder < 0.5)
		bench->strategy = "Adaptive / O(n*sqrt(n))";
	else
		bench->strategy = "Adaptive / O(n log n)";
}

static void	run_strategy(t_stack *a, t_stack *b, t_bench *bench,
		double disorder)
{
	if (disorder < 0.2)
		sort_simple(a, b, bench);
	else if (disorder < 0.5)
		sort_medium(a, b, bench);
	else
		sort_complex(a, b, bench);
}

void	sort_adaptive(t_stack *a, t_stack *b, t_bench *bench)
{
	double	disorder;

	disorder = bench->disorder;
	if (a->size <= 1 || is_sorted(a))
		return ;
	if (a->size <= 5)
	{
		sort_tiny(a, b, bench);
		return ;
	}
	set_strategy(bench, disorder);
	run_strategy(a, b, bench, disorder);
}
