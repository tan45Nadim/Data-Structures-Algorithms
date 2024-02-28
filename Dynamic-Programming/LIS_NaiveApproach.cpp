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
