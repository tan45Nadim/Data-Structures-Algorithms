//        Time complexity  O(n × log n)
//        Space Complexity  O(n)


#include<iostream>
using namespace std;

void merge(int *A, int start, int mid, int end) {
    int left = mid - start + 1;
    int right = end - mid;

    int *L = new int[left];
    int *R = new int[right];

    for (int i = 0; i < left; i++) {
        L[i] = A[start + i];
    }
    for (int j = 0; j < right; j++) {
        R[j] = A[mid + j + 1];
    }

    int i = 0, j = 0;
    for (int k = start; k <= end; k++) {
        if (L[i] <= R[j]) {
            if (i < left) A[k] = L[i++];
            else A[k] = R[j++];
        } else {
            if (j < right) A[k] = R[j++];
            else A[k] = L[i++];
        }
    }

//    int i = 0, j = 0, k = start;
//    while (i < left && j < right) {
//        if (L[i] <= R[j]) {
//            A[k++] = L[i++];
//        } else {
//            A[k++] = R[j++];
//        }
//    }
//    while (i < left) {
//        A[k++] = L[i++];
//    }
//    while (j < right) {
//        A[k++] = R[j++];
//    }

    delete[] L; delete[] R;
}

void mergeSort(int *A, int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        mergeSort(A, start, mid);
        mergeSort(A, mid + 1, end);
        merge(A, start, mid, end);
    }
}

int main () {
    cout << "How many numbers? ";
    int n; cin >> n;
    int *arr = new int[n];
    cout << "Enter numbers for Sort: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    mergeSort(arr, 0, n - 1);
    cout << "After Sort: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    } cout << endl;

    delete[] arr;
}
