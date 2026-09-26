/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 10:58:24 by cmarino           #+#    #+#             */
/*   Updated: 2026/07/15 11:10:26 by cmarino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_push(t_stack *src, t_stack *dst)
{
	t_node	*tmp;

	if (!src || src->size == 0)
		return ;
	tmp = src->top;
	src->top = src->top->next;
	tmp->next = dst->top;
	dst->top = tmp;
	src->size--;
	dst->size++;
}

void	pb(t_stack *a, t_stack *b, t_bench *bench)
{
	ft_push(a, b);
	write(1, "pb\n", 3);
	if (bench)
	{
		bench->pb++;
		bench->total_ops++;
	}
}

void	pa(t_stack *a, t_stack *b, t_bench *bench)
{
	ft_push(b, a);
	write(1, "pa\n", 3);
	if (bench)
	{
		bench->pa++;
		bench->total_ops++;
	}
}
