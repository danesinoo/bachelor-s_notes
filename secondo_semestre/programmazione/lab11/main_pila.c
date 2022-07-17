#include "pila.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    Pila p;
    init(&p);

    print_pila(p);

    push(&p, 1);
    print_pila(p);

    push(&p, 2);
    print_pila(p);

    push(&p, 0);
    print_pila(p);

    push(&p, 3);
    print_pila(p);

    pop(&p);
    print_pila(p);

    int val = pop(&p);
    print_pila(p);

    printf("%d", val);
}
