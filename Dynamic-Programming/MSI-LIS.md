## MSI - Maximum Sum Interval

```cpp=
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
```

## LIS - Longest Increasing Subsequence

> Naive Approach
```cpp=
//    Time complexity  O(n^2)


#include <iostream>
using namespace std;

int LIS_Naive(int *A, int *L, int *prev, int n) {
    L[0] = 0; prev[0] = -1;
    int maxL = 0, maxI = 0;
    for (int i = 1; i <= n; i++) {
        L[i] = 0;
        for (int j = 0; j < i; j++) {
            if (A[j] < A[i] && L[j] + 1 >= L[i]) {
                L[i] = L[j] + 1;
                prev[i] = j;
            }
        }
        if (L[i] > maxL) {
            maxL = L[i]; maxI = i;
        }
    }
    return maxI;
}

void printLIS_Naive(int *A, int *prev, int i) {
    if (prev[i] > 0) {
        printLIS_Naive(A, prev, prev[i]);
    }
    cout << A[i] << " ";
}

int main () {
    cout << "Enter n: ";
    int n; cin >> n;
    cout << "Enter Elements: ";

    int *a = new int[n + 1]; a[0] = 0;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int *L = new int[n + 1];
    int *prev = new int[n + 1];

    int maxIndex = LIS_Naive(a, L, prev, n);
    
    cout << "Longest Increasing Subsequence: ";
    printLIS_Naive(a, prev, maxIndex);
    cout << endl;

    delete[] a; delete[] L; delete[] prev;
}

// INPUT
// n = 10
// 9 2 5 3 7 11 8 10 13 6

// n = 9
// 2 5 3 6 1 2 10 7 9

```


> LIS-Fast
```cpp=
//  Time complexity  O(n*log(n))


#include <iostream>
#include <limits.h>
using namespace std;

int LIS(int *A, int *L, int *Li, int *prev, int n, int &len) {
    L[0] = INT_MIN; Li[0] = -1; prev[0] = -1;
    int maxL = 0, maxI = 0;
    for (int i = 1; i <= n; i++) {
        if (L[len] < A[i]) {
            len++;
            L[len] = A[i];
            Li[len] = i;
            prev[i] = Li[len - 1];
            maxL = L[i]; maxI = i;
        } else {
            int st = 0, en = len;
            while (st < en) {
                int mid = (st + en) / 2;
                if (L[mid] < A[i]) {
                    st = mid + 1;
                } else {
                    en = mid;
                }
            }
            L[st] = A[i];
            Li[st] = i;
            prev[i] = Li[st - 1];
        }
    }
    return maxI;
}

void printLIS(int *A, int *prev, int i) {
    if (prev[i] > -1) {
        printLIS(A, prev, prev[i]);
    }
    cout << A[i] << " ";
}

int main () {
    cout << "Enter n: ";
    int n; cin >> n;
    cout << "Enter Elements: ";

    int *a = new int[n + 1]; a[0] = 0;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int *L = new int[n + 1];
    int *Li = new int[n + 1];
    int *prev = new int[n + 1];
    int length = 0;

    int maxIndex = LIS(a, L, Li, prev, n, length);

    cout << "Length of LIS: " << length << endl;
    cout << "LIS Sequence: ";
    printLIS(a, prev, maxIndex);

    delete[] a; delete[] L; delete[] Li; delete[] prev;
}

// INPUT

// n = 10
// 9 2 5 3 7 11 8 10 13 6

// n = 9
// 2 5 3 6 1 2 10 7 9

// n = 7
// 2 8 9 5 6 7 1

```
