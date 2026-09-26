/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarino <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 12:28:42 by cmarino           #+#    #+#             */
/*   Updated: 2026/07/16 13:13:11 by cmarino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_init(void)
{
	t_stack	*s;

	s = malloc(sizeof(*s));
	if (!s)
		return (NULL);
	s->top = NULL;
	s->size = 0;
	return (s);
}

void	stack_push(t_stack *s, int value)
{
	t_node	*new;

	new = malloc(sizeof(*new));
	if (!new)
		error_exit();
	new->value = value;
	new->index = 0;
	new->next = s->top;
	s->top = new;
	s->size++;
}

int	stack_pop(t_stack *s)
{
	t_node	*tmp;
	int		value;

	if (!s || s->size == 0)
		return (0);
	tmp = s->top;
	value = tmp->value;
	s->top = s->top->next;
	free(tmp);
	s->size--;
	return (value);
}

int	is_sorted(t_stack *a)
{
	t_node	*current;

	if (!a || a->size <= 1)
		return (1);
	current = a->top;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

void	stack_free(t_stack *s)
{
	t_node	*tmp;
	t_node	*current;

	if (!s)
		return ;
	current = s->top;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	free(s);
}
