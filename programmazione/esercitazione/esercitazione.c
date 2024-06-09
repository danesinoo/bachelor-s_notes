#include <stdio.h>

void benvenuto();
void inserisciChiave(int *chiave);
void cripta(int chiave);
int stringToInt();
void menu();
void inserisciOpzione(int *opzione);

int main(void)
{
  int chiave = 0;    // chiave di codifica
  int opzione = 256; // puntatore opzioni del menu

  while (opzione != 4)
  {
    // PRE opzione = 0

    // nei vari cicli l'utente cambia l'opzione ed interagisce con il programma
    benvenuto(); // stampa il benvenuto sul terminale

    if (opzione == 1)
      inserisciChiave(&chiave); // la chiave viene aggiornata

    else if (opzione == 2 && chiave != 0)
    { // controlla l'opzione e la chiave
      printf("\nInserire la frase da criptare: ");
      cripta(chiave); // una frase viene criptata
    }
    else if (opzione == 3 && chiave != 0)
    { // controlla l'opzione e la chiave
      printf("\nInserire la frase da decriptare: ");
      cripta(-1 * chiave); // una frase viene decriptata
    }
    else if (opzione == 2 || opzione == 3 && chiave == 0)
    { // se la chiave è 0 spiega all'utente l'errore
      printf("\nNon è stata inserita alcuna chiave, si prega di inserire una chiave prima di proseguire.\n");
    }
    else if (opzione != 256)
      printf("\nComando non trovato, si prega di tentare nuovamente.\n");

    menu();                     // è mostrato il menu
    inserisciOpzione(&opzione); // l'utente indica l'opzione
  }
}

void benvenuto()
{
  printf("\e[1;1H\e[2J"); // serve per pulire il terminale
  printf("   ---------------------\n");
  printf("   Benvenuto in CrittApp\n");
  printf("   ---------------------\n");
}

void inserisciChiave(int *chiave)
{
  // PRE forniamo l'indirizzo di memoria in cui è salvata la variabile chiave
  *chiave = 0; // settiamo la chiave a 0 per poterla modificare

  // PRE chiave==0
  while (*chiave == 0)
  {
    benvenuto(); // il menu permane nella schermata
    printf("\nScegliere una nuova chiave di cifratura diversa da 0: ");
    *chiave = stringToInt(); // l'utente inserisce un valore
//    printf("%d\n", *chiave);       // utile per il debug
  }
  // POST abbiamo cambiato l'r-valore di chiave nel main
}

int stringToInt()
{
  char str[256];
  scanf("%s", str); // chiediamo all'utente una stringa
  int i = 0, n = 0; // i: puntatore che ci orienta nella stringa; n: valore che ci interessa tornare
  if (*str == 45)
    i++; // verifichiamo se il valore inserito è negativo

  for (; *(str + i) > 47 && *(str + i) < 58; i += 1)
  {
    n = n * 10 + *(str + i) - 48; // convertiamo la stringa in int
  }
  if (*(str + i) != '\0')
    return 0; // se non era una stringa numerica ritorniamo 0
  else if (*str == 45)
    return n * (-1); // se il primo carattere è un meno moltiplichiamo per -1
  else
    return n; // torniamo il valore
}

void cripta(int chiave)
{
  // PRE diamo chiave di input per indicare di quanto traslare una stringa

  char str[256];
  scanf("%*c%[^\n]%*c", str); // l'utente fornisce la stringa
//(utilizzo "%*c%[^\n]%*c" al posto di "%s" per risolvere problematiche relative agli spazi e intriseche a scanf)

  chiave = chiave % 130 + 130; // trasformiamo k in un valore positivo per semplicità (se chiave è già positivo non cambia nulla)

  /* Il funzionamento è il seguente: se trasliamo una lettera di 26 posizioni
   * è come se non la traslassimo. Se trasliamo una lettera per un multiplo di 26
   * posizioni allo stesso modo è come se non traslassimo affatto. Ora prendiamo
   * il caso dei numeri: avendo una qualunque cifra se trasliamo di 10 posizioni
   * è come se non traslassimo, allo stesso modo se trasliamo di un multiplo di 10
   * è come se non traslassimo affatto. Allora se trasliamo di mcm(10, 26)= 130
   * posizioni è come se non traslassimo affatto. In sostanza possiamo aggiungere
   * o togliere 130 a qualunque chiave ed è come se non avessimo fatto nulla.
   * Per questo motivo modulo (%) 130 equivale a non fare nulla, ma il numero
   * ottenuto sarà compreso tra -129 e 129 (-129 < x < 129). Se a questo numero
   * aggiungo 130 allora ottengo un numero compreso tra 1 e 259 (1 < x < 259).
   * In particolare il numero ottenuto è sempre positivo ed equivalente alla
   * chiave iniziale.
   */

  int i; // ci orienta all'interno della stringa

  for (i = 0; *(str + i) != '\0'; i += 1)
  { // scorriamo la stringa
    // PRE abbiamo una stringa, i==0

    // INV tecnicamente non c'è un'invariante, ma str[j] è traslata per ogni i>j

    if (*(str + i) > 96 && *(str + i) < 123)
    {                                                    // lettere minuscole
      *(str + i) = (*(str + i) + chiave - 97) % 26 + 97; // shiftiamo
    }
    else if (*(str + i) > 64 && *(str + i) < 91)
    { // lettere maiuscole
      *(str + i) = (*(str + i) + chiave - 65) % 26 + 65;
    }
    else if (*(str + i) > 47 && *(str + i) < 58)
    { // numeri
      *(str + i) = (*(str + i) + chiave - 48) % 10 + 48;
    }
  }
  // POST i caratteri alfanumerici dell'array str viene traslato in avanti

  printf("\nDi seguito è riportato il risultato: %s\n", str); // restituiamo la stringa
}

void menu()
{ // mostriamo il menu nel terminale
  printf("\nScegliere una delle seguenti opzioni:\n\n");
  printf("1) specificare la chiave di cifratura;\n\n");
  printf("2) codifica un messaggio;\n\n");
  printf("3) decodifica un messaggio\n\n");
  printf("4) esci\n\n");
  printf("Indicare l'opzione: ");
}

void inserisciOpzione(int *opzione)
{
  // PRE forniamo l'indirizzo di memoria in cui è salvata la variabile opzione

  *opzione = 256; // settiamo  opzione a 256
  while (*opzione == 256)
  {
    *opzione = stringToInt(); // l'utente inserisce un valore che noi convertiamo in int
  }
  // POST opzione ha un valore, che sia 0 o un numero
}