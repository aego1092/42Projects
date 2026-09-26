/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 11:36:05 by cmarino           #+#    #+#             */
/*   Updated: 2026/07/15 11:43:37 by cmarino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rotate(t_stack *s)
{
	t_node	*tmp;
	t_node	*last;

	if (!s || s->size < 2)
		return ;
	tmp = s->top;
	s->top = s->top->next;
	last = s->top;
	while (last->next)
		last = last->next;
	last->next = tmp;
	tmp->next = NULL;
}

void	ra(t_stack *a, t_bench *bench)
{
	ft_rotate(a);
	write(1, "ra\n", 3);
	if (bench)
	{
		bench->ra++;
		bench->total_ops++;
	}
}

void	rb(t_stack *b, t_bench *bench)
{
	ft_rotate(b);
	write(1, "rb\n", 3);
	if (bench)
	{
		bench->rb++;
		bench->total_ops++;
	}
}

void	rr(t_stack *a, t_stack *b, t_bench *bench)
{
	if (!a || !b || a->size < 2 || b->size < 2)
		return ;
	ft_rotate(a);
	ft_rotate(b);
	write(1, "rr\n", 3);
	if (bench)
	{
		bench->rr++;
		bench->total_ops++;
	}
}
