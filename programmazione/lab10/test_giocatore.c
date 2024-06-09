#include "giocatore.h"
#include "board.h"
#include <assert.h>
#include <stdio.h>


void test_scegli_mossa_computer(void) {

    int x,y;
    for(int i=0; i<1000; i+=1) {
        scegli_mossa_computer(&x, &y);
        assert((x>=0) && (x<BOARD_LATO));
        assert((y>=0) && (y<BOARD_LATO));
    }
    printf("scegli_mossa_computer(): test passato con successo\n");
}
