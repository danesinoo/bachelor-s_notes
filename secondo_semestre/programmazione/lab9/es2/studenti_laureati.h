#include <stdlib.h>
#include <stdio.h>
#define N_VOTI 5

typedef struct studenti
{
    char nome[256];
    char cognome[256];
    int voti[N_VOTI];
    //struct qui
} Studente_extra;


// int conta_linee(FILE* fp); // in parser.c

// void leggi_studente(FILE* fp, Studente_extra* s); // in parser.c
// void scrivi_studente(FILE* fp, Studente_extra s); // in parser.c

// float calcola_media(Studente_extra s);   // in studente.c
// int sufficienza_studente(Studente_extra s);  // in studente.c
int completato_percorso(Studente_extra s);
/* 
    POST: ritorna
        1 ha fatto tutti gli esami ed è sufficiente o è già laureato
        0 altrimenti
*/

float calcola_media(Studente_extra s);
// PRE: voti contiene valori compresi tra 0 e 30 oppure uguali a -1 (voto ancora non conseguito)
// POST calcolare la media dei voti conseguiti

int sufficienza_studente(Studente_extra s);
// POST: restituisce 1 se la media dei voti conseguiti è >= 18, 0 altrimenti

void print_studente(Studente_extra s);
// Funzione di utilità per stampare a schermo tutti i dati dello studente

int conta_linee(FILE *fp);
// POST: conta il numero di entries nel file

void leggi_studente(FILE *fp, Studente_extra *s);
// POST: legge da file i dati relativi ad un unico studente

void scrivi_studente(FILE *fp, Studente_extra s);
// POST: scrive su file i dati di un unico studente
