#include "pila.h"
#include <stdlib.h>
#include <stdio.h>

void print_pila(Pila pila) {
    printf("[");
    for (int i=0; i<pila.size; i++)
        printf("%d ", *(pila.data- i));
    printf("]\n");
}
void init(Pila* pila){ //Inizializza pila con capacity 1 e senza nessun elemento
    pila->capacity = 1;
    pila->size = 0;
    pila->data = (int *)malloc(sizeof(int));
}
void push(Pila* pila, int elem) {
    if (pila->size < pila->capacity) {
        pila->data++;
        *(pila->data) = elem;
        pila->size++;
    }

    else {
        pila->data = realloc(pila->data - pila->size, (pila->capacity + 1) * 2 * sizeof(int));
        pila->data += pila->size;
        pila->capacity *= 2;
        push(pila, elem);
    }
}

int pop(Pila* pila) {
    pila->size--;
    pila->data--;
    return *(pila->data +1);
}