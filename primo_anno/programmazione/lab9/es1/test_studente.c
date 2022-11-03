#include "studente.h"
#include <stdio.h>

int main(){
    Studente s;
    printf("Inserire dati studente:\n");
    scanf("%s %s", s.nome, s.cognome);
    printf("Inserire %d voti:\n", N_VOTI);
    for(int i=0; i<N_VOTI; i++){
        scanf("%d", s.voti + i);
    }
    print_studente(s);
    printf("Media: %f\n", calcola_media(s));
    if(sufficienza_studente(s)==1)
        printf("Sufficiente\n");
    else printf("Non sufficiente\n");
}