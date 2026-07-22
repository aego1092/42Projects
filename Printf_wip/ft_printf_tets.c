/*
PASSANGGIO PER CONTEGGIO ESATTO
#include <stdio.h>
#include <stdarg.h>

// Il primo parametro 'quanti' dice alla funzione quanti int aspettarsi

void stampa_numeri(int quanti, ...)
{
    va_list args;
    va_start(args, quanti);

    for (int i = 0; i < quanti; i++)
    {
        int num = va_arg(args, int);
        printf("Numero %d: %d\n", i + 1, num);
    }

    va_end(args);
}

int main()
{
    // Diciamo esplicitamente che passiamo 3 numeri
    stampa_numeri(3, 10, 20, 30); 
    return 0;
}
*/


/*
Per Valore Sentinella (Sentinel Value)
#include <stdio.h>
#include <stdarg.h>

// La funzione concatena stringhe finché non incontra NULL
void stampa_parole(char *prima_parola, ...)
{
    va_list args;
    va_start(args, prima_parola);

    char *corrente = prima_parola;
    
    while (corrente != NULL)
    {
        printf("%s ", corrente);
        // Estraiamo la prossima stringa
        corrente = va_arg(args, char *);
    }
    printf("\n");

    va_end(args);
}

int main()
{
    // MANDATORIO: Finire la chiamata con NULL, altrimenti la funzione continua a leggere la memoria!
    stampa_parole("Il", "metodo", "42", "è", "fantastico", NULL);
    return 0;
}
*/

#include <stdio.h>
#include <stdarg.h>

// La funzione legge la stringa 'formato' e decide cosa estrarre in base a 'i' o 'c'
void mini_stampa(const char *formato, ...)
{
    va_list args;
    va_start(args, formato);

    for (int j = 0; formato[j] != '\0'; j++)
    {
        if (formato[j] == '%')
        {
            j++; // Guardiamo il carattere dopo il %
            if (formato[j] == 'i') // 'i' sta per intero
            {
                int n = va_arg(args, int);
                printf("%d", n);
            }
            else if (formato[j] == 'c') // 'c' sta per carattere
            {
                int c = va_arg(args, int); // Ricorda la promozione automatica a int!
                putchar(c);
            }
        }
        else
        {
            putchar(formato[j]); // Stampa i caratteri normali
        }
    }

    va_end(args);
}

int main()
{
    // La stringa di formato dice: "ci sono un intero e un carattere"
    mini_stampa("Voto: %i, Giudizio: %c\n", 30, 'A');
    return 0;
}