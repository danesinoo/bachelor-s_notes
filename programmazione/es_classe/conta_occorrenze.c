#include <stdio.h>

int conta_occorenze(int X[], int dim, int elem);

main() {
    int numeri[10];
    for (int i= 0; i< 10; i++) {
        scanf("%d", (numeri + i));
    }
    int x; scanf("%d", &numeri);

    int presente= trova_elemento(numeri, 10, x);

    printf(presente== 1? "Il numero %d è presente", x: "Il numero non è presente");
}

int conta_occorenze(int X[], int dim, int elem) {
// POST restituisce il numero di volte per cui elem viene trovato in X[]
    if (dim == 0) return 0; // caso base: se non ci sono altri elementi nell'array  ritorna 0

    else if (X[0]== elem) return 1 + conta_occorrenze(X[1], dim -1, elem); // se X[0] == elem allora la frequenza dell'elemento nell'array è 1 + conta_occorenze(...) 
    else return conta_occorenze(X+1, dim -1, elem);
}