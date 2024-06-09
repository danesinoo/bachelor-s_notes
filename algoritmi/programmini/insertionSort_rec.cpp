#include <iostream>

void printArray(int[], int);
void insertionSort(int[], int);
int &count(int[], int, int);

int main(void) {
  int A[10];
  for (int i = 0; i < 10; i++)
    A[9 - i] = i;

  printArray(A, 10);
  insertionSort(A, 10);
  printArray(A, 10);
}

void insertionSort(int A[], int size) {
  if (size-- > 1) {
    insertionSort(A, size);
    int i = 0;
    int tmp = A[size];
    count(A, size - 1, tmp) = tmp;
  }
}

int &count(int A[], int size, int tmp) {
  if (size < 0)
    return A[0];
  else if (tmp >= A[size])
    return A[size];
  A[size + 1] = A[size];
  return count(A, size - 1, tmp);
}

void printArray(int A[], int size) {
  for (int i = 0; i < size; i++)
    std::cout << A[i] << " ";
  std::cout << std::endl;
}
