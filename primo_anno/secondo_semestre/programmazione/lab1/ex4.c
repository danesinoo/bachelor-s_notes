#include <stdio.h>
/*
 * Data la costante LIMIT, stampare la serie di 
 * fibonacci, fib(k), a partire da fib(0) fino al
 * valore fib(k) più grande t.c. fib(k) < LIMIT.
 * 
 * La funzione di Fibonacci è definita per casi:
 * 
 * fib(0) = 0
 * fib(1) = 1
 * fib(i) = fib(i-1) + fib(i-2)
 * 
 * Es. se LIMIT = 25 stampa
 * 0
 * 1
 * 1
 * 2
 * 3
 * 5
 * 8
 * 13
 * 21
 * 
 * Per la consegna assegnare LIMIT=56
 * 
 */

int main(void) {

// indico il limite sotto il quale dobbiamo tenerci
	const int LIMIT = 56;

// ho bisogno di 3 variabili per poter calcolare il numero di fibonacci successivo
	int f1 = 0;
	int f2 = 1;
	int f3 = 0;

// controllo che il numero che vado a stampare sia minore del limite, altrimenti
// disattivo il processo
	while ( f1<LIMIT ) {
		printf("%d\n",f1);

// calcolo il numero di fibonacci successivo
		f3 = f1 + f2;
 		f1 = f2;
		f2 = f3;
	}
}	
