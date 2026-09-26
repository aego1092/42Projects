/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtyhach <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 15:50:30 by mtyhach           #+#    #+#             */
/*   Updated: 2026/07/01 15:50:32 by mtyhach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_bits(int size)
{
	int	bits;
	int	max;

	bits = 0;
	max = size - 1;
	while ((1 << bits) <= max)
		bits++;
	return (bits);
}

void	sort_complex(t_stack *a, t_stack *b, t_bench *bench)
{
	int	bits;
	int	i;
	int	j;
	int	size;

	size = a->size;
	bits = get_bits(size);
	i = 0;
	while (i < bits)
	{
		j = 0;
		while (j < size)
		{
			if (((a->top->index >> i) & 1) == 0)
				pb(a, b, bench);
			else
				ra(a, bench);
			j++;
		}
		while (b->size > 0)
			pa(a, b, bench);
		i++;
	}
}
