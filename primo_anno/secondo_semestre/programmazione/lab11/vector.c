#include "vector.h"
#include <stdlib.h>
#include <stdio.h>

void init(Vector* vettore) { //PRE: Il puntatore non è NULL
    vettore->capacity = 1;
    vettore->size = 0;
    vettore->data = (int *)malloc(sizeof(int));
}

int read(Vector vettore, unsigned int index) {
    return vettore.data[index];
}

void insert_element(Vector* v, int data, unsigned int pos) {
    if (v->size < v->capacity && pos < v->size+1) {
        v->size++;
        int sup;
        for (int i=pos; i<v->size; i++) {
            sup = read(*v, i);
            v->data[i] = data;
            data= sup;
        }
    }

    else if (v->size == v->capacity) {
        v->data = realloc(v->data, sizeof(int) * v->capacity * 2);
        v->capacity = v->capacity * 2;
        insert_element(v, data, pos);
    }
}

void delete_element(Vector* v, unsigned int pos) {
    for (int i=pos+1; i<v->size; i++)
        v->data[i-1] = v->data[i];
    v->size--;
}

void print_vector(Vector v) {
    printf("[");
    for (int i=0; i<v.size; i++) 
        printf("%d ", read(v, i));
    printf("]\n");
}
