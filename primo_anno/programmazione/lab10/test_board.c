#include <stdio.h>
#include <assert.h>
#include "board.h"


void test_mossa_ammissibile() {

    char board[] = {SIMB_X, CASELLA_VUOTA, SIMB_O, 
                    CASELLA_VUOTA, CASELLA_VUOTA, SIMB_O,
                    CASELLA_VUOTA, SIMB_X, CASELLA_VUOTA};

    assert(mossa_ammissibile(board, 0, -1)==0);
    assert(mossa_ammissibile(board, 0, 0)==0);
    assert(mossa_ammissibile(board, 0, 1)==1);
    assert(mossa_ammissibile(board, BOARD_LATO, 1)==0);
    assert(mossa_ammissibile(board, 0, BOARD_LATO)==0);
    assert(mossa_ammissibile(board, BOARD_LATO, BOARD_LATO)==0);
    printf("mossa_ammissibile(): test passato con successo\n");
}


void test_tris_in_colonna() {

    char board[] = {SIMB_X,  CASELLA_VUOTA, SIMB_O, 
                    SIMB_X,  CASELLA_VUOTA, SIMB_O,
                    SIMB_X,  SIMB_X,        CASELLA_VUOTA};
    
    assert(tris_in_colonna(board, 1)==0);
    assert(tris_in_colonna(board, 0)==1);

    printf("tris_in_colonna(): test passato con successo\n");
}


void test_tris_in_diagonali() {

    char board[] = {SIMB_X,  CASELLA_VUOTA, SIMB_O, 
                    SIMB_X,  CASELLA_VUOTA, SIMB_O,
                    SIMB_X,  SIMB_X,        CASELLA_VUOTA};

    assert(tris_in_diagonali(board)==0);
    printf("tris_in_colonna(): test passato con successo\n");

}

