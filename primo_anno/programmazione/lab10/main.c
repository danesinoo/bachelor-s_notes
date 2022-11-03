#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "salva.h"
#include "board.h"
#include "partita.h"
#include "giocatore.h"


int main(int argc, char *argv[]) {

    srand(1);

    if(argc!=2){
        printf("Selezionare una modalità di gioco (1vs1 o 1vscpu o carica)\n");
        return -1;
    }
    //strcmp è definita in string.h e confronta due stringhe, restituisce 0 se sono uguali. L'abbiamo implementata come funzione ricorsiva in un laboratorio passato
    if(strcmp(argv[1], "1vs1")!=0 && strcmp(argv[1],"1vscpu")!=0 && strcmp(argv[1], "carica")!=0) {
        printf("Errore, modalità di gioco non esiste (1vs1 o 1vscpu o carica)\n");
        return -1;
    }
    char continua = 's'; //indica la volontà del giocatore di continuare a giocare

    while(continua == 's'){
        if(!strcmp(argv[1], "carica")) {
            int mod = carica_partita();
            argv[1] = mod == 0 ? "1vs1" : "1vscpu";
        }
        else
            primo_salvataggio(argv[1]);
        printf("Altra partita? (s/n)\n");
        scanf(" %c%*c", &continua);
    }

}
