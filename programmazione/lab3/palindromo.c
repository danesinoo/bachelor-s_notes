#include<stdio.h>

/*
 * Dato un array di interi di lunghezza N, scrivere un programma che stampa
 * "Array palindromo" se l'array è palindromo o "Array non palindromo" se non lo è.
 * Un array è definito palindromo se invertendolo rimane uguale (es. [1, 2, 3, 2, 1] è palindromo)
 * 
 * Per questa l'implementazione ci rifaremo letteralmente alla
 * la definizione sopra: creeremo una funzione che 
 * inverte un array ed una che confronta due array. 
 * Realizzate le due funzioni secondo i prototipi forniti
 * ed infine usatele all'interno di una funzione 
 * palindromo che realizzi la consegna. 
 */

int confronta_array(int *X, int *Y, int dim);
void inverti(int *A, int dim);
int palindromo(int array[], int n);


int main(){
    int N;
    //leggere da input grandezza array
    scanf("%d", &N);

    int array[N];

    //leggere da input dati array
    for(int i = 0; i < N; i++){
        scanf("%d", array+i);
    }

    if(palindromo(array, N) == 1){
        printf("Array palindromo\n");
    } else printf("Array non palindromo\n");
    
}

int confronta_array(int *X, int *Y, int dim) {
	int i = 0;

// confronto gli elementi i-esimi dei due array
// e sto attento di non andare oltre la dimensione dell'array
	while (*(X + i) == *(Y+i) && i < dim) {

// aggiorno i per controllare l'elemento successivo
		i++;
	}

// se while non si è interrotto precocemente allora i è uguale 
// a dim e i due termini si annullano; altrimenti dim - i è
// diverso da 0 e allora viene tornato un valore diverso da 1
	return dim - i + 1;
}

void inverti(int *A, int dim) {

// dichiaro tmp per scambiare i valori
	int tmp;

// se non lo facessi solo in dim / 2 invertirei l'ordine due volte, quindi non lo invertirei
	for (int i = 0; i < dim / 2; i++) {

// sfruttando tmp inverto le posizione dell'oggetto nella posizione i con l'oggetto
// corrispondente partendo dal fondo
		tmp = *(A + i);
		*(A + i) = *(A + dim - i - 1);
		*(A + dim - i - 1) = tmp;
	}
}

int palindromo(int array[], int n) {

// mi divido in due casi, che n sia pari o dispari

// se n è pari allora giro la seconda metà dell'array con inverti come se fosse un array a parte
// e poi confronto le due metà dell'array come se fossero array diversi
	if (n % 2 == 0) {
		inverti(array + n/2, n/2);
		return confronta_array(array, array + n/2, n/2);
	}

// se n è pari allora non mi importa considerare l'elemento che ha indice n/2 + 1
// quindi inverto la seconda metà di array a partire dal successivo di n/2 + 1
// e poi confronto le metà da n/2 + 1 in giù con quella n/2 + 1 in su, senza considerare n/2 + 1

// inverti ritorna 1 se le due metà sono uguali
	else {
		inverti(array + n/2 + 1, n/2);
		return confronta_array(array, array + n/2 + 1, n/2);
	}
}
