#include <stdio.h>

/*
* Date due stringhe, scrivere una funzione che passi come parametri queste stringhe e le concateni.
* La concatenazione deve avvenire nella prima stringa, senza l'utilizzo di altre variabili di tipo array.
* La funzione dovrà sfruttare quanto visto con i puntatori per l'accesso in memoria (non usare S1[i]).
* Una volta fatto ciò, il programma deve stampare la stringa concatenata.
* 
* Per la consegna, utilizzare le seguenti stringhe:
* "laboratorio" e " programmazione"
* 
* Per la stampa usare:
* printf("Stringa concatenata: %s",S1);
*/


int main (void) {

	char S1[50] = "laboratorio",
	     S2[20] = " programmazione";

	//Inserite il vostro codice qua
	
	int len_s1 = 0;
	while (*(S1 + len_s1) != '\0') {
		len_s1++;
	}

	int len_s2 = 0;
	while (*(S2 + len_s2) != '\0') {
		len_s2++;
	}

	for (int i = 0; i - 1 < len_s2; i++) {
		*(S1 + len_s1 + i) = *(S2 + i);
	}

	printf("Stringa concatenata: %s",S1);

	return 0;
}
