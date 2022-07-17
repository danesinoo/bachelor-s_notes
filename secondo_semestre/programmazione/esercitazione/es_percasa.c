#include <stdio.h>

// un array multidimensionale, prima dimensione: le 10 cifre, seconda dimensione: frequenza di quella cifra.

// 1 metodo: si fa x%10, resta l'unità che noi confrontiamo con gli elementi nella prima dimensione dell'array, se il numero così estratto coincide con un numero dell'array allora aumentiamo la seconda dimensione collegata al valore

// 2 metodo: si divide un numero per dieci, fino a che il numero non è compreso tra 0 e 10. A questo punto si trasforma momentaneamente il numero e lo si confronta con gli elementi dell'array, a questo punto si aumenta la frequenza del match. WORK IN PROGRESS

// 3 metodo: prendo una stringa in input per risucire ad occuparmi di una cifra per volta, alla cifra in input sottraggo 48 e diventa un numero confrontabile con quelli dell'array

// 4 metodo: prendo una stringa come input per riuscire ad occuparmi di una cifra per volta. Chiamo una funzione ricorsiva che cerca il valore del puntatore che gli do all'interno dell'array multidimensionale e invoca se stessa sul prossimo valore della stringa. Si interrope quando trova '\0'

// III metodo
/*
int main() {
    int freq[10][2];
    for (int i = 0; i < 10; i++) {
        freq[i][0] = i; freq[i][1] = 0;
    }

    char numero[255]; scanf("%s", numero);

    for (int i = 0; numero[i] != '\0'; i++) {
        for (int j = 0; j < 10; j++) {
            if (numero[i] - 48 == freq[j][0]) freq[j][1] += 1;
        }
    }
    for (int i = 0; i < 10; i++) {
        printf("frequenza %d: %d\n", freq[i][0], freq[i][1]);
    }
}
*/

/* I metodo funziona solo per numeri piuttosto piccoli. Riguardo a questo punto preferisco il metodo III
int main() {
    int freq[10][2];
    for (int i = 0; i < 10; i++) {
        freq[i][0] = i;
        freq[i][1] = 0;
    }

    int numero; scanf("%d", &numero);

    for (int i = 0; numero != 0; i++) {
        for (int j = 0; j < 10; j++) {
            if (numero % 10 == freq[j][0]) {
                freq[j][1] += 1;
                numero = (numero - numero % 10) / 10;
            }
        }
    }
    for (int i = 0; i < 10; i++) {
        printf("frequenza %d: %d\n", freq[i][0], freq[i][1]);
    }
}
*/ 

/* II metodo, non comprendo come mai questa soluzione non funzioni;
int main() {
    int freq[10][2];
    for (int i = 0; i < 10; i++) {
        freq[i][0] = i; freq[i][1] = 0;
    }

    int numero; scanf("%d", &numero);
    double numero_con_virgola = (double) numero;

    while (numero_con_virgola < 10) {
        numero_con_virgola = numero_con_virgola / 10.0;
        printf("%f", numero_con_virgola);       // non arriva nemmeno qui
    }

    while (numero_con_virgola > 0) {
        int cifra = (int) numero_con_virgola;
        while (numero_con_virgola < 10) {
            numero_con_virgola -= 10;
        }
        for (int i = 0; i < 10; i++) {
            if (cifra == freq[i][0]) {
                freq[i][1] += 1;
                printf("%d\n", cifra);
            }
        }
    }

    for (int i = 0; i < 10; i++) {
        printf("frequenza %d: %d\n", freq[i][0], freq[i][1]);
    }
}
*/

// IV metodo, questo metodo è equivalente al III, ma il ciclo esterno è effettuato attraverso la tecnica della ricorsione
/*
void freqCifre(char *str, int *frequenza);
int main() {
    int freq[20];
    for (int i = 0; i < 20; i++) {
        freq[i] = (i%2 == 0 ? i/2 : 0); // i think the problem is right here, it's not
//        printf("%d, ", freq[i]);
    }

    char numero[255]; scanf("%s", numero);

    freqCifre(numero, freq);

    for (int i = 0; i < 20; i += 2) {
        printf("frequenza %d: %d\n", freq[i], freq[i+1]);
    }
}

void freqCifre(char *str, int *frequenza) {
    if (*str == '\0') {}
    else freqCifre((str + 1), frequenza);
    
    for (int i = 0; i < 20; i += 2){
        if (*str - 48 == *(frequenza + i)) *(frequenza + i + 1) += 1;
    }
}
*/