#include "studenti_laureati.h"
#include <stdio.h>

float calcola_media(Studente_extra s);
//PRE: voti contiene valori compresi tra 0 e 30 oppure uguali a -1 (voto ancora non conseguito)
//POST calcolare la media dei voti conseguiti

int sufficienza_studente(Studente_extra s);
//POST: restituisce 1 se la media dei voti conseguiti è >= 18, 0 altrimenti

void print_studente(Studente_extra s);
//Funzione di utilità per stampare a schermo tutti i dati dello studente
