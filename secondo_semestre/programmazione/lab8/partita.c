#include "partita.h"
#include "board.h"
#include "giocatore.h"
#include <stdio.h>
#include <stdlib.h>

void gioca(char board[], void(*p1)(int *x, int *y), void(*p2)(int *x, int *y)) {
    int x, y, turno= rand() % 2;
    void (*arr[2])(int *, int *)= {p1, p2};
    char simboli[]= {'X', 'O'}; 
    int simbolo = 1;

    while (partita_terminata(board) == 0) {
        simbolo = (simbolo +1) % 2;
        turno = (turno +1) % 2;
        (*arr[turno])(&x, &y);
        while (effettua_mossa(board, x, y, simboli[simbolo]) == 0) {
            (*arr[turno])(&x, &y);
        }
        print_board(board);
    }
    
    if (board_vincente(board) == 1) {
        printf("Il giocatore %c ha vinto la partita\n", simboli[simbolo]);
    }
    else printf("La partita si è conclusa con un pareggio\n");
}