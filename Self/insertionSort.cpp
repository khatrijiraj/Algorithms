#include <iostream>
using namespace std;

class insertionSort {
   public:
    void display(int array[20], int n);
    void sort(int array[20], int n);
};

void insertionSort::sort(int array[20], int n) {
    int i, j, key, comparison = 0;
    for (i = 1; i < n; i++) {
        key = array[i];
        j = i - 1;
        comparison++;
        while (j >= 0 && array[j] > key) {
            if (array[j - 1] > array[j]) {
                comparison++;
            }
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
    cout << "\nComparison: " << comparison;
}

void insertionSort::display(int array[20], int n) {
    cout << "Array: ";
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
}

int main() {
    insertionSort obj;
    int size, array[20];
    cout << "INSERTION SORT\nEnter the size of array: ";
    cin >> size;
    for (int i = 0; i < size; i++) {
        cout<<"Enter element "<<i+1<<": ";
        cin >> array[i];
    }
    obj.display(array, size);
    obj.sort(array, size);
    cout << "\nSorted Array: ";
    obj.display(array, size);
    cout << endl;
    return 0;
}