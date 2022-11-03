#include <stdio.h>

/*
 * Stampare l'insieme dei divisori non banali 
 * di un numero x>0. Un divisore non banale è 
 * un divisore diverso da 1 e x. 
 * Inoltre, se x è primo, stampare 
 * "il numero x è primo".
 * 
 * Es. se x=5 stampa
 * Il numero 5 è primo
 * 
 * Es. se x=6 stampa
 * Il numero 6 è divisibile per 2
 * Il numero 6 è divisibile per 3
 * 
 * Per la consegna utilizzare x=63
 * 
 */

int main(void) {

// inserisco il numero di cui voglio conoscere i divisori
	const int x = 84;

// questo valore mi permette di capire se il numero è primo o meno
	int primo = 0;

// per ogni numero tra 2 e radice quadrata di di x controllo se è un divisore
// non controllo l'1: divisore banale, non esistono divisori interi di x superiori a x / 2  
	for (int i = 2; i < x + 1 / 2; i++) {
		if ( x % i == 0 ) {

// per definizione se il resto della divisione tra x e un numero i è 0, allora x è divisibile per i
// dunque stampo il numero che si rivela essere un divisore di x
			printf("Il numero %d è divisibile per %d\n", x, i);

// quando viene trovato un divisore primo viene incrementato di 1
			primo += 1;
		}
	}

// se primo non è mai stato incrementato, allora x non ha divisori interi
	if (primo == 0) printf("il numero %d è primo\n", x);
}
