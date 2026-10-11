/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtyhach <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 15:50:12 by mtyhach           #+#    #+#             */
/*   Updated: 2026/07/01 15:50:13 by mtyhach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

static int	find_rank(int *sorted, int size, int value)
{
	int	i;

	i = -1;
	while (++i < size)
		if (sorted[i] == value)
			return (i);
	return (-1);
}

static void	fill_arrays(t_stack *a, int *sorted, int *values)
{
	t_node	*current;
	int		i;

	current = a->top;
	i = -1;
	while (++i < a->size)
	{
		sorted[i] = current->value;
		values[i] = current->value;
		current = current->next;
	}
}

static void	assign_ranks(t_stack *a, int *sorted, int *values)
{
	t_node	*current;
	int		i;

	current = a->top;
	i = -1;
	while (++i < a->size)
	{
		current->index = find_rank(sorted, a->size, values[i]);
		current = current->next;
	}
}

void	normalize(t_stack *a)
{
	int	*sorted;
	int	*values;

	sorted = malloc(sizeof(int) * a->size);
	values = malloc(sizeof(int) * a->size);
	if (!sorted || !values)
		return ;
	fill_arrays(a, sorted, values);
	sort_array(sorted, a->size);
	assign_ranks(a, sorted, values);
	free(sorted);
	free(values);
}
