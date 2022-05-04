#include <algorithm>
#include <iostream>
using namespace std;

class Interval {
   public:
    int start;
    int finish;
    int weights;
};

bool jobsComparison(Interval a, Interval b) {
    return (a.finish < b.finish);
}

int NonOverlappingJobs(Interval job[], int i) {
    for (int j = i - 1; j >= 0; j--) {
        if (job[j].finish <= job[i - 1].start) {
            return j;
        }
    }
    return -1;
}

int computeOptimal(Interval job[], int n) {
    if (n == 1) {
        { return job[n - 1].weights; }
    }
    int j = NonOverlappingJobs(job, n);

    int selected = job[n - 1].weights + computeOptimal(job, j + 1);
    int notSelected = computeOptimal(job, n - 1);

    return max(selected, notSelected);
}

int findSolution(Interval job[], int n) {
    sort(job, job + n, jobsComparison);
    return computeOptimal(job, n);
}

int main() {
    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;
    Interval interval[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter the start time of jobs: ";
        cin >> interval[i].start;
    }
    for (int i = 0; i < n; i++) {
        cout << "Enter the finish time of jobs: ";
        cin >> interval[i].finish;
    }
    for (int i = 0; i < n; i++) {
        cout << "Enter the weights of job: ";
        cin >> interval[i].weights;
    }
    int optimalSolution = findSolution(interval, n);
    cout << "\nOptimal Solution : " << optimalSolution;

    return 0;
}