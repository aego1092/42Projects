/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 11:49:34 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/06/01 16:25:33 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr_dest;
	const unsigned char	*ptr_src;
	size_t	i;
	
	ptr_dest = (unsigned char *)dest;
	ptr_src = (const unsigned char *)src;

	if (ptr_dest <= ptr_src)
	{
		i = 0;
		while (i < n)
		{
			*(ptr_dest + i) = *(ptr_src + i);
			i++;
		}
	}
	else 
	{
		i = n;
		while (--i > 0 )
		{
		 	*(ptr_dest + i) = *(ptr_src + i);
			//i--;
		}
		*(ptr_dest) = *(ptr_src);
	}
	return (dest);
}


int main() {
    // Definiamo una stringa (array di char) modificabile
    char testo[50] = "Programmazione C!";
    
    printf("Stringa originale:        \"%s\"\n", testo);

    // --- CASO 1: Copia tra aree di memoria che si sovrappongono ---
    // Vogliamo spostare "C!" in avanti per fare spazio alla parola "in "
    // Sorgente (src): punta a "C!" -> testo + 15
    // Destinazione (dest): punta a dove vogliamo metterlo -> testo + 18
    // Dimensione: 3 byte (i caratteri 'C', '!' e il terminatore '\0')
    
    memmove(testo + 18, testo + 15, 3);
    
    printf("Dopo il primo memmove:    \"%s\"\n", testo);

    // Ora inseriamo la parola "in " nello spazio liberato
    // In questo caso usiamo memcpy perché le aree NON si sovrappongono
    memcpy(testo + 15, "in ", 3);
    
    printf("Dopo l'inserimento:       \"%s\"\n\n", testo);


    // --- CASO 2: Spostamento all'indietro (Sovrapposizione distruttiva con memcpy) ---
    // Resettiamo l'array con una nuova stringa
    strcpy(testo, "0123456789");
    printf("Nuova stringa di test:    \"%s\"\n", testo);

    // Vogliamo copiare i caratteri "3456" (da indice 3, lungh. 4) all'indice 1
    // Destinazione: testo + 1
    // Sorgente: testo + 3
    // Le aree si sovrappongono: [1,2,3,4] e [3,4,5,6]
    memmove(testo + 1, testo + 3, 4);

    printf("Dopo memmove (indici 3-6): \"%s\"\n", testo);
    // Risultato atteso: "0345656789"

    return 0;
}