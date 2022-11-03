#include <stdio.h>
#include <stdlib.h>
#include "test_board.c"
#include "test_giocatore.c"


int main(int argc, char *argv[]) {

    srand(1);

    printf("--Start Tests--\n\n");
    test_scegli_mossa_computer();
    test_mossa_ammissibile();
    test_tris_in_colonna();
    test_tris_in_diagonali();

    printf("\nTutti i test passati con successo!\n");
    printf("\n--End Tests--\n");

}
