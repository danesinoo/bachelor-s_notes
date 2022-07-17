#include "studenti_laureati.h"
#include <stdio.h>

int completato_percorso(Studente_extra s) {
    if (s.voti[0] == -2) return 1;
    for (int i= 0; i< N_VOTI; i++) {
        if (s.voti[i] == -1) return 0;
    }
    if (sufficienza_studente(s)) return 0;
    else return 1;
}

float calcola_media(Studente_extra s)
{
    if (s.voti[0] == -2)
        return (float)s.voti[1] + (float)s.voti[2] / 100.;
    int somma = 0;
    int nvoti = 0;

    for (int i = 0; i < N_VOTI; i++)
    {
        if (s.voti[i] > -1)
        {
            somma += s.voti[i];
            ++nvoti;
        }
    }
    return (float)somma / (float)nvoti;
}

int sufficienza_studente(Studente_extra s)
{
    if (calcola_media(s) > 17)
        return 1;
    return 0;
}

void print_studente(Studente_extra s) {
    printf("nome: %s cognome: %s\n", s.nome, s.cognome);
    if (s.voti[0] == -2) {
        printf("Laureato\n");
        printf("Media: %d.%d\n", s.voti[1], s.voti[2]);
    }
    else {
        printf("Non Laureato\n");
        printf("VOTI:\n");
        for (int i = 0; i < 5; ++i)
        printf("Voto prova %d: %d\n", i + 1, s.voti[i]);
    }
}
// Funzione di utilità per stampare a schermo tutti i dati dello studente

int conta_linee(FILE *fp)
{
    int nrighe = 0;
    while (feof(fp))
    {
        if (fgetc(fp) == '\n')
            ++nrighe;
        ++fp;
    }
    return nrighe;
}

void leggi_studente(FILE *fp, Studente_extra *s)
{
    fscanf(fp, "%s", (*s).nome);
    char *name = (*s).nome;

    while (*(name) != ' ') // salta il nome
        name++;

    *(name) = '\0'; // %s finisce
    char *surname = (*s).cognome;
    while (*(++name) != ' ')
    { // copia il cognome
        *(surname++) = *(name++);
    }

    name++; // abbiamo finito di trascrivere il cognome
    if (*(name) == 'L')
    { // se è laureato
        (*s).voti[0] = -2;
        while ((*name) != ' ')
            name++; // finito laureato
        name++;     // togliamo lo spazio
        (*s).voti[1] = strtol(name, &name, 0);
        (*s).voti[2] = strtol(name, &name, 0);
        return;
    }

    while ((*name) != ' ')
        name++; // finito non_laureato
    for (int i = 0; i < N_VOTI; ++i)
        (*s).voti[i] = (int)strtol(name, &name, 0);
}

void scrivi_studente(FILE *fp, Studente_extra s)
{
    fprintf(fp, "1\n");
/*
    fprintf(fp, "%s %s ", s.nome, s.cognome);
    if (s.voti[0] == -2)
    { // i laureati hanno voti[0] == -2
        fprintf(fp, "Laureato ");
        fprintf(fp, "%3d.%.2d", s.voti[1], s.voti[2]); // dato che voti[1] è la parte intera della media e voti[2] è la parte razionale
        return;
    }
    fprintf(fp, "Non_Laureato ");
    for (int i = 0; i < N_VOTI; ++i)
        fprintf(fp, "%3d", s.voti[i]);
    fprintf(fp, "\n");
*/
}
// POST: scrive su file i dati di un unico Studente_extra