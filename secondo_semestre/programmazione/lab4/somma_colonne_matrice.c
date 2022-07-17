#include <stdio.h>

void leggi_array(int * array, unsigned int dim){
    for(int i = 0; i< dim; i=i+1){
        scanf("%d", array+i);
    }
}

void calcola_somma(int *matrix, unsigned int righe, unsigned int colonne, int* somma){

// eseguo un ciclo for per ogni valore nella matrice matrix
	for (int i = 0; i < righe * colonne; i++) {

// il resto della divisione i / colonne ritorna la colonna del valore che devo sommare
// e quindi mi basta aggiungerla al puntatore della matrice somma, mentre matrice + i
// punta al valore che devo sommare
		*(somma + (i % colonne)) += *(matrix + i);
	}
}

int main(){
    int righe, colonne;

    scanf("%u", &righe);
    scanf("%u", &colonne);

    int mat[righe][colonne];

    leggi_array(*mat, righe*colonne);

    // array contenente le somme di ogni colonna
    int somma[colonne];

//setto tutte le colonne a 0
	for (int i = 0; i < colonne; i++) {
		somma[i] = 0;
	}

    calcola_somma(*mat, righe, colonne, somma);

    for(int i = 0; i < colonne; i = i+1){
        printf("La somma della colonna %d è %d\n", i, somma[i]);
    }
}
