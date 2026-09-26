/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtyhach <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 15:50:46 by mtyhach           #+#    #+#             */
/*   Updated: 2026/07/01 15:50:49 by mtyhach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_pos(t_stack *a)
{
	t_node	*current;
	int		min_pos;
	int		min_val;
	int		pos;

	current = a->top;
	min_val = current->index;
	min_pos = 0;
	pos = 0;
	while (current)
	{
		if (current->index < min_val)
		{
			min_val = current->index;
			min_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (min_pos);
}

void	bring_to_top(t_stack *a, int pos, t_bench *bench)
{
	int	size;

	size = a->size;
	if (pos <= size / 2)
	{
		while (pos > 0)
		{
			ra(a, bench);
			pos--;
		}
	}
	else
	{
		while (pos < size)
		{
			rra(a, bench);
			pos++;
		}
	}
}

void	sort_simple(t_stack *a, t_stack *b, t_bench *bench)
{
	int	min_pos;

	while (a->size > 1)
	{
		min_pos = find_min_pos(a);
		bring_to_top(a, min_pos, bench);
		pb(a, b, bench);
	}
	pb(a, b, bench);
	while (b->size > 0)
		pa(a, b, bench);
}
