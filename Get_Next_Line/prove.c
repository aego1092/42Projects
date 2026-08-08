// #include <stdlib.h>

// char *ft_strjoin(char *s1, char *s2)
// {
// 	int	i1;
// 	int	i2;
// 	char	*str;

// 	if (!s1 && !s2)
// 		return (NULL);
	
// 	str= (char*)malloc((ft_strlen(s1)+ft_strlen(s2)+1)*sizeof(char));
// 	if (!str)
// 		return (NULL);
	
// 	i1 = 0;
// 	if (s1)
// 	{
// 		while (s1[i1])
// 		{
// 			str[i1] = s1[i1];
// 			i1++;
// 		}
// 	}
// 	i2 = 0;
// 	if (s2)
// 	{
// 		while (s2[i2])
// 		{
// 			str[i1 + i2] = s2[i2];
// 			i2++;
// 		}
// 	}
// 	str[i1 + i2] = '\0';
// 	return(str);
// }

#include <stdio.h>
#include <unistd.h> // Contiene la funzione read()

int main() {
    char buffer[100];
    
    printf("Scrivi qualcosa e premi Invio: ");
    fflush(stdout); // Forza la stampa del testo prima della read

    // Legge al massimo 99 byte per lasciare spazio al '\0' finale
    ssize_t byte_letti = read(0, buffer, 99);

    if (byte_letti == -1) {
        perror("Errore nella lettura");
        return 1;
    }

    // Aggiungiamo manualmente il carattere di fine stringa
    buffer[byte_letti] = '\0';

    printf("Hai scritto %ld byte: %s", byte_letti, buffer);

    return 0;
}