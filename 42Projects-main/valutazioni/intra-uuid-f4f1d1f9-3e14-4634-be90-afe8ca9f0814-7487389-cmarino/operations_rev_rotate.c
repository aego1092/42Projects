/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rev_rotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 11:43:54 by cmarino           #+#    #+#             */
/*   Updated: 2026/07/15 11:52:36 by cmarino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	ft_rev_rotate(t_stack *s)
{
	t_node	*tmp;
	t_node	*prev;
	t_node	*current;

	if (!s || s->size < 2)
		return ;
	prev = NULL;
	current = s->top;
	while (current->next)
	{
		prev = current;
		current = current->next;
	}
	tmp = current;
	prev->next = NULL;
	tmp->next = s->top;
	s->top = tmp;
}

void	rra(t_stack *a, t_bench *bench)
{
	ft_rev_rotate(a);
	write(1, "rra\n", 4);
	if (bench)
	{
		bench->rra++;
		bench->total_ops++;
	}
}

void	rrb(t_stack *b, t_bench *bench)
{
	ft_rev_rotate(b);
	write(1, "rrb\n", 4);
	if (bench)
	{
		bench->rrb++;
		bench->total_ops++;
	}
}

void	rrr(t_stack *a, t_stack *b, t_bench *bench)
{
	ft_rev_rotate(a);
	ft_rev_rotate(b);
	write(1, "rrr\n", 4);
	if (bench)
	{
		bench->rrr++;
		bench->total_ops++;
	}
}
