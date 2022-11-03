#include <stdio.h>
#define righe 3
#define colonne 2

/*
* Scrivete un programma che calcoli la trasposta di una matrice generica.
*
* L'operazione consiste nello scambiare le righe con le colonne.
*
* Esempio:
* |a b c| ____ |a d|
* |d e f|      |b e|
*              |c f|
*
* Per la consegna, utilizzare:
*
* Utilizzare il seguente codice per stampare il risultato:
* 
*/

int main (void) {

	int matrice[righe][colonne] = {{1,2},{3,4},{5,6}};
	int matRisultato[colonne][righe];

	for (int i = 0; i < colonne; i++) {
		for (int j = 0; j < righe; j++) {
			matRisultato [i][j] = matrice[j][i];
		}
	}


	for (int i = 0; i < colonne; i += 1){
		for (int j = 0; j < righe; j += 1){
			printf("%d ", matRisultato[i][j]); 
		}
		printf("\n");
	}
}
