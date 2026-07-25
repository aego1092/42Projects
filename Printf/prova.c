#include <stdio.h>

// printf("Testo con %segnaposto", variabile1, variabile2);

// int main() {
//     printf("Ciao mondo!\n");
//     printf("Questo testo va a capo.");
//     return 0;
// }



// int main() {
//     int eta = 20;
//     printf("Ho %d anni.\n", eta);
    
//     // Output: Ho 20 anni.
//     return 0;
// }

// int main() {
//     char iniziale = 'M';
//     int punti = 100;
//     float tempo = 12.5;

//     printf("Giocatore %c: %d punti in %f secondi.\n", iniziale, punti, tempo);
    
//     // Output: Giocatore M: 100 punti in 12.500000 secondi.
//     return 0;
// }


int main() {
    float prezzo = 19.99;
    float voto = 28.5;

    // %f stampa il float standard, %.2f lo limita a 2 decimali
    printf("Prezzo: %.2f EUR\n", prezzo);
    printf("Voto: %.1f\n", voto);

    return 0;
}