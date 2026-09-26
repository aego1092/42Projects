/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tiny.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtyhach <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 15:12:01 by mtyhach           #+#    #+#             */
/*   Updated: 2026/07/25 15:12:04 by mtyhach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_stack *a, t_bench *bench)
{
	int	top;
	int	mid;
	int	bot;

	top = a->top->index;
	mid = a->top->next->index;
	bot = a->top->next->next->index;
	if (top < mid && mid < bot)
		return ;
	if (top < bot && bot < mid)
	{
		sa(a, bench);
		ra(a, bench);
	}
	else if (mid < top && top < bot)
		sa(a, bench);
	else if (mid < bot && bot < top)
		rra(a, bench);
	else if (bot < top && top < mid)
		ra(a, bench);
	else if (bot < mid && mid < top)
	{
		sa(a, bench);
		rra(a, bench);
	}
}

static void	sort_four(t_stack *a, t_stack *b, t_bench *bench)
{
	int	pos;

	pos = find_min_pos(a);
	bring_to_top(a, pos, bench);
	pb(a, b, bench);
	sort_three(a, bench);
	pa(a, b, bench);
}

static void	sort_five(t_stack *a, t_stack *b, t_bench *bench)
{
	int	pos;

	pos = find_min_pos(a);
	bring_to_top(a, pos, bench);
	pb(a, b, bench);
	pos = find_min_pos(a);
	bring_to_top(a, pos, bench);
	pb(a, b, bench);
	sort_three(a, bench);
	pa(a, b, bench);
	pa(a, b, bench);
}

void	sort_tiny(t_stack *a, t_stack *b, t_bench *bench)
{
	if (a->size == 2)
	{
		if (a->top->index > a->top->next->index)
			sa(a, bench);
	}
	else if (a->size == 3)
		sort_three(a, bench);
	else if (a->size == 4)
		sort_four(a, b, bench);
	else if (a->size == 5)
		sort_five(a, b, bench);
}
