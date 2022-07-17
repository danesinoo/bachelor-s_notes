typedef struct nodo{
    int info;
    struct nodo *next;
} Lista;

void print_list(Lista*); //stampa il contenuto della lista
Lista* init(int data, Lista* next); //crea una lista con un nuovo nodo iniziale con campo info uguale a data e collegata in testa ad una lista next (next può essere anche NULL)
int read(Lista*, unsigned int);
void insert_element(Lista**, int, unsigned int);
void delete_element(Lista**, unsigned int);
unsigned int size(Lista*);
