#include "corso.h"
#include "stdio.h"

int conta_linee(FILE* fp);
//POST: conta il numero di entries nel file

void leggi_studente(FILE* fp, Studente* s);
//POST: legge da file i dati relativi ad un unico studente

void scrivi_studente(FILE* fp, Studente s);
//POST: scrive su file i dati di un unico studente