#include "salva.h"
#include "board.h"tpm
#include "giocatore.h"
#include "partita.h"
#include <stdlib.h>
#include <stdio.h>


void primo_salvataggio(char mod[]) {
    FILE *fp= fopen(".salva.dat", "wb+");
    char tmp = ' ';
    for (int i= 0; i<9; i++) 
        fwrite(&tmp, sizeof(tmp), 1, fp); // scrive la board
    tmp = '0';
    fwrite(&tmp, sizeof(tmp), 1, fp);     // scrive il turno
    tmp = (mod[3] == '1'? '0': '1');
    fwrite(&tmp, sizeof(tmp), 1, fp);     // scrive la modalità
    fclose(fp);
    char board[9];
    reset_board(board);
    if (mod[3] == '1')
        gioca(board, scegli_mossa_utente, scegli_mossa_utente, 0);
    else 
        gioca(board, scegli_mossa_utente, scegli_mossa_computer, 0);
}

void salva(int mossa_x, int mossa_y, int turno) {
    FILE *fp= fopen(".salva.dat", "rb+");
    fseek(fp, mossa_x * BOARD_LATO + mossa_y, SEEK_SET);
    char simbolo = turno == 0? SIMB_O : SIMB_X;
    fwrite(&simbolo, sizeof(char), 1, fp);
    fseek(fp, 9, SEEK_SET);
    simbolo = '0' + turno;
    printf("1- %d\n", simbolo);
    fwrite(&simbolo, sizeof(char), 1, fp);
    fclose(fp);
}

/*
void mostra_salvato() {
    FILE *fp= fopen(".salva.dat", "rb");
    char value;
    for (int i=0; i< 11; i++) {
        fread(&value, sizeof(char), 1, fp);
        printf("2- %d\n", value);
    }
    fclose(fp);
}
*/

int carica_partita() {
    FILE *fp = fopen(".salva.dat", "rb");
    char value;
    char board[9];
    for (int i=0; i<9; i++) {
        fread(&value, sizeof(char), 1, fp);
        board[i] = value;
    }
    fread(&value, sizeof(char), 1, fp);
    printf("%d\n", value);
    int turno = -48 + value;
    printf("%d\n", turno);
    fread(&value, sizeof(char), 1, fp);
    fclose(fp);
    if (value == '0') {
        gioca(board, scegli_mossa_utente, scegli_mossa_utente, turno);
        return 0;
    }
    gioca(board, scegli_mossa_utente, scegli_mossa_computer, turno);
    return 1;
}