#include <stdio.h>

int main(void) {

// inserisco il numero da cui cominciare a cercare
	int SOGLIA = 63;

// controllo se il numero è divisibile per 2, 3 e 5
	while (SOGLIA % 2 != 0 && SOGLIA % 3 != 0 && SOGLIA % 5 != 0) {

// aumento soglia di 1 qui perchè può darsi che la soglia stessa non sia divisibile per 2, 3 e 5
		SOGLIA += 1;
	}
	// stampo il valore non divisibile per 2, 3 e 5
	printf("%d\n", SOGLIA);
}
