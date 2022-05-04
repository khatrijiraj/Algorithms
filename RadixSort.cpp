#include <iostream>

#include "Countingsort.h"
using namespace std;
void radixSort(int A[], int size) {
    int k = findRange(A, size);
    for (int placeValue = 1; (k / placeValue) > 0; placeValue = placeValue * 10) {
        countingSort(A, size, placeValue);
    }
}

int main() {
    int k, n, A[20];
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "A[" << i << "] : ";
        cin >> A[i];
    }
    cout << "Array: ";
    display(A, n);
    radixSort(A, n);
    display(A, n);
    return 0;
}