/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtyhach <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 08:22:09 by mtyhach           #+#    #+#             */
/*   Updated: 2026/07/15 08:22:11 by mtyhach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <math.h>

static int	find_max_pos(t_stack *b)
{
	t_node	*current;
	int		max_pos;
	int		max_val;
	int		pos;

	current = b->top;
	max_val = current->index;
	max_pos = 0;
	pos = 0;
	while (current)
	{
		if (current->index > max_val)
		{
			max_val = current->index;
			max_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (max_pos);
}

static void	bring_max_to_top(t_stack *b, int pos, t_bench *bench)
{
	int	size;

	size = b->size;
	if (pos <= size / 2)
	{
		while (pos > 0)
		{
			rb(b, bench);
			pos--;
		}
	}
	else
	{
		while (pos < size)
		{
			rrb(b, bench);
			pos++;
		}
	}
}

static void	push_one_chunk(t_stack *a, t_stack *b, t_bench *bench, int chunk[2])
{
	int	pushed;
	int	i;

	pushed = 0;
	i = 0;
	while (pushed < chunk[1] && i < a->size)
	{
		if (a->top->index >= chunk[0] && a->top->index < chunk[0] + chunk[1])
		{
			pb(a, b, bench);
			pushed++;
		}
		else
		{
			ra(a, bench);
			i++;
		}
	}
}

static void	push_chunks_to_b(t_stack *a, t_stack *b, t_bench *bench)
{
	int	chunk[2];
	int	num_chunks;
	int	size;

	size = a->size;
	chunk[1] = (int)sqrt(size);
	num_chunks = (size / chunk[1]) + 1;
	chunk[0] = 0;
	while (chunk[0] < num_chunks * chunk[1])
	{
		push_one_chunk(a, b, bench, chunk);
		chunk[0] += chunk[1];
	}
}

void	sort_medium(t_stack *a, t_stack *b, t_bench *bench)
{
	int	max_pos;

	push_chunks_to_b(a, b, bench);
	while (b->size > 0)
	{
		max_pos = find_max_pos(b);
		bring_max_to_top(b, max_pos, bench);
		pa(a, b, bench);
	}
}
