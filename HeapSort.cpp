#include <iostream>
using namespace std;

template <class H>
class HeapSort {
    int comparision = 0;

   public:
    void maxHeapify(H Arr[20], int size, int i);
    void heapSort(H Arr[], int size);
};

template <class H>
void HeapSort<H>::maxHeapify(H Arr[20], int size, int i) {
    int largest, left, right;
    largest = i;
    left = 2 * i + 1;
    right = 2 * i + 2;
    if (left < size && Arr[left] > Arr[largest]) {
        largest = left;
        comparision++;
    } else {
        largest = i;
    }
    if (right < size && Arr[right] > Arr[largest]) {
        largest = right;
        comparision++;
    }
    if (largest != i) {
        swap(Arr[i], Arr[largest]);
        maxHeapify(Arr, size, largest);
    }
}

template <class H>
void HeapSort<H>::heapSort(H Arr[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        maxHeapify(Arr, size, i);
    }
    for (int i = size - 1; i >= 0; i--) {
        swap(Arr[0], Arr[i]);
        maxHeapify(Arr, i, 0);
    }
    cout << "No of comparisons: " << comparision << endl;
}

int main() {
    HeapSort<int> a;
    HeapSort<char> b;
    int Arr[20], size, choice;
    char A[20];
    cout << "Enter the type of heap you want to enter " << endl;
    cout << "1.Integer" << endl;
    cout << "2.Character" << endl;
    cout << "Your choice: ";
    cin >> choice;
    cout << "Enter the number of elements: ";
    cin >> size;
    switch (choice) {
        case 1:
            cout << "Enter the elements: ";
            for (int i = 0; i < size; i++) {
                cin >> Arr[i];
            }
            a.heapSort(Arr, size);
            cout << "Sorted Array: ";
            for (int i = 0; i < size; i++) {
                cout << Arr[i] << " ";
            }
            break;

        case 2:
            cout << "Enter the elements: ";
            for (int i = 0; i < size; i++) {
                cin >> A[i];
            }
            b.heapSort(A, size);
            cout << "Sorted Array: ";
            for (int i = 0; i < size; i++) {
                cout << A[i] << " ";
            }
            break;

        default:
            cout << "Error wrong choice :(";
            break;
    }
    return 0;
}