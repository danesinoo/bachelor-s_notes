#include <stdio.h>

/*
 * Scrivere una funzione che dati: 
 * - due array X e Y ordinati in modo crescente
 * - le loro dimensioni dim_X e dim_Y
 * - un terzo array Ord di dimensione dim_X+dim_Y
 * immetta i valori di X e Y in Ord in modo che anche
 * Ord risulti ordinato in modo crescente. Il prototipo
 * della funzione è il seguente
 *
 void combina_array(int *X, int dim_X, int *Y, int dim_Y, int *Ord)
 * 
 * Ad esempio se X={3,6,8} e Y={4,5,7,9}, 
 * Ord={3,4,5,6,7,8,9}
 * 
 */

void combina_array(int *X, int dim_X, int *Y, int dim_Y, int *Ord) {
    /* 
        PRE: X, di dimensione dim_X ed Y, di dimensione dim_Y, sono ordinati in modo crescente; Ord è di dimensione dim_X+dim_Y
        POST: Ord contiene gli elementi di X e Y, Ord è ordinato in modo crescente
    */
   
   if (dim_X == 0) {        // controllo che il primo array non sia vuoto
       if (dim_Y == 0) {    // controllo che il secondo array non sia vuoto
           return;
       }
       else {
           *Ord = *Y;
           return combina_array(X, 0, Y+1, dim_Y-1, Ord+1);
       }
    }
    else if (dim_Y == 0) {  // controllo che il secondo array non sia vuoto
        *Ord= *X;
        return combina_array(X+1, dim_X-1, Y, 0, Ord+1);
    }
    else if (*X <= *Y) {    // confronto tra gli array
        *Ord= *X;
        return combina_array(X+1, dim_X-1, Y, dim_Y, Ord+1);
    }
    else {
        *Ord= *Y;
        return combina_array(X, dim_X, Y+1, dim_Y-1, Ord+1);
    }
}

/* devo porre il caso che X[] o Y[] non abbiamo più elementi, ciascuno e quindi
 * si inserisce l'altro array. Ci starebbe un ciclo for nel qual caso, ma non
 * lo far;
 *
 * altrimenti si fa un confronto if (x >= y) *ord= y return combina_array(...
 * ord + 1);
 *
 * altrimenti *ord = x; return combina_array(.., dim_y -1, .. ord + 1)
 */

int main(void) {

    int X[3] = {3,6,8};
    int Y[4] = {4,5,7,9};
    int Z[7];

    combina_array(&X[0], 3, &Y[0], 4, &Z[0]);
    
    for(int i=0; i<7; i+=1) {
        printf(" %d", Z[i]);
    }
    printf("\n");
}