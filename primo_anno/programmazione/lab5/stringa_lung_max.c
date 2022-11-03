#include <stdio.h>

/*
 * Scrivere una funzione che, dato un array di stringhe,
 * restituisca la stringa di lunghezza massima. 
 * Nel main si dovrà stampare tale stringa.
 * Inoltre, si tratti in modo appropriato il caso in cui
 * il numero di stringhe nell'array sia zero. In particolare,
 * nel main si stampi "array vuoto\n". Se il numero di 
 * stringhe è maggiore di zero, utilizzare il seguente comando
 * nel main per la stampa della stringa più lunga:
 * 
 * printf("%s\n", stringa_lung_max(stringhe, num_stringhe));
 * 
 * Il numero di stringhe e le stringhe stesse sono lette da 
 * tastiera. 
 * 
 */

int len(char *s) {
    if (*s == '\0') return 0;
    else return 1 +  len(s + 1);
}

char *len_max(char *stringhe, int num_stringhe) {
    if (num_stringhe == 1) return stringhe;
    if (len(stringhe) > len(len_max(stringhe + 256, num_stringhe - 1)))
        return stringhe;
    else
        return len_max(stringhe + 256, num_stringhe - 1);
}

int main(void) {

    int num_stringhe;
    scanf("%d", &num_stringhe);

    char stringhe[num_stringhe][256];
    for(int i=0; i<num_stringhe;i+=1) {
        scanf("%255s", stringhe[i]);
    }

    char *s_max = len_max(stringhe, num_stringhe);
    printf("%s\n", (s_max==NULL)?"array vuoto": s_max);
}