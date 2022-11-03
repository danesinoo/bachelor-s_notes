#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    Vector v;
    init(&v);

    print_vector(v);

    insert_element(&v, 1, 0);
    print_vector(v);

    insert_element(&v, 2, 1);
    print_vector(v);

    insert_element(&v, 0, 0);
    print_vector(v);

    insert_element(&v, 3, 2);
    print_vector(v);

    delete_element(&v, 2);
    print_vector(v);

    delete_element(&v, 0);
    print_vector(v);

    printf("%d", read(v, 1));
}
