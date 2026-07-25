/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 17:16:09 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/06/21 17:31:26 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*this_node;
	t_list	*next_node;

	if (lst == NULL || del == NULL)
		return ;
	this_node = *lst;
	while (this_node)
	{
		next_node = this_node->next;
		del(this_node->content);
		free(this_node);
		this_node = next_node;
	}
	*lst = NULL;
}
