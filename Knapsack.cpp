#include <climits>
#include <iostream>
using namespace std;

int knapsack(int values[], int weights[], int n, int capacity) {
    if (capacity < 0) {
        return INT_MIN;
    }
    if (n < 0 || capacity == 0) {
        return 0;
    }

    int include = values[n] + knapsack(values, weights, n - 1, capacity - weights[n]);
    int exclude = knapsack(values, weights, n - 1, capacity);
    return max(include, exclude);
}

// 0–1 Knapsack problem
int main() {
    int value[] = {20, 5, 10, 40, 15, 25};
    int weight[] = {1, 2, 3, 8, 7, 4};
    int capacity = 10;
    // total number of items
    int n = sizeof(value) / sizeof(value[0]);
    cout << "Knapsack value: " << knapsack(value, weight, n - 1, capacity);
    return 0;
}