/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 13:09:56 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/06/21 15:20:04 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
NAME
     ft_lstadd_front — aggiunge un elemento all'inizio di una lista

LIBRARY
     Libreria di Utilità Standard (libft)

SYNOPSIS
     #include "libft.h"

     void ft_lstadd_front(t_list **lst, t_list *new);

DESCRIPTION
     La funzione ft_lstadd_front() aggiunge il nodo 'new' all'inizio della
     lista 'lst'. Per farlo, collega il puntatore 'next' di 'new' al vecchio
     primo nodo della lista, e aggiorna il puntatore della testa 'lst' affinché
     punti a 'new'.

RETURN VALUE
     Nessuno.

LIMIT CASES
     - Se 'lst' è NULL (il puntatore alla lista non esiste), la funzione deve
       interrompersi immediatamente per evitare un Segmentation Fault.
     - Se '*lst' è NULL (la lista è inizialmente vuota), 'new' diventa il primo
       e unico elemento della lista.
     - Se 'new' è NULL, la funzione non compie alcuna azione.
*/

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}

/*
#include <stdio.h>

// Funzione di supporto solo per stampare la lista nel terminale
void    print_list(t_list *lst)
{
    printf("Stato della lista: ");
    if (lst == NULL)
    {
        printf("(vuota)\n");
        return ;
    }
    while (lst != NULL)
    {
        printf("[%s] -> ", (char *)lst->content);
        lst = lst->next;
    }
    printf("NULL\n");
}

int main(void)
{
    // 1. Inizializziamo la testa della lista a NULL (lista vuota)
    t_list *testa_della_lista = NULL;
    print_list(testa_della_lista);

    // 2. Creiamo il primo nodo usando la TUA ft_lstnew
    t_list *nodo1 = ft_lstnew("Marco");
    ft_lstadd_front(&testa_della_lista, nodo1);
    print_list(testa_della_lista);

    // 3. Creiamo e inseriamo il secondo nodo in testa
    t_list *nodo2 = ft_lstnew("Luigi");
    ft_lstadd_front(&testa_della_lista, nodo2);
    print_list(testa_della_lista);

    // 4. Creiamo e inseriamo il terzo nodo in testa
    t_list *nodo3 = ft_lstnew("Anna");
    ft_lstadd_front(&testa_della_lista, nodo3);
    print_list(testa_della_lista);

    return (0);
}
*/
