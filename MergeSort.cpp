#include <iostream>
using namespace std;

int comparison = 0;
template <class M>
void Merge(M a[20], int left, int m, int right) {
    int i, j, k, n1, n2;
    n1 = m - left + 1;
    n2 = right - m;
    M L[n1], R[n2];

    for (i = 0; i < n1; i++) {
        L[i] = a[left + i];
    }

    for (j = 0; j < n2; j++) {
        R[j] = a[m + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        } else {
            a[k] = R[j];
            j++;
        }
        k++;
        comparison++;
    }

    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }
}

template <class M>
void MergeSort(M a[20], int left, int right) {
    int m;
    if (left < right) {
        m = (left + right) / 2;
        MergeSort(a, left, m);
        MergeSort(a, m + 1, right);

        Merge(a, left, m, right);
    }
}

int main() {
    int noOfElements, a[20];
    cout << "Enter the number of elements: ";
    cin >> noOfElements;
    for (int i = 0; i < noOfElements; i++) {
        cout << "Enter the element: ";
        cin >> a[i];
    }

    MergeSort(a, 0, noOfElements - 1);
    cout << "Sorted Array: ";
    for (int i = 0; i < noOfElements; i++) {
        cout << a[i] << " ";
    }
    cout << "\nComparison: " << comparison;

    return 0;
}