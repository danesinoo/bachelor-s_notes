#include <stdio.h>

/* 
* Scrivere un programma che dato in input una stringa, verifichi con una funzione ricorsiva se è palindroma.
* Il programma deve poi stampare quanto trovato, utilizzare:
* if ( stringa_palindroma == 1)
*     printf("%s palindroma\n",S);
* else
*     printf("%s non palindroma\n",S);
*/

int lunghezza_stringa_ric(char *s) {
    if (*s == '\0') return 0;
    else return 1 +  lunghezza_stringa_ric(s + 1);
}

int stringaPalindroma(char *str, int len) {
//    printf("%c, %c\n", *str, *(str + len));
    if (str > str + len) return 0;
    else if (*str == *(str + len) && stringaPalindroma(str + 1, len - 2) == 0)
        return 0;
    else 
    return 1;
} 

int main(void) {
    char S[256];
    scanf("%s",S);
    int len = lunghezza_stringa_ric(S) - 1;

    int stringa_palindroma = stringaPalindroma(S, len);

    if (stringa_palindroma == 0)   printf("%s palindroma\n",S);
    else    printf("%s non palindroma\n",S);
    return 0;
}
