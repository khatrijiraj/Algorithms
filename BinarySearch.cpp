/*
elements should be in increasing
or decreasing order
*/

#include <iostream>
using namespace std;

int binarySearch(int key, int array[], int size) {
    int start = 0;
    int end = size - 1;
    // int mid = (start + end) / 2;
    int mid = start + (end - start) / 2;
    /* int can take max upto 2^31-1 so to counter
    mid not greater than this... */

    while (start <= end) {
        if (array[mid] == key) {
            return mid;
        } else if (key > array[mid]) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
        mid = (start + end) / 2;
    }
    return -1;
}
/* complexity = logn */
/*
n
n/2
n/4
n/8

== n/2^k
n/2^k = 1
n = 2^k

k = log n
 */
// O(logn)

int main() {
    int even[6] = {1, 2, 4, 7, 8, 10};
    int odd[5] = {2, 3, 6, 8, 9};
    int key;
    cout << "Enter the elements to search: ";
    cin >> key;

    int index = binarySearch(key, odd, 6);
    cout << "Element found at index: " << index << endl;
    return 0;
}