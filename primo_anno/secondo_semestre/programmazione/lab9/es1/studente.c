#include "studente.h"
#define N_VOTI 5

typedef struct studente {
    char nome[256];
    char cognome[256];
    int voti[N_VOTI];
} Studente;

float calcola_media(Studente s) {
    int somma = 0;
    int nvoti = 0;

    for (int i= 0; i< N_VOTI; i++) {
        if (s.voti[i] > -1) {
            somma += s.voti[i];
            ++nvoti;
        }
    }
    return (float) somma / (float) nvoti;
}

int sufficienza_studente(Studente s) {
    if (calcola_media(s) > 17) return 1;
    return 0;
}

void print_studente(Studente s) {
    printf("nome: %s cognome: %s\n", s.nome, s.cognome);
    printf("VOTI:\n");
    for (int i=0; i<5; ++i) {
        printf("Voto prova %d: %.2f\n", i+1, s.voti[i]);
    }
}
//Funzione di utilità per stampare a schermo tutti i dati dello studente
