//    Time complexity  O(n)


#include <iostream>
using namespace std;

void maxSumInterval(int *A, int *sum, int *prev, int n, int &ms, int &mInd) {
    sum[0] = 0;
    prev[0] = -1;
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + A[i];
        prev[i] = i - 1;
        if (A[i] > sum[i]) {
            sum[i] = A[i];
            prev[i] = 0;
        }
        if (ms < sum[i]) {
            ms = sum[i]; mInd = i;
        }
    }
}

void printMaxSumInterval(int *A, int *prev, int i) {
    if (prev[i] > 0) {
        printMaxSumInterval(A, prev, prev[i]);
    }
    cout << A[i] << " ";
}

int main () {
    cout << "Enter n: ";
    int n; cin >> n;
    cout << "Enter Elements: ";

    int *a = new int[n + 1]; a[0] = 0;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int *sum = new int[n + 1];
    int *prev = new int[n + 1];
    int maxSum = 0, maxInd = 0;

    maxSumInterval(a, sum, prev, n, maxSum, maxInd);

    cout << "Maximum Sum = " << maxSum << endl;

    cout << "The Maximum Sum Interval: ";
    printMaxSumInterval(a, prev, maxInd);
    cout << endl;

    delete[] a; delete[] sum; delete[] prev;
}

// INPUT
// n = 15
// 9 –3 1 7 –15 2 3 –4 2 –7 6 –2 8 4 -9
