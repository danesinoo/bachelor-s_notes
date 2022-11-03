#include "matrici.h"

int linearmente_indipendente(float *, int, int);

int main() {
/*    int righe1, colonne1;
    printf("Indicare il numero delle righe e delle colonne:\n");
    scanf(" %d %d", &righe1, &colonne1);
    printf("Indicare i coefficiente della matrice\n");
    float matrice[righe1*colonne1];
    prendi_matrice(matrice, righe1, colonne1);

    int righe2, colonne2;
    printf("Indicare il numero delle righe e delle colonne:\n");
    scanf(" %d %d", &righe2, &colonne2);
    printf("Indicare i coefficiente della matrice\n");
    float matrice1[righe2*colonne2];
    prendi_matrice(matrice1, righe2, colonne2);
*/

    float matrice[]= {1., 0., 1., 0., 3., 0., 1., 0., -1.};
    float termini_noti[]= {0., 0., 0.};

    risolvi_sistema(matrice, termini_noti, 3, 3);
    printf("Risoluzione del sistema:\n");
    stampa_matrice(termini_noti, 3, 1);
}

int linearmente_indipendente(float *A, int righe, int colonne) {
    float B[colonne];
    for (int i=0; i< colonne; i++)
        B[i]= 0.;
    risolvi_sistema(A, B, righe, colonne);
    for (int i=0; i< colonne; i++) 
        if (B[i]!= 0) return 0;
    return 1;
}

// autovettori e autovalori geometricamente