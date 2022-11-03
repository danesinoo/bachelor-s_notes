#include <stdio.h>

/*
 * Definire una funzione ricorsiva che determini 
 * se esiste un percorso che permetta di attraversare 
 * un campo fiorito, dal basso verso l'alto, 
 * senza calpestare alcun fiore. 
 * Il campo è rappresentato da una matrice, i cui valori
 * rappresentano la presenza di un fiore (0) oppure la sua
 * assenza (1).
 * E' possibile muoversi una casella in alto oppure una 
 * casella verso destra. 
 * Leggere le coordinate della casella di partenza 
 * da tastiera.  
 * Ad esempio se il campo è definito come segue: 
 * {0,0,0,1,0}
 * {0,1,0,1,1}
 * {1,0,1,1,0}
 * {1,0,1,1,1}
 * {1,0,1,0,0}
 * e la casella di partenza è (4,2), un percorso è il 
 * seguente: SU, SU, DESTRA, SU, SU (raffigurato dalle X) 
 * {0,0,0,X,0}
 * {0,1,0,X,1}
 * {1,0,X,X,0}
 * {1,0,X,1,1}
 * {1,0,X,0,0}
 */

int mossa(int dim_x, int dim_y, int *campo, int pos_x, int pos_y);

int main(void) {

    int campo[5][5]={
                         {0,0,0,1,0},
                         {0,1,0,1,1},
                         {1,0,1,1,0},
                         {1,0,1,1,1},
                         {1,0,1,0,0}
                    };
    int x,y;
    scanf("%d", &x);
    scanf("%d", &y);

    if (mossa(5, 5, &campo[0][0], x, y)==1) {
        printf("Esiste un percorso da %d,%d alla riga 0\n", x, y);
    } else {
        printf("Non esiste un percorso da %d,%d alla riga 0\n", x, y);
    } 
}

int mossa(int dim_x, int dim_y, int *campo, int pos_x, int pos_y) {
// PRE: insrisco la posizione di partenza e il campo di riferimento
// POST: se esiste un percorso andando solo SU o a DESTRA allora ritorna 1 altrimenti ritorna 0.

    if (pos_x == 0 && *(campo + pos_y) == 1) return 1;
    else if (*(campo + pos_x * 5 + pos_y) == 1) {
//        printf("%d, %d\n", pos_x, pos_y);     // per debug
        return mossa(dim_x, dim_y, campo, pos_x -1, pos_y);
    }
    else if  (*(campo + (pos_x+1) * 5 + pos_y + 1) == 1) {
//        printf("%d, %d\n", pos_x, pos_y);     // per debug
        return mossa(dim_x, dim_y, campo, pos_x, pos_y + 1);
    }
    else return 0;
}

/* ci sono 4 possibilità:
 * siamo nella prima riga, campo[0][x] e la cella vale 1 o 0, se vale 1 siamo
 * apposto, altrimenti proseguiamo con le condizioni;
 * 
 * siamo alla riga x, alla colonna y, verifichiamo se possiamo passare di cui,
 * se ce la facciamo andiamo SU
 * 
 * siamo alla riga x, alla colonna y, non possiamo stare dove siamo, allora
 * torniamo alla riga x+1 (GIU), ma ci spostiamo a destra. Se possiamo
 * spostarci a destra siamo apposto e andiamo DESTRA, SU
 * 
 * se non possiamo andare nè a DESTRA nè SU allora torniamo 0
 */ 