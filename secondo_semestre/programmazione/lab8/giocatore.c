#include "giocatore.h"
#include "board.h"
#include <stdlib.h>
#include <stdio.h>


void scegli_mossa_utente(int *x, int *y) {
    printf("Inserisci Mossa: ");
    scanf("%d %d", x, y);
}


void scegli_mossa_computer(int *x, int *y) {
    // Inserite qua il vostro codice
    *x = rand() % 3;    // assegno valori casuali
    *y = rand() % 3;
}
// con le classi di equivalenza mi assicuro che vada sempre bene
