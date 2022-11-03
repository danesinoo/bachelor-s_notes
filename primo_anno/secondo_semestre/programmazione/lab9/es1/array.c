#include <stdio.h>
#include "array.h"

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