#include <stdio.h>

/*
 * Scrivete un programma che definisca una costante ALTEZZA=x e disegni un triangolo rettangolo di base ed 
 * altezza x, utilizzando il carattere #. 
 * In particolare il programma stamperà # una volta per la prima riga, # due volte per la seconda riga, 
 * fino a stampare # x volte per la x-esima riga. 
 *
 * Per esempio se ALTEZZA=3 si ottiene il seguente output: 
 * #
 * ##
 * ###
 * 
 * Per la consegna utilizzare ALTEZZA=13
 */

int main(void) {

// indichiamo il numero di righe che compone la piramide
	const int ALTEZZA = 13;

// ciclo for, scrive una riga per ogni unità indicata dall'altezza del triangolo
	for (int riga = 0; riga < ALTEZZA; riga++) { 

// scrive le righe: la riga in cui ci troviamo ci indica il numero di # (figure)
// da stampare
		for (int figura = 0; figura < riga; figura++) {
			printf("#");
		}

// tra una riga e l'altra dobbiamo andare a capo
		printf("#\n");
	}
}
