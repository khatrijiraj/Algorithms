#include <iostream>
using namespace std;

int count = 0;
int randomizedPartition(int A[20], int p, int r);
int partition(int A[20], int p, int r);
void QuickSort(int A[20], int p, int r);
void display(int A[20], int n);

int partition(int A[20], int p, int r) {
    int x, i, j;
    x = A[r];
    i = p - 1;
    for (j = p; j <= r - 1; j++) {
        if (A[j] < x) {
            i = i + 1;
            swap(A[i], A[j]);
        }
    }
    swap(A[i + 1], A[r]);
    return i + 1;
}
int randomizedPartition(int A[20], int p, int r) {
    int m;
    m = p + (rand() % (r - p + 1));
    swap(A[r], A[m]);
    return partition(A, p, r);
}
void QuickSort(int A[20], int p, int r) {
    if (p < r) {
        int q;
        q = randomizedPartition(A, p, r);
        QuickSort(A, p, q - 1);
        QuickSort(A, q + 1, r);
    }
}

void display(int A[20], int n) {
    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
}