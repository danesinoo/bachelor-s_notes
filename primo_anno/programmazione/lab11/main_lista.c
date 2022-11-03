#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    Lista *lista = init(1, NULL);
    print_list(lista);

    insert_element(&lista, 2, 1);
    print_list(lista);

    insert_element(&lista, 0, 0);
    print_list(lista);

    insert_element(&lista, 3, 2);
    print_list(lista);

    delete_element(&lista, 2);
    print_list(lista);

    delete_element(&lista, 0);
    print_list(lista);

    printf("%d", read(lista, 1));
}
