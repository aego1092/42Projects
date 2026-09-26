/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtyhach <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 08:35:12 by mtyhach           #+#    #+#             */
/*   Updated: 2026/07/15 08:35:16 by mtyhach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bench	*bench_init(void)
{
	t_bench	*bench;

	bench = malloc(sizeof(t_bench));
	if (!bench)
		return (NULL);
	bench->total_ops = 0;
	bench->sa = 0;
	bench->sb = 0;
	bench->ss = 0;
	bench->pa = 0;
	bench->pb = 0;
	bench->ra = 0;
	bench->rb = 0;
	bench->rr = 0;
	bench->rra = 0;
	bench->rrb = 0;
	bench->rrr = 0;
	bench->disorder = 0.0;
	bench->strategy = NULL;
	return (bench);
}

void	bench_print(t_bench *bench)
{
	ft_printf_fd(2, "[bench] disorder: %d%%\n",
		(int)(bench->disorder * 100));
	ft_printf_fd(2, "[bench] strategy: %s\n", bench->strategy);
	ft_printf_fd(2, "[bench] total_ops: %d\n", bench->total_ops);
	ft_printf_fd(2, "[bench] sa: %d  sb: %d  ss: %d  pa: %d  pb: %d\n",
		bench->sa, bench->sb, bench->ss, bench->pa, bench->pb);
	ft_printf_fd(2,
		"[bench] ra: %d  rb: %d  rr: %d  "
		"rra: %d  rrb: %d  rrr: %d\n",
		bench->ra, bench->rb, bench->rr,
		bench->rra, bench->rrb, bench->rrr);
}
