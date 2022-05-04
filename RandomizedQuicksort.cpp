#include <cstdlib>
#include <iostream>
using namespace std;

template <class T>
class Sort {
   public:
    int comparison = 0;
    int randomizedPartition(T A[20], int p, int r);
    int partition(T A[20], int p, int r);
    void QuickSort(T A[20], int p, int r);
    void display(T A[20], int n);
};

template <class T>
int Sort<T>::partition(T A[20], int p, int r) {
    int x, i, j;
    x = A[r];
    i = p - 1;
    for (j = p; j <= r - 1; j++) {
        if (A[j] < x) {
            comparison++;
            i = i + 1;
            swap(A[i], A[j]);
        }
    }

    swap(A[i + 1], A[r]);
    return i + 1;
}

template <class T>
int Sort<T>::randomizedPartition(T A[20], int p, int r) {
    int m;
    m = p + (rand() % (r - p + 1));
    swap(A[r], A[m]);
    return partition(A, p, r);
}

template <class T>
void Sort<T>::QuickSort(T A[20], int p, int r) {
    if (p < r) {
        int q;
        q = randomizedPartition(A, p, r);
        QuickSort(A, p, q - 1);
        QuickSort(A, q + 1, r);
    }
}

template <class T>
void Sort<T>::display(T A[20], int n) {
    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl
         << "Comparisons: " << comparison;
}

int main() {
    Sort<char> b;
    Sort<float> c;
    Sort<int> a;
    int n, choice, arr1[20];
    float arr3[20];
    char arr2[20];
    cout << "Enter your choice " << endl;
    cout << "1.Integer" << endl;
    cout << "2.Character" << endl;
    cout << "3.Float" << endl;
    cout << "Your choice : ";
    cin >> choice;
    switch (choice) {
        case 1:
            cout << "Enter the number of elements: ";
            cin >> n;
            for (int i = 0; i < n; i++) {
                cout << "Enter the element: ";
                cin >> arr1[i];
            }
            a.QuickSort(arr1, 0, n - 1);
            a.display(arr1, n);
            break;

        case 2:
            cout << "Enter the number of elements: ";
            cin >> n;
            for (int i = 0; i < n; i++) {
                cout << "Enter the element: ";
                cin >> arr2[i];
            }
            b.QuickSort(arr2, 0, n - 1);
            b.display(arr2, n);
            break;

        case 3:
            cout << "Enter the number of elements: ";
            cin >> n;
            for (int i = 0; i < n; i++) {
                cout << "Enter the element: ";
                cin >> arr3[i];
            }
            c.QuickSort(arr3, 0, n - 1);
            c.display(arr3, n);
            break;

        default:
            cout << "Error wrong choice :(";
            break;
    }
    return 0;
}