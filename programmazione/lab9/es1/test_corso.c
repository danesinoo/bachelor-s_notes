#include "corso.h"
#include <stdio.h>

int main(){
    Studente s[2]={
        {"Enrico" ,"Cancelli", {21,23,18,29,30}},
        {"Gennaro","Bullo"   , {18,16,22,18,2}}
    };

    printf("Miglior Studente:\n");
    print_studente(miglior_studente(s, 2));
    for(int i=0; i<N_VOTI; i++){
        printf("Percentuale superamento corso %d: %f\n", i, percentuale_superamento_test(s, 2, i)*100);
    }
}