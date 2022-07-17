#include <stdio.h>

void e1(float *A, int colonne);
/* 
    POST: porta il primo coefficiente della riga ad uno e tratta il resto della riga di conseguenza
*/
void e2(float *A, float *B, int colonne);
/*
    POST: sottrae alla riga B, la riga A, in modo tale che A diventi colonna dominante
*/

void e3(float *A, float *B, int colonne);
/*
    POST: scambia due righe
*/

void elm_gauss(float *A, int righe, int colonne);
/*
    POST: A diventa la forma ridotta di A
*/

int dominante(float *A, int righe, int colonne);
/*
    POST: ritorna la prima colonna dominante
*/

void stampa_array(float *A, int righe, int colonne);
/*
    POST: stampa l'array
*/

// Moduli di I/O

void prendi_matrice(float *A, int righe, int colonne);
/*
    POST: prende una matrice da input
*/

void stampa_matrice(float *A, int righe, int colonne);

// operazioni con le matrici

void genera_matrice(float *A, float *B, float *C, int righe, int colonne);
/*
    POST: aggiunge la colonna B alla colonna A in C
*/

void estrai_colonna(float *A, float *B, int righe, int colonne, int i);
/*
    POST: assegna assegna la i-esima colonna di A a B
*/

void trova_incognite(float *A, float *B, int righe, int colonne);
/*
    PRE: la matrice A è una matrice ridotta attraverso l'eliminazione di Gauss
    POST: B ha i valori delle incognite del sistema rappresentato da A
*/

void risolvi_sistema(float *A, float *B, int righe, int colonne);
/*
    POST: risolve un sistema composto solo da colonne dominanti e con soluzione
*/

//void cambio_base(float *A, float *B, int righe1, int colonne1, int righe2, int colonne2);
/*
    POST: cambio base per spazi generati da insiemi di vettori (ciascuna colonna di B corrisponde ad un vettore dell'insieme)
*/