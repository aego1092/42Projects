/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 08:41:26 by cmarino           #+#    #+#             */
/*   Updated: 2026/07/15 10:39:34 by cmarino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(t_stack *s)
{
	int	tmp_value;
	int	tmp_index;

	if (!s || s->size < 2)
		return ;
	tmp_value = s->top->value;
	tmp_index = s->top->index;
	s->top->value = s->top->next->value;
	s->top->index = s->top->next->index;
	s->top->next->value = tmp_value;
	s->top->next->index = tmp_index;
}

void	sa(t_stack *a, t_bench *bench)
{
	ft_swap(a);
	write(1, "sa\n", 3);
	if (bench)
	{
		bench->sa++;
		bench->total_ops++;
	}
}

void	sb(t_stack *b, t_bench *bench)
{
	ft_swap(b);
	write(1, "sb\n", 3);
	if (bench)
	{
		bench->sb++;
		bench->total_ops++;
	}
}

void	ss(t_stack *a, t_stack *b, t_bench *bench)
{
	ft_swap(a);
	ft_swap(b);
	write(1, "ss\n", 3);
	if (bench)
	{
		bench->ss++;
		bench->total_ops++;
	}
}
