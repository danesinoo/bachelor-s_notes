#include <stdio.h>

/*
 * Enigmistica - Parole intrecciate. 
 * Scrivere una funzione che, data una tabella di caratteri
 * di dimensione 13x15 e una stringa, cerchi se la stringa
 * appare nella tabella: la stringa può apparire scritta:
 * 
 * 1) in orizzontale da sinistra a destra 
 * 2) in orizzontale da destra a sinistra
 * 
 * Se la word è presente nella tabella, restituire le sue
 * coordinate; se la word non
 * compare, utilizzare le coordinate -1,-1. 
 * Nel main utilizzare il seguente frammento di codice per 
 * stampare il risultato:
    // gli interi x,y contengono le coordinate,
    // dir è un intero che rappresenta la direzione del match (0 se è da sinistra a destra, 1 viceversa) 
    // word la word da cercare
    printf("word %s ", word);
    if (x != -1)
        printf("in (%d,%d), direzione %s\n", x, y, dir==0?"s->d":"d->s");
    else
        printf("non trovata\n");;
 * 
 * Ad esempio nella tabella fornita sotto, se
 * word_cercata = "Riposo"; allora stampa
    word Riposo in (1,0), direzione s->d
 * ATTENZIONE: le parole fornite possono avere sia lettere maiuscole che minuscole
 *             mentre la tabella contiene solo caratteri maiuscoli
 */

int confronto_destra(char *input, char *tabella);
int confronto_sinistra(char *input, char *tabella);
int len(char *str);

int main(void) {

    char tabella[13][16] = { 
        {"EISEOPIDLNOTETM"},
        {"RIPOSOTICUCBAOI"},
        {"ETROPSIVOOINMRL"},
        {"RSINNETIITGSFAA"},
        {"ROCKSPCNTOIOOLM"},
        {"OLAUOSSABLLIRLI"},
        {"CAMPINGZCBDAUYN"},
        {"BCOLLEZIONISMOA"},
        {"ALTIROCONLARCOB"},
        {"LAOIGGANIDRAIGM"},
        {"LIBGCINEMAIERLA"},
        {"OROTALIGUPORITS"},
        {"OTENOIZAMROFNIE"}
        };

    char word[256];     // input dell'utente

    scanf("%255s", word);

    int dir = -1;
    int i = 0;          // ci orienta nell'array

    word[0] = word[0] % 65 % 32 + 65;   // sono sicuro che word sia una lettera maiuscola
    while (i < 16 * 13 && dir == -1) {
// PRE
// POST
        if (word[0] == tabella[i / 16][i % 16]) {  
            dir = (i + len(word) > 208? -1 : confronto_destra(&word[1], &tabella[i/16][i%16+1]));
            if (dir != 0) {
                if (i > len(word)) dir = confronto_sinistra(&(word[1]), &(tabella[i/16][i%16-1]));
            }
            dir = (dir!= 0 && i>len(word)?confronto_sinistra(&(word[1]), &(tabella[i/16][i%16-1])):dir); 
        }
        i += 1;
    }

    int x = (i == 16 * 13 ? -1: (i-1) / 16);    // indico la riga
    int y = (i == 16 * 13 ? -1: (i-1) % 16);    // indico la colonna
    
    printf("Parola %s ", word);
    if (x != -1)
        printf("in (%d,%d), direzione %s\n", x, y, dir==0?"s->d":"d->s");
    else
        printf("non trovata\n");

}

int len(char *str) {
// PRE inserisco il puntatore ad una stringa

// INV len(str+1) è uguale al numero di caratteri che rimangono alla stringa per finire
    if (*str == '\0') return 0; // caso base
    else return 1 + len(str + 1);

// POST ritorno il numero di caratteri che compongono la stringa
}

int confronto_destra(char *input, char *tabella) {
// PRE inserisco le variabili parola e tabella
//INV e POST confronto_destra(..) vale 0 se la stringa coincide con la parola in tabella
//      altrimenti vale -1
    if (*input == '\0') return 0;   // caso base
    else if (*input % 65 % 32 + 65 == *tabella) return confronto_destra(input +1, tabella +1);
    else return -1;
}

int confronto_sinistra(char *input, char *tabella) {
// PRE inserisco le variabili paorla e tabella
// INV e POSR confronto_sinistra(..) vale 1 se la stringa coincide con la parola nella tabella
//      altrimenti vale -1
    if (*input == '\0') return 1;
    else if (*input % 65 % 32 + 65 == *tabella) return confronto_sinistra(input +1, tabella-1);
    else return -1;
}

/* soluzione:

// II metodo controlla contemporaneamente le due direzioni
    // se nessuna delle due direzioni va bene si passa alla riga successiva

    // se siamo andati oltre alle righe possibili allora restituiamo -1 -1

// implementazione: 

    // si cerca la prima lettra fino alla fine dell'array, se il carattere che trovaimo coincide con '\0' lo ignoriamo tanto le altre stringhe sono salvate di seguito. 

    // per confrontare i caratteri bisogna controllare il capslock la a coincide con 97, mentre la A con 65 (97 - 65 = 32), si fa char %65: un carattere che sia maiuscolo o minuscolo si trova tra 65 e 122 e 122 < 2 * 65 = 130. Poi si fa % 32. Le lettere dell'alfabeto sono 26, e 32 > 26, per cui otteniamo una base comune per le lettere maiuscole e per le lettere minuscole. Poi aggiungiamo 65 e otteniamo la lettera maiuscola, sempre.

    // ora comincia un ciclo while fino alla fine dell'array che effettua il confronto.
*/