/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcorasan <kcorasan@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 22:31:43 by kcorasan          #+#    #+#             */
/*   Updated: 2026/06/22 22:31:43 by kcorasan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*_list;
	t_list	*_node;
	void	*content;

	if (!lst || !f)
		return (NULL);
	_list = NULL;
	while (lst)
	{
		content = f(lst->content);
		_node = ft_lstnew(content);
		if (!_node)
		{
			if (del)
				del(content);
			ft_lstclear(&_list, del);
			return (NULL);
		}
		ft_lstadd_back(&_list, _node);
		lst = lst->next;
	}
	return (_list);
}
