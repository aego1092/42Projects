/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giupalum <giupalum@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 17:35:56 by giupalum          #+#    #+#             */
/*   Updated: 2026/06/15 17:35:57 by giupalum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next_temp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		next_temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = next_temp;
	}
	*lst = NULL;
}
