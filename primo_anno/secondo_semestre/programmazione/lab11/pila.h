typedef struct
{
    unsigned int size;
    unsigned int capacity;
    int *data;
} Pila;

void print_pila(Pila);
void init(Pila*); //Inizializza pila con capacity 1 e senza nessun elemento
void push(Pila*, int elem); //push dell'elemento elem sulla pila
int pop(Pila*);