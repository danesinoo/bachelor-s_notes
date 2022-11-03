#include <stdio.h>
#define DIMENSIONE 3

/*
* Scrivete la funzione "moltiplicaMatrici" che calcola la moltiplicazione tra
* due matrici quadrate di numeri interi.
*
* L'operazione consiste nell'effettuare il prodotto scalare tra le righe della
* prima matrice e le colonne della seconda.
*
* Esempio:
* |a b| |e f| ____ |a*e+b*g a*f+b*h|
* |c d| |g h|      |c*e+d*g c*f+d*h|
*
* La funzione riceve come argomenti i puntatori alle due matrici di input ed
* alla matrice in cui salvare il risultato
* 
* void moltiplicaMatrici(int dim, int *mat1, int *mat2, int *matRisultato)
*
* Per la consegna, utilizzare:
* mat1 = {{1,2,3},{4,5,6},{7,8,9}}
* mat2 = {{9,8,7},{6,5,4},{3,2,1}}
*
* Utilizzare il seguente codice per stampare il risultato:
* for (int i = 0; i < dim; i += 1){
*   for (int j = 0; j < dim; j += 1){
*       printf("%d\t", matRisultato{i}{j}); 
*   }
*   printf("\n");
* }
*/

void moltiplicaMatrici(int dim, int *mat1, int *mat2, int *matRisultato);

int main(void) {
    int mat1[DIMENSIONE][DIMENSIONE] = {
        {1, 2, 3}, 
        {4, 5, 6},
        {7, 8, 9}};
    int mat2[DIMENSIONE][DIMENSIONE] = {
        {9, 8, 7}, 
        {6, 5, 4},
        {3, 2, 1}};
    int matRisultato[DIMENSIONE][DIMENSIONE] = {0};

    moltiplicaMatrici(DIMENSIONE*DIMENSIONE -1, &(mat1[0][0]), &(mat2[0][0]), &(matRisultato[0][0]));

    for (int i = 0; i < DIMENSIONE; i += 1) {
        for (int j = 0; j < DIMENSIONE; j += 1) {
            printf("%d\t", matRisultato[i][j]);
        }
        printf("\n");
    }
}

void moltiplicaMatrici(int dim, int *mat1, int *mat2, int *matRisultato) {
// PRE inseriamo la posizione del valore da calcolare e le matrici attraverso cui calcolare il valore

// POST matRisultato è il prodotto tra mat1 e mat2

    if (dim < 0) return; // CASO BASE: si ferma quando dim == -1

    for (int i=0; i < DIMENSIONE; i++) {
        // PRE: *(matRisultato + dim)== 0
        // POST: matRisultato[i][j] = vettori_riga_mat1[i] * vettore_colonna_mat2[j]

        // INV *(matRisultato + dim) = mat1[k][dim/DIMENSIONE * DIMENSIONE] * mat2[dim % DIMENSIONE][k] + mat1[j]... * mat2..[j] + ... per ogni j,k,... < i, ma contenuto in N. Fondamentalmente la cella *(matRisultato + dim) è un invariante e contiene la somma parziale del prodotto riga per colonna tra le matrici mat1 e mat2
        *(matRisultato + dim) += *(mat1 + i + (dim / DIMENSIONE) * DIMENSIONE) * *(mat2 + i * DIMENSIONE + dim % DIMENSIONE);
    }
    return moltiplicaMatrici(dim -1, mat1, mat2, matRisultato);
}