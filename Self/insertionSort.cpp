#include <iostream>
using namespace std;

class insertionSort {
   public:
    void display(int array[20], int n);
    void sortIncreasingOrder(int array[20], int n);
    void sortDecreasingOrder(int array[20], int n);
};

void insertionSort::sortIncreasingOrder(int array[20], int n) {
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

void insertionSort::sortDecreasingOrder(int array[20], int n) {
}

void insertionSort::display(int array[20], int n) {
    cout << "Array: ";
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
}

int main() {
    insertionSort obj;
    int size, array[20], choice;
    char tryagain;
    do {
        cout << "\nINSERTION SORT\nEnter the size of array: ";
        cin >> size;
        for (int i = 0; i < size; i++) {
            cout << "Enter element " << i + 1 << ": ";
            cin >> array[i];
        }

        cout << "Enter order of sorting:\n 1. Increasing order\n 2. Decreasing order\n 3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                obj.display(array, size);
                obj.sortIncreasingOrder(array, size);
                cout << "\nSorted Array: ";
                obj.display(array, size);
                cout << endl;
                cout << "Do you want to try again?(y/Y): ";
                cin >> tryagain;
                break;
            case 2:
                obj.display(array, size);
                obj.sortDecreasingOrder(array, size);
                cout << "\nSorted Array: ";
                obj.display(array, size);
                cout << endl;
                cout << "Do you want to try again?(y/Y): ";
                cin >> tryagain;
            case 3:
                exit(0);
            default:
                cout << "Error Wrong Choice try again";
                tryagain = 'y';
                break;
        }
    } while (tryagain = 'y' || tryagain == 'Y');
    return 0;
}