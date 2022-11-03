#include <stdio.h>
/* Troviamo il più piccolo numero non divisibile per 2, 3 e 5
** 
** Notiamo che 30 = 2 * 3 * 5, dunque individuaiamo le classi di congruenza di 30
** i moduli 1, 7, 11, 13, 17, 19, 23 e 29 sono nonnulli e non divisibili per 2, 3 e 5.
** ora bisogna individuare la classe del numero dato, e trovare la classe tra quello sopra
** indicate che è maggiore del numero dato ed è la più piccola possibile
*/

int main(void) {

// indichiamo il numero di partenza
	int SOGLIA = 4006;

// troviamo la sua classe
	int classe = SOGLIA % 30;

// identifichiamo la classe tra quelle sopra riportate, più vicina al numero dato
// strettamente maggiore di esso. Cambiamo il valore dato, in modo da restituirlo
	if (classe < 17) {
		if  (classe < 11) {
			if (classe < 7) {
				if (classe < 1) SOGLIA += 1;
				else SOGLIA += 7 - classe;
				}
			else SOGLIA += 11 - classe;
			}
		else if (classe < 13) SOGLIA += 13 - classe;
			
		else SOGLIA += 17 - classe;
	}
	else {	if (classe < 23) {
			if (classe < 19) SOGLIA += 19 - classe;
			else SOGLIA += 23 - classe;
			}
		else if (classe < 29) SOGLIA += 29 - classe;

		else SOGLIA += 2;
	}
	printf("%d\n", SOGLIA);
}
