#include <stdio.h>

int trova_elemento(int X[], int dim, int elem);

main() {
    int numeri[10];
    for (int i= 0; i< 10; i++) {
        scanf("%d", (numeri + i));
    }
    int x; scanf("%d", &numeri);

    int presente= trova_elemento(numeri, 10, x);

    printf(presente== 1? "Il numero %d è presente", x: "Il numero non è presente");
}

int trova_elemento(int X[], int dim, int elem) {
    if (dim == 0) return 0;
    else if (X[0] == elem) return 1;
    else return trova_elemento(X+1, dim -1, elem);
}