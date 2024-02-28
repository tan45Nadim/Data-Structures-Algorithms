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
