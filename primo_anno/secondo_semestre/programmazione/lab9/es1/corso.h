#include "studente.h"

float percentuale_superamento_test(Studente s[], int n_studenti, int esame);
//PRE: esame compreso tra 0 e 4
//POST: calcola la percentuale di superamento di un dato esame (solo guardando gli studenti che hanno conseguito un voto, chi non ha fatto l'esame non è contato)

Studente miglior_studente(Studente s[], int n_studenti);
//POST: restituisce lo studente con la media più alta

void ordina_studenti(Studente s[], int n_studenti);
//POST: ordina gli studenti a seconda della loro media
//NOTA: l'algoritmo di ordinamento da utilizzare è a vostra discrezione. E' consentito riadattare gli esercizi sul mergesort o sul quicksort se volete