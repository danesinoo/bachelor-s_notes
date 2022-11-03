#include<stdio.h>

/* Date due stringhe N e T, trovare la posizione del primo match di T in N.
 * Trovare un match significa trovare una sottosequenza di caratteri adiacenti in N uguali a T.
 * (ovvero una *(N+k)==*T, *(N+(k+1))==*(T+1), ..., *(N+(k+n))==*(T+n) dove n è (la lunghezza di T)-$
 * La posizione del match è uguale a quella del primo carattere matchato in N.
 * ES: N="programmazione2022", T="gra" -> "Match found at position 3"
 * ES: N="programmazione2020", T="ez" -> "No match found"
*/

unsigned int len(char* N) {
	unsigned len = 0;

// fino a che non viene trovato il carattere '\n' si fa len += 1
// in sostanza ritorna la lunghezza della stringa
	while (*(N + len) != '\0') {
		len++;
	}
	return len;
}

int main(){
    /* Nota:
     * 256 è la dimensione massima della stringa ma il numero di caratteri può essere inferiore
     * implementare una funzione len per misurare la lunghezza di una stringa
     * (contare quanti caratteri ci sono prima del delimiter "\0")
     */
    char N[256];
    char T[256];

    scanf("%255s", N);
    scanf("%255s", T);

    int N_len = len(N), T_len = len(T);

// tiene conto di quanti caratteri coincidono
	int flag = 0;

// ricorda l'indice fino a dove abbiamo cercato fino ad ora
	int pos = 0;

// eseguiamo un ciclo while fino a quando tutti i caratteri della stringa T non sono stati trovati
// di fila nella stringa N, oppure fino a quando nella stringa N restano meno caratteri da controllare
// della lunghezza della stringa T
	while (flag < len(T) && N_len - pos + 1 > T_len ) {
	
// se i due caratteri coincidono allora incremmentiamo flag di 1, per cui testiamo il secondo carattere di fila
// altrimenti si ricomincia "da capo"
		if (N[pos + flag] == T[flag]) flag++;
		else {
			pos++;
			flag = 0;
		}
	}
// se flag alla fine di tutto è uguale a 0, allora vuol dire che non c'è nessun match
	if (flag == 0) printf("No match found\n");
	else printf("Match found at position %d\n", pos);
}

