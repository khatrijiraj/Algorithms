#include <iostream>
using namespace std;

int findRange(int array[], int size) {
    int maximum = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > maximum) {
            maximum = array[i];
        }
    }
    return maximum;
}

void countingSort(int A[], int size, int k) {
    k = findRange(A, size);
    int B[20], C[20];
    for (int i = 0; i <= k; i++) {
        C[i] = 0;
    }
    for (int j = 0; j < size; j++) {
        C[A[j]] = C[A[j]] + 1;
    }
    for (int i = 1; i <= k; i++) {
        C[i] = C[i] + C[i - 1];
    }
    for (int j = size - 1; j >= 0; j--) {
        B[C[A[j]] - 1] = A[j];
        C[A[j]] = C[A[j]] - 1;
    }
    for (int i = 0; i < size; i++) {
        A[i] = B[i];
    }
}

void display(int array[], int size) {
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}