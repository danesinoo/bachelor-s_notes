#define N_VOTI 5

typedef struct studente {
    char nome[256];
    char cognome[256];
    int voti[N_VOTI];
} Studente;

float calcola_media(Studente s);
//PRE: voti contiene valori compresi tra 0 e 30 oppure uguali a -1 (voto ancora non conseguito)
//POST calcolare la media dei voti conseguiti

int sufficienza_studente(Studente s);
//POST: restituisce 1 se la media dei voti conseguiti è >= 18, 0 altrimenti

void print_studente(Studente s);
//Funzione di utilità per stampare a schermo tutti i dati dello studente
