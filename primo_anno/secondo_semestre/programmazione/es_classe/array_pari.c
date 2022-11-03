#include <stdio.h>

int array_pari(int X[], int dim);

main() {
    int numeri[10];
    for (int i= 0; i< 10; i++) {
        scanf("%d", (numeri + i));
    }
    int x; scanf("%d", &numeri);

    int presente= array_pari(numeri, 10);

    printf(presente== 1? "L'array è pari": "L'array non è pari");
}

int array_pari(int X[], int dim) {
    if (dim == 0) return 1;
    else if (X[0] % 2== 0) return array_pari(X+1, dim-1);
    else return 0;
}