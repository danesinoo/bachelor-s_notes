#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

void print_list(Lista* node) {
    printf("[");
    while (node->next != NULL) {
        printf("%d, ", node->info);
        node = node->next;
    }
    printf("%d]\n", node->info);
}

Lista* init(int data, Lista* next) {
    Lista *new = malloc(sizeof(Lista));
    new->info = data;
    new->next = next;
    return new;
}

int read(Lista* lst, unsigned int pos) {
    if (pos == 0) 
        return lst->info;
    if (lst->next == NULL)
        return __INT_MAX__;
    return read(lst->next, pos -1);
}

void insert_element(Lista** lst, int elem, unsigned int pos) {
    if (pos == 0) {
        *lst = init(elem, (*lst)->next);
    }
    else {
        Lista *sup = *lst;
        for (int i = 0; i< pos -1; i++) 
            sup = sup->next;
        sup->next = init(elem, sup->next);
    }
}

void delete_element(Lista** lst, unsigned int pos) {
    if (pos == 0) {
        Lista *sup= *lst;
        (*lst) = (*lst)->next;
        free(sup);
    }
    else {
        for (int i=0; i<pos-1; i++)
            lst = &(*lst)->next;
        Lista* node= (*lst)->next->next;
        free((*lst)->next);
        (*lst)->next= node;
    }
}

unsigned int size(Lista* lst) {
    if (lst->next != NULL)
        return 1 + size(lst->next);
    return 1;
}