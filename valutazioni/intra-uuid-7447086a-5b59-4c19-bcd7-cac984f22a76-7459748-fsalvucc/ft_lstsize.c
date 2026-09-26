/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalvucc <fsalvucc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 15:31:05 by fsalvucc          #+#    #+#             */
/*   Updated: 2026/06/01 17:46:41 by fsalvucc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	nbr;

	nbr = 0;
	while (lst != NULL)
	{
		nbr++;
		lst = lst->next;
	}
	return (nbr);
}
