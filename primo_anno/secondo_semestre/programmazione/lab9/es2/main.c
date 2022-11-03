#include <stdio.h>
#include "studenti_laureati.h"

int main(){
    FILE *fp;
    fp = fopen("studenti.txt","r");
    if (fp==NULL){
        printf("Il file non può essere aperto\n");
        return 1;
    }
//    int n_studenti = conta_linee(fp);
    int n_studenti = 7; // debug
    printf("righe: %d\n", n_studenti);  //debug
    Studente_extra studenti[n_studenti];
    for (int i= 0; i< n_studenti -1; i++) {
        leggi_studente(fp, studenti + i);
    }
    fclose(fp);

    // qui i dati vengono elaborati
    for (int i= 0; i< n_studenti -1; i++) {
        if (completato_percorso(studenti[i])) {
            float media = calcola_media(studenti[i]);
            studenti[i].voti[0] = -2;
            studenti[i].voti[1] = media;
            while (media > 1) media--;
            studenti[i].voti[2] = media * 100;  // tengo solo le prime due cifre
        }
    }

    // qui sono scritti
    fp = fopen("studenti_laureati.txt", "w+");
    for (int i= 0; i< n_studenti -1; i++) {
        scrivi_studente(fp, studenti[i]);
    }
    fclose(fp);
}