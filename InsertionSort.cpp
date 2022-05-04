#include <iostream>
using namespace std;

template <class I>
class insertionSort {
    I array[20], n;

   public:
    void display(I array[20], int n);
    void sort(I array[20], int n);
};

template <class I>
void insertionSort<I>::sort(I array[], int n) {
    int i, j, comparison = 0, sum = 0;
    I temp;
    for (i = 1; i < n; i++) {
        temp = array[i];
        j = i - 1;
        comparison++;
        while (j >= 0 && array[j] > temp) {
            if (array[j - 1] > array[j]) {
                comparison++;
            }
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = temp;
    }
    cout << "\nComparison: " << comparison;
}

template <class I>
void insertionSort<I>::display(I array[], int n) {
    cout << "Array: ";
    for (int i = 0; i < n; i++)
        cout << array[i] << " ";
}

int main() {
    insertionSort<int> obj1;
    insertionSort<char> obj2;
    int choice, size, array[20];
    char a[20];
    cout << "Integer" << endl;
    cout << "Character" << endl;
    cout << "Enter your choice : ";
    cin >> choice;
    switch (choice) {
        case 1:
            cout << "Enter size: ";
            cin >> size;
            cout << "Enter the elements: ";
            for (int i = 0; i < size; i++) {
                cin >> array[i];
            }
            obj1.display(array, size);
            obj1.sort(array, size);
            cout << endl;
            cout << "\nSorted Array: " << endl;
            obj1.display(array, size);
            cout << endl;
            break;

        case 2:
            cout << "Enter size: ";
            cin >> size;
            cout << "Enter the elements: ";
            for (int i = 0; i < size; i++) {
                cin >> a[i];
            }
            obj2.display(a, size);
            obj2.sort(a, size);
            cout << endl;
            cout << "\nSorted Array:" << endl;
            obj2.display(a, size);
            cout << endl;
            break;

        default:
            cout << "Error wrong choice :(";
            break;
    }
    return 0;
}