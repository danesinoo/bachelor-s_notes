#include "corso.h"
#include "studente.h"

float percentuale_superamento_test(Studente s[], int n_studenti, int esame) {
    float superamento = 0.;
    float npresente = 0.;

    for (int i= 0; i< n_studenti; ++i) {
        if (s[i].voti[esame] > -1) {
            superamento += s[i].voti[esame];
            npresente += 1;
        }
    }
    return superamento / npresente;
}

Studente miglior_studente(Studente s[], int n_studenti) {
    float best_stdnt = 0.;
    int nstdnt;
    for (int i= 0; i < n_studenti; ++i) {
        if (calcola_media(s[i]) > best_stdnt) {
            best_stdnt = calcola_media(s[i]);
            nstdnt = i;
        }
    }
    return s[nstdnt];
}

void ordina_studenti(Studente s[], int n_studenti) {
    
}

void quickSort(Studente arr[], int low, int high) {
    if (high < 1)
        return;
    Studente copia[high]; // non ci serve arr[0]
    int j = 0;
    int i = 0;
    while (i < high)
    {
        if (calcola_media(arr[1 + i]) < calcola_media(arr[0]))
        {
            *(copia + j++) = *(arr + 1 + i);
        }
        i++;
    }
    trasla(arr, copia, j - 1, high, 0);
    copia_array(copia, arr, j);
    quickSort(arr, 0, j - 1);
    quickSort(arr + j + 1, 0, high - j - 1);
}

void trasla(Studente *arr, Studente *copia, int dim_copia, int high, int salto) {
    if (high - salto < 0)
        return;
    else if (dim_copia > -1 && calcola_media(arr[high - salto]) == calcola_media(copia[dim_copia]))
    {
        salto++;
        dim_copia--;
        trasla(arr, copia, dim_copia, high, salto);
    }
    else
    {
        *(arr + high) = *(arr + high - salto);
        trasla(arr, copia, dim_copia, high - 1, salto);
    }
}

void copia_array(float A[], float B[], int dim) {
    if (dim == 0)
        return;
    *B = *A;
    copia_array(++A, ++B, --dim);
}