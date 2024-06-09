#include <stdio.h>

// somma dei numeri pari minori di n

int main() {
	
// indico n
	const int n = 13;
	int somma = 0;
	
// partendo da 2 sommo i numeri pari, che vanno di due in due
	for (int i = 2; i < n; i  += 2) {
		somma += i;
	}
	
// dopo aver calcolato la somma la ritorno
	printf("La somma dei numeri pari minori di %d è %d\n", n, somma);
}
