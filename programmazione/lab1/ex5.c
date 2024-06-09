/*
 * Stampare una piramide rovesciata utilizzando il carattere #,  
 * in modo che la punta della piramide sia in basso e la base in alto. 
 * Per esempio se ALTEZZA=3 si ottiene il seguente output: 
 * 
 * #####
 *  ###
 *   #
 * 
 * Per la consegna utilizzare ALTEZZA=6
 * 
 */
#include <stdio.h>

int main (void) {

// indico il numero delle righe totali della figura:
	const int h = 6;

// ciclo for per ogni riga:
	for (int righe = 0; righe < h; righe += 1) { 

// la prima non ha spazi, ogni riga successiva ha uno spazio aggiuntivo rispetto alla precedente
// dunque introduco un ciclo for che per la prima riga viene saltato e poi a seconda della riga in
// in cui ci troviamo stampa il numero necessario di spazi
		for (int spazio = 0; spazio < righe; spazio += 1) {
			printf(" ");	
		}	

// ogni riga è composta da 2*(n umero righe totali - riga in cui ci troviamo)-1 # (figura)
// per cui in base alla riga in cui ci troviamo stampo il numero adeguato di # in successione
		for (int figura = 0; figura < 2 * (h - righe) - 1; figura += 1) {
			printf("#");
		}
// dal momento che a destre della piramide non devo stampare nulla il doppio ciclo ricomicia
// dopo essere andati a capo:
		printf("\n");
	}
}
