/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 12:31:47 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/06/21 22:48:14 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
NAME
	 ft_lstnew — crea un nuovo nodo per una lista concatenata

LIBRARY
	 Libreria di Utilità Standard (libft)

SYNOPSIS
	 #include "libft.h"

	 t_list *ft_lstnew(void *content);

DESCRIPTION
	 La funzione ft_lstnew() alloca (tramite malloc) e restituisce un nuovo
	 nodo di tipo 't_list'. Il membro 'content' del nuovo nodo viene
	 inizializzato con il valore del parametro 'content', mentre il membro
	 'next' viene inizializzato a NULL.

RETURN VALUE
	 Il nuovo nodo allocato. NULL se l'allocazione di memoria fallisce.

LIMIT CASES
	 - Se 'content' è NULL, il nodo viene comunque creato con successo,
	   ma il suo membro 'content' punterà a NULL.
	 - Se la malloc() fallisce, la funzione restituisce protettivamente NULL.
*/

#include "libft.h"

t_list *ft_lstnew(void *content)
{
	t_list *node;

	node = malloc(sizeof(t_list) * (1));
	if (node == NULL)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

#include <stdio.h>

int main()
{
	int *data = malloc(sizeof(t_list));
	*data = 42;
	
	t_list *nodo = ft_lstnew(data);
	t_list *lst;

	lst = (t_list *)malloc(sizeof(t_list));
	
	// 2. Controllo di sicurezza: se la malloc fallisce, ritorna NULL
	if (!lst)
		return (1);

	//char *str = "ciao";
	char *str1 = "miao";
	lst->content = NULL;
	lst->next = NULL;
	// uint64_t valore = 0xAB12;
	printf("[%s] -> ", (char *)lst-> content);
	printf("[%p] -> ", (char *)lst-> next);
	lst->content = str1;
	printf("[%s] -> ", (char *)lst-> content);
	printf("[%p] -> ", (char *)lst-> next);
	
	printf("\n--- TEST COLLEGAMENTI MANUALE ---\n");
	return (0);
}

/*
// FUNZIONE DI SUPPORTO: Stampa la lista in modo grafico
void print_list(t_list *lst)
{
	printf("Stato della Lista: ");
	if (!lst)
	{
		printf("EMPTY (NULL)\n");
		return;
	}
	while (lst != NULL)
	{
		// Facciamo il cast a char* assumendo di aver inserito stringhe
		if (lst->content == NULL)
			printf("[NULL] -> ");
		else
			printf("[%s] -> ", (char *)lst->content);

		lst = lst->next; // Passiamo al nodo successivo
	}
	printf("NULL\n");
}

int main(void)
{
	printf("--- TEST FT_LSTNEW ---\n");

	// Test 1: Creazione nodo standard
	t_list *nodo1 = ft_lstnew("Primo Nodo");
	if (nodo1 == NULL)
	{
		printf("Errore: malloc fallita nel Test 1\n");
		return (1);
	}
	print_list(nodo1);

	// Test 2: Crash Test con content = NULL
	t_list *nodo2 = ft_lstnew(NULL);
	if (nodo2 == NULL)
	{
		printf("Errore: malloc fallita nel Test 2\n");
		free(nodo1); // Pulizia prima di uscire
		return (1);
	}
	printf("Dopo aver creato il nodo con content NULL:\n");
	print_list(nodo2);

	// Test 3: Integrità dei collegamenti (Manuale)
	printf("\n--- TEST COLLEGAMENTI MANUALE ---\n");
	nodo1->next = nodo2; // Colleghiamo il nodo 1 al nodo 2
	print_list(nodo1);   // Dovrebbe stampare: [Primo Nodo] -> [NULL] -> NULL

	// --- PULIZIA DELLA MEMORIA (Per evitare i leak su Valgrind) ---
	// Liberiamo nell'ordine corretto
	free(nodo1); // Libera il primo blocco di t_list
	free(nodo2); // Libera il secondo blocco di t_list

	printf("\nMemoria liberata correttamente. Controlla con Valgrind!\n");
	return (0);
}
*/