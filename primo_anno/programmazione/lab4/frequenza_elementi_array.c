#include <stdio.h>

/*
 * Scrivete un programma che dato un array di interi positivi, calcoli quante 
 * sono le occorrenze di ogni valore presente nell'array.
 * Notate che i valori dell'array, purché positivi, 
 * possono essere grandi a piacere. 
 * Il programma deve poi stampare quanto trovato, utilizzando il comando:
 * printf("il valore %d appare %d volte\n", A[i], freq[i]);
 * 
 * Per esempio se l'array è [1,1,2,3,1,2] si ottiene il seguente output:
 * il valore 1 appare 3 volte
 * il valore 2 appare 2 volte
 * il valore 3 appare 1 volte
 * 
 * Per la consegna usare l'array [2,5,6,2,7,6,6,7,7,7]
 * 
 */

int main () {
	int arr[10] = {2, 5, 6, 2, 7, 6, 6, 7, 7, 7};
	int len = sizeof(arr)/ sizeof(int);
	int pos = 0;
	int flag = 0;
	int freq[len][2];

	for (int i = 0; i < len; i++) {
		for (int j = 0; j < pos; j++) {
			if (arr[i] == freq[j][0]) {
				freq[j][1]++;
				flag++;
			}
		}
		if (flag == 0) {
			freq[pos][0] = arr[i];
			freq[pos][1] = 1;
			pos++;
		}
		flag = 0;
	}
	for (int i = 0; i < pos; i++) {
		printf("il valore %d appare %d volte\n", freq[i][0], freq[i][1]);
	}			 
}
