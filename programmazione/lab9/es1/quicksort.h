/*
 * Implementare l'algoritmo di quick sort per ordinare un array di interi.
 * 
 * Quick Sort è un algoritmo divide-et-impera che divide iterativamente
 * l'array di input in due sottoarray rispetto ad un elemento detto pivot, 
 * per esempio l'ultimo elemento dell'array. Tale procedura ricorsiva 
 * viene chiamata partition: scelto il pivot si pongono a sinistra tutti 
 * gli elementi minori e a destra tutti i maggiori formando così i due 
 * sottoarray. Si noti che al termine di partition pivot sarà nella 
 * corretta posizione nell'array (ovvero nella posizione che assumerà 
 * quando l'array è completamente ordinato). 
 * L'operazione viene reiterata ricorsivamente sui sottoarray destro e 
 * sinistro fino all'ordinamento completo. 
 * 
 */


void quickSort(int A[], int low, int high);
    /*
     * Implementazione dell'algoritmo QuickSort. 
     * low e high sono rispettivamente l' indice 
     * più piccolo e più grande in A tra i quali effettuare l'ordinamento. 
     * 
     * PRE: A array di N interi, 0 <= low <= high < N
     * POST: A è ordinato in modo crescente
     */
void trasla(int* arr, int* copia, int j, int high, int salto);
    
