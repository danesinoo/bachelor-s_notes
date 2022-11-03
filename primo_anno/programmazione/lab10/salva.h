#ifndef SALVA_H
#define SALVA_H

void primo_salvataggio(char []);
/* 
    POST: salva le condizioni della prima partita, ritorna 0: il turno
*/

void salva(int, int, int);
/*
    POST: aggiorna la partita alle condizioni attuali: turno 
*/

//void mostra_salvato();

int carica_partita(void);
/*
    POST: carica una partita salvata
*/

#endif 