#include <stdio.h>
#include "parser.h"

int main(){
    FILE *fp;
    fp = fopen("studenti.txt","r");
    if (fp==NULL){
        printf("Il file non può essere aperto\n");
    }
    else {
        //lettura file qui
        
        fclose(fp);
        printf("File letto\n");

        //ordinamento

        //scrittura file qui

        fclose(fp);
    }
}