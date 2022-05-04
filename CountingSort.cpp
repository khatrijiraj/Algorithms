#include <iostream>

#include "Countingsort.h"
using namespace std;

int main() {
    int k, noOfElements, A[20];
    cout << "Enter the number of elements: ";
    cin >> noOfElements;
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < noOfElements; i++) {
        cout << "A[" << i << "] : ";
        cin >> A[i];
    }
    cout << "Input Array: ";
    display(A, noOfElements);
    countingSort(A, noOfElements, k);
    display(A, noOfElements);
    return 0;
}