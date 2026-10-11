/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddi-nico <ddi-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 14:30:08 by ddi-nico          #+#    #+#             */
/*   Updated: 2026/08/12 15:22:00 by ddi-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>

void first_word(int argc, char **argv)
{
    int i;

    // Stampiamo la prima parola SOLO se c'è esattamente 1 argomento
    if (argc == 2)
    {
        i = 0;
        // Salta eventuali spazi o tab iniziali
        while (argv[1][i] == ' ' || argv[1][i] == '\t')
            i++;
        
        // Stampa finché non incontra spazio, tab o fine stringa
        while (argv[1][i] != ' ' && argv[1][i] != '\t' && argv[1][i] != '\0')
        {
            write(1, &argv[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
}

int main(int argc, char **argv)
{
    first_word(argc, argv);
    return (0);
}