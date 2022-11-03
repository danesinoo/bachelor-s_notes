#include <stdio.h>
#include "studenti_laureati.h"
#include <stdlib.h>

int conta_linee(FILE* fp) {
    int nrighe = 0;
    while (fgetc(fp) != EOF) {
        if (fgetc(fp) == '\n') ++nrighe;
        ++fp;
    }
    return nrighe;
}

void leggi_Studente(FILE* fp, Studente_extra* s) {
    fscanf(fp, "%s", (*s).nome);
    char *name = (*s).nome;

    while (*(name) != ' ')  // salta il nome
        name++;

    *(name) = '\0'; // %s finisce
    char *surname = (*s).cognome;
    while (*(++name) != ' ') {  // copia il cognome
        *(surname++) = *(name++);
    }

    name++; // abbiamo finito di trascrivere il cognome
    if (*(name) == 'L') {   // se è laureato
            (*s).voti[0] = -2;
            while ((*name) != ' ') name++;  // finito laureato
            name++; // togliamo lo spazio
            (*s).voti[1]= strtol(name, &name, 0);
            (*s).voti[2]= strtol(name, &name, 0);
            return;
        }
    
    while((*name) != ' ') name++;   // finito non_laureato
    for (int i= 0; i< N_VOTI; ++i)
        (*s).voti[i]= (int) strtol(name, &name, 0);
}

void scrivi_Studente(FILE* fp, Studente_extra s) {
    fprintf(fp, "%s %s ", s.nome, s.cognome);
    if (s.voti[0]== -2) {    // i laureati hanno voti[0] == -2
        fprintf(fp, "Laureato ");
        fprintf(fp, "%3d.%.2d", s.voti[1], s.voti[2]);  // dato che voti[1] è la parte intera della media e voti[2] è la parte razionale
        return;
    }
    fprintf(fp, "Non_Laureato ");
    for (int i= 0; i< N_VOTI; ++i)
        fprintf(fp, "%3d", s.voti[i]);
    fprintf(fp, "\n");
}
//POST: scrive su file i dati di un unico Studente_extra