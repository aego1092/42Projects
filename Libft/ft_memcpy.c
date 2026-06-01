/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 11:39:56 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/06/01 17:23:51 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
#include <string.h>
*/

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr_dest;
	const unsigned char	*ptr_src;
	size_t				i;

	// if ((dest == NULL) && (src == NULL))
	// 	return (NULL);
	ptr_dest = (unsigned char *)dest;
	ptr_src = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		*(ptr_dest + i) = *(ptr_src + i);
		i++;
	}
	return (dest);
}

/*
int main(void)
{
    printf("--- INIZIO TEST FT_MEMCPY ---\n\n");

    // -------------------------------------------------------------------------
    // TEST 1: Copia di una stringa di testo
    // -------------------------------------------------------------------------
    char src_str[] = "Nel mezzo del cammin di nostra vita...";
    char dest_ft[50] = {0}; // Buffer per la tua funzione (inizializzato a zero)
    char dest_or[50] = {0}; // Buffer per la memcpy originale

    // Eseguiamo la copia (copiamo 20 byte)
    ft_memcpy(dest_ft, src_str, 20);
    memcpy(dest_or, src_str, 20);

    printf("[TEST 1 - Stringa]\n");
    printf("Sorgente:  %s\n", src_str);
    printf("ft_memcpy: %s\n", dest_ft);
    printf("memcpy:    %s\n", dest_or);
    
    // Verifica se i risultati coincidono
    if (strcmp(dest_ft, dest_or) == 0)
        printf("-> RISULTATO: OK ✅\n\n");
    else
        printf("-> RISULTATO: DIVERSO ❌\n\n");


    // -------------------------------------------------------------------------
    // TEST 2: Copia di un array di interi (memoria non testuale)
    // -------------------------------------------------------------------------
    int src_ints[] = {10, 20, 30, 40, 50};
    int dest_ints_ft[5] = {0};
    int dest_ints_or[5] = {0};

    // Copiamo l'intero array (5 elementi * la dimensione di un int)
    ft_memcpy(dest_ints_ft, src_ints, sizeof(src_ints));
    memcpy(dest_ints_or, src_ints, sizeof(src_ints));

    printf("[TEST 2 - Array di interi]\n");
    printf("ft_memcpy: [%d, %d, %d, %d, %d]\n", dest_ints_ft[0],
             dest_ints_ft[1], dest_ints_ft[2], dest_ints_ft[3], dest_ints_ft[4]);
    printf("memcpy:    [%d, %d, %d, %d, %d]\n", dest_ints_or[0],
             dest_ints_or[1], dest_ints_or[2], dest_ints_or[3], dest_ints_or[4]);
    
    if (memcmp(dest_ints_ft, dest_ints_or, sizeof(src_ints)) == 0)
        printf("-> RISULTATO: OK ✅\n\n");
    else
        printf("-> RISULTATO: DIVERSO ❌\n\n");


    // -------------------------------------------------------------------------
    // TEST 3: Protezione NULL
    // -------------------------------------------------------------------------
 printf("[TEST 3 - Gestione NULL]\n");
    void *res = ft_memcpy(NULL, NULL, 5);
    if (res == NULL)
        printf("-> RISULTATO: OK (ha ritornato NULL correttamente) ✅\n");
    else
        printf("-> RISULTATO: FALLITO (non ha ritornato NULL) ❌\n");

    printf("\n--- FINE TEST ---\n");
    return (0);
}
*/
