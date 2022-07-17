#include <stdio.h>

void stampaHeader();
void trovaChiave(int *key);
void code(int key);
int stringToInt();
void mostraOpzioni();
void indicaOpzione(int *option);


int main(void) {
  int key = 0;                  // chiave di codifica
  int option = 256;             // puntatore opzione del menu

  while (key == 0 && option != 4) {
    stampaHeader();

    printf("\nScegliere una delle seguenti opzioni:\n\n");
    printf("1) specificare la chiave di cifratura;\n\n");
    indicaOpzione(&option);

    if (option == 1) trovaChiave(&key);
  }

  while (option != 4) {

  // messaggio di benvenuto, bisogna avere l'impressione che permanga nel terminale
    stampaHeader();

    if (option == 1) trovaChiave(&key); //la chiave viene aggiornata

    else if (option == 2) {
      printf("\nInserire la frase da criptare: ");
      code(key);                // una frase viene criptata
    }
    else if (option == 3) {
      printf("\nInserire la frase da decriptare: ");
      code(-1 * key);           // una frase viene decriptata
    }
    else if (option != 256) printf("Comando non trovato, si prega di tentare nuovamente.\n");

    mostraOpzioni();            // è mostrato il menu
    indicaOpzione(&option);     // l'utente indica l'opzione
  }
}

void stampaHeader() {


	printf("\e[1;1H\e[2J");      // serve per pulire il terminale

  printf("   ---------------------\n");
  printf("   Benvenuto in CrittApp\n");
  printf("   ---------------------\n");
}

void trovaChiave(int *key) {
// PRE forniamo l'indirizzo di memoria in cui è salvata la variabile key
	*key = 0;

// PRE key==0
	while (*key == 0) {
		stampaHeader();             // il menu permane nella schermata
		printf("\nScegliere una nuova chiave di cifratura diversa da 0: ");

    *key = stringToInt();       // l'utente inserisce un valore
//    printf("%d\n", *key);     //utile per il debug
	}

// POST abbiamo cambiato l'r-valore di key nel main
}

int stringToInt() {
  char str[256]; scanf("%s", str); // chiediamo all'utente un'input
  int i = 0, n = 0;  // i: puntatore che ci orienta nella stringa; n: valore che ci interessa tornare
  if (*str == 45) i++;  // verifichiamo se il valore inserito è negativo

  for (; *(str + i) > 47 && *(str + i) < 58; i += 1) {
    n = n * 10 + *(str + i) - 48;  // convertiamo la stringa in int
  }
  if (*(str + i) != '\0') return 0;// se non era una stringa numerica ritorniamo 0
  else if (*str == 45) return n * (-1); // se il primo carattere è un meno moltiplichiamo per -1
  else return n;                   // torniamo il valore
}

void code(int key) {
	// PRE diamo key di input per indicare di quanto traslare una stringa

	// Le lettere dell'alfabeto sono 26, mentre le cifre sono 10.
	// Il minimo comune multiplo tra 26 e 10 è 130.
	// Al posto di traslare la stringa di k posizioni indietro la traslo di (k + m130)
	// posizioni in avanti, in questo modo è sufficiente controllare lo "overflow"

	char str[256]; scanf("%*c%[^\n]%*c", str); // l'utente fornisce la stringa

  key = key % 130 + 130;
  int i;                            // ci orienta all'interno della stringa

  for (i = 0; *(str + i) != '\0'; i += 1) {

	// se il carattere che trasliamo è una lettera minuscola entra qui dentro
    if (*(str + i) > 96 && *(str + i) < 123) {

		// dal momento che l'alfabeto ha 26 lettere, traslare per multipli di 26
		// corrisponde a non traslare affatto. Traslare di una posizione è come
		// traslare (1 + m * 26) posizioni e così via. Per questo motivo trasliamo
		// il carattere dell'alfabeto di (key % 26): è equivalente a traslare di
		// key posizioni
//      if (*(str + i) + key % 26 < 123) *(str + i) += key % 26;
      *(str + i) = (*(str + i) + key - 97) % 26 + 97;
		// se la lettera sfora il range di caratteri possibili allora viene
		// sottratto il numero 26, in modo che rietri
//      else *(str + i) += key % 26 - 26;
    }

	// se si tratta di una lettera maiuscola entra qui
    else if (*(str + i) > 64 && *(str + i) < 91) {

      *(str + i) = (*(str + i) + key - 65) % 26 + 65;
		// in questo caso vale il medesimo discorso proposto per le lettere minuscole
//      if (*(str + i) + key % 26 < 91) *(str + i) += key % 26;
//      else *(str + i) += key % 26 - 26;
    }

// se si tratta di un numero entra qui
    else if (*(str + i) > 47 && *(str + i) < 58) {

// dal momento che le cifre sono 10, traslare per multipli di 10 corrisponde
// a non traslare affatto. Traslare di una posizione è come traslare
// di (1 + m * 10) posizioni e così via. Per questo motivo trasliamo la cifra di
// (key % 10): è equivalente a traslare di key posizioni
//      if (*(str + i) + key % 26 < 58) *(str + i) += key % 10;

      *(str + i) = (*(str + i) + key + 48) % 26 + 48;
// se la cifra sfora il range di caratteri possibili allora viene sottratto il
// numero 10, in modo che rientri
//      else *(str + i) += key % 10 - 10;
    }
  }

// infine viene restituita la stringa, traslata secondo il cifrario di cesare,
// nel terminale (a questo punto la stringa viene cancellata dalla ram)
  printf("\nDi seguito è riportato il risultato: %s\n", str);
}

void mostraOpzioni() {
// PRE forniamo l'indirizzo di memoria in cui è salvata la variabile option

// mostriamo il menu nel terminale
  printf("\nScegliere una delle seguenti opzioni:\n\n");
  printf("1) specificare la chiave di cifratura;\n\n");
  printf("2) codifica un messaggio;\n\n");
  printf("3) decodifica un messaggio\n\n");
  printf("4) esci\n\n");
}

void indicaOpzione(int *option) {
// PRE forniamo l'indirizzo di memoria in cui è salvata la variabile option

    printf("Indicare l'opzione: ");
    
  *option = 256;                      // settiamo  option a 0
  while (*option == 256) {
    *option = stringToInt(); // l'utente inserisce un valore che noi convertiamo in int
  }
// POST option ha un valore
}
