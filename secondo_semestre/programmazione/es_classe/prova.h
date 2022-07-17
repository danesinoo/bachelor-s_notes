void filter(int *, unsigned int *, int);
void trasla(int *arr, unsigned int);

void filter(int *arr, unsigned int *len, int lmnt) {
    for (int i = 0; i < *len; i++) {
        if (*(arr + i) == lmnt) {
            *len -= 1;
            trasla(arr +i, *len -i);
        }
    }
}

void trasla(int *arr, unsigned int len) {
    for (int i= 0; i < len; i++) {
        arr[i] = arr[i +1];
    }
}
