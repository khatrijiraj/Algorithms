#include <iostream>

#include "RandomizedQuicksort.h"
using namespace std;

int randomizedSelect(int A[], int p, int r, int i) {
    int q, k;
    if (p == r) {
        return A[p];
    }
    q = randomizedPartition(A, p, r);
    k = q - p + 1;
    if (i == k) {
        return A[q];
    } else if (i < k) {
        return randomizedSelect(A, p, q - 1, i);
    } else {
        return randomizedSelect(A, q + 1, r, i - k);
    }
}

int main() {
    int A[20], i, n;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    cout << "Enter the index: ";
    cin >> i;
    cout << "The smallest " << i << " number is: " << randomizedSelect(A, 0, n - 1, i);
    return 0;
}