/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 15:30:32 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/06/21 15:39:06 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	if (lst == NULL)
		return (0);
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
/*
int	main(void)
{
	1. Creiamo 3 nodi separati con delle stringhe come contenuto
	t_list	*nodo1 = ft_lstnew("Primo");
	t_list	*nodo2 = ft_lstnew("Secondo");
	t_list	*nodo3 = ft_lstnew("Terzo");

	2. Colleghiamo i nodi per formare la lista: nodo1 -> nodo2 -> nodo3 -> NULL
	nodo1->next = nodo2;
	nodo2->next = nodo3;

	3. Testiamo la tua funzione ft_lstsize
	int size = ft_lstsize(nodo1);
	printf("Dimensione della lista (atteso 3): %d\n", size);

	Test aggiuntivo con lista vuota (NULL)
	int size_vuota = ft_lstsize(NULL);
	printf("Dimensione di una lista vuota (atteso 0): %d\n", size_vuota);

	4. Liberiamo la memoria allocata (buona abitudine!)
	free(nodo1);
	free(nodo2);
	free(nodo3);

	return (0);
}
*/
