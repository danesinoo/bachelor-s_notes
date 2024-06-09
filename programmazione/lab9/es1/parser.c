#include "corso.h"
#include "stdio.h"

int conta_linee(FILE* fp) {
    int nrighe = 0;
    while (fgetc(fp) != EOF) {
        if (fgetc(fp) == '\n') ++nrighe;
        ++fp;
    }
    return nrighe;
}

void leggi_studente(FILE* fp, Studente* s) {
    fscanf(fp, "%s", (*s).nome); // legge l'intera riga fino al punto
    char *name = (*s).nome;     // è un array di caratteri, quindi un puntatore
    while (*(name) != ' ')
        name++;
    *(name) = '\0';
    char *surname = (*s).cognome;
    while (*(++name) != ' ') {
        *(surname++) = *name;
    }
    for (int i= 0; i< N_VOTI; ++i)
        (*s).voti[i]= (int) strtol(name, "%d", &name);
}

void scrivi_studente(FILE* fp, Studente s) {
    fprintf(fp, "%s %s  ", s.nome, s.cognome);
    for (int i= 0; i< N_VOTI; ++i)
        fprintf(fp, "%3d", s.voti[i]);
    fprintf(fp, "\n");
}
//POST: scrive su file i dati di un unico studente