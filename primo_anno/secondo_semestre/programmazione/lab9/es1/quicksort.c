#include "array.h"
#include "quicksort.h"

void quickSort(float arr[], int low, int high) {
    if (high < 1) return;
    int copia[high];   // non ci serve arr[0]
    int j = 0;
    int i = 0;
    while (i < high) {
        if (*(arr +1 +i) < *arr) {
            *(copia + j++) = *(arr +1 +i);
        }
        i++;
    }
    trasla(arr, copia, j -1, high, 0);
    copia_array(copia, arr, j);
    quickSort(arr, 0, j-1);
    quickSort(arr +j +1, 0, high -j -1);
}

void trasla(float *arr, int* copia, int dim_copia, int high, int salto) {
    if (high - salto < 0) return;
    else if (dim_copia > -1 && *(arr +high -salto) == *(copia +dim_copia)) {
        salto++; 
        dim_copia--;
        trasla(arr, copia, dim_copia, high, salto);
    }
    else {
        *(arr + high) = *(arr +high -salto);
        trasla(arr, copia, dim_copia, high -1, salto);
    }
}

void copia_array(int A[], int B[], int dim)

{
    /*
        PRE dim è il numero di elementi di A e B.
        POST B è una copia di A
     */

    if (dim == 0)
        return;
    *B = *A;
    copia_array(++A, ++B, --dim);
}

void stampaArray(int A[], int dim)
{
    /*
     * PRE: A ha dimensione almeno dim
     * POST stampa a video gli elementi di A su
     * una riga separati da spazi e poi va a capo.
     */
    if (dim == 0)
    {
        printf("\n");
        return;
    }
    printf("%d ", *A);
    return stampaArray(++A, --dim);
}