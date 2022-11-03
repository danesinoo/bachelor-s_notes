#include "matrici.h"

// il primo coefficiente della riga diventa 1
void e1(float *A, int colonne) {
    int i=0;
    while (A[i]==0 && i<colonne)
        i++;
    if (i== colonne) return;
    int sup = A[i];
    while (i<colonne) {
        A[i]= A[i] / sup;
        i++;
    }
}

// sottrae la riga riportata alla colonna
void e2(float *A, float *B, int colonne) {
    int i= 0;
    while (A[i]==0 && i<colonne)
        i++;
    if (B[i]==0) return;
    float sup= -B[i];
    while (i<colonne) {
        B[i]= B[i] + A[i]*sup;
        i++;
    }
}

// scambia due righe
void e3(float *A, float *B, int colonne) {
    int sup;
    for (int i=0; i<colonne; i++) {
        sup = A[i];
        A[i]= B[i];
        B[i]= sup;
    }
}

// trova la colonna dominante
int dominante(float *A, int righe, int colonne) {
    int j=0;
    while (j<colonne) {
        int i=0;
        while (i<righe) {
            if (A[i*colonne +j]!= 0) return i;
            i++;
        }
        j++;
    }
    return -1;
}

// effettua l'eliminazione di gauss
void elm_gauss(float *A, int righe, int colonne) {
    while (righe >= 0) {
        int dom =dominante(A, righe, colonne);
        if (dom==-1) return;
        else if (dom != 0) e3(A, A+dom*colonne, colonne);
        e1(A, colonne);
        for (int j= 1; j<righe; j++)
            e2(A, A+j*colonne, colonne);
//        stampa_matrice(A, righe, colonne);
//        printf("\n");
        A = A+colonne;
        righe--;
    }
}

// moduli di I/O

void prendi_matrice(float *A, int righe, int colonne) {
    int i=0;
    while (i< righe) {
        for (int j=0; j<colonne; j++)
            scanf("%f", A+i*colonne+j);
        i++;
    }
    printf("Ricevuta la seguente matrice:\n");
    stampa_matrice(A, righe, colonne);
    printf("\n");
}

void stampa_matrice(float *A, int righe, int colonne) {
    for (int i=0; i< righe; i++) {
        for (int j=0; j< colonne; j++)
            printf("%7.2f", A[i*colonne+j]);
        printf("\n");
    }
}

// Operazioni con le matrici

// aggiunge la colonna B alla matrice A
void genera_matrice(float *A, float *B, float *C, int righe, int colonne) {
    for (int k=0; k< righe; k++) {
        for (int j=0; j<colonne; j++)
            C[k*(colonne +1) +j] = A[k*colonne +j];
        C[k*(colonne +1) + colonne] = B[k];
    }
}

// estrae la colonna i-esima e la salva in B
void estrai_colonna(float *A, float *B, int righe, int colonne, int colonna) {
    for (int j=0; j<righe; j++) 
        B[j] = A[j*colonne + colonna-1];    // +1 per utilizzare la semantica di algebra corrisponde a moltiplicare per e_{i}
}

void trova_incognite(float *A, float *B, int righe, int colonne) {
    for (int i= righe-1; i>= 0; i--) {
        B[i] = A[(i+1) * colonne -1];
        for (int j = colonne -2; j> i; j--) 
//        printf("%.2f %.2f\n", A[i*colonne +j], B[j]); // fino a qui tutto bene
            B[i] -= (A[i*colonne + j] * B[j]);
    }
}

void risolvi_sistema(float *A, float *B, int righe, int colonne) {
    float matrice[(colonne+1)* righe];
    genera_matrice(A, B, matrice, righe, colonne);
    elm_gauss(matrice, righe, colonne +1);
//    stampa_matrice(matrice, righe, colonne+1);
//    printf("\n");
    trova_incognite(matrice, B, righe, colonne+1);
}

/*
void cambio_base(float *A, float *B, int righe1, int colonne1, int righe2, int colonne2) {

}
*/