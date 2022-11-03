#include <iostream>

int dup(int A[], int size);
int dupCount(int& A[], int size, int [][]);
void aggiungi_elm(int *A, int curr_size, int a, int b);

int main(void) {
    // ...
}

// ritorna 1 se c'è almeno un doppione, altrimenti torna 0
int dup(const int A[], const int size) {
    for (int i=1; i<size; i++)
        for (int j=0; j<i; j++)
            if (A[i] == A[j]) 
                return 1;
    return 0;
}

int dupCount(const int& A[], const int size, int& *ret) {
    ret = new int[0][2];
    ret_size = 0;
    for (int i=1; i<size; i++) 
        for (int j=0; j<i; i++) 
            if (A[i] == A[j]) 
                aggiungi_elm(ret, ret_size, A[i], A[j]);
}

void  aggiungi_elm(int *A, int& curr_size, const int a, const int b) {
    A = realloc(A, ++ret_size); 
    A[curr_size -1][0] = a;
    A[curr_size-1][1] = b;
}

int dup_count(const int& A[], const int size) {
    unsigned int tmp= 0;
    for (int i=1; i<size; i++) 
        for (int j=0; j<i; j++) 
            if (A[i] == A[j])
                tmp++;
    return tmp;
}

int dup_num(const int& A[]
