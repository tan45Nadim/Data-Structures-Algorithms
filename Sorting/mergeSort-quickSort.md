
## Merge Sort
 > Type - 01 (Using INT_MAX)
```cpp=
//        Time complexity  O(n × log n)
//        Space Complexity  O(n)


#include<iostream>
#include <limits.h>
using namespace std;

void merge(int *A, int start, int mid, int end) {
    int left = mid - start + 1;
    int right = end - mid;

    int *L = new int[left + 1];
    int *R = new int[right + 1];

    for (int i = 0; i < left; i++) {
        L[i] = A[start + i];
//        *(L + i) = *(A + start + i);
    }
    for (int j = 0; j < right; j++) {
        R[j] = A[mid + j + 1];
//        *(R + j) = *(A + mid + j + 1);
    }

    L[left] = INT_MAX; R[right] = INT_MAX;
    int i = 0, j = 0;
    for (int k = start; k <= end; k++) {
        if (L[i] <= R[j]) {
            A[k] = L[i++];
        } else {
            A[k] = R[j++];
        }
    }

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
```
> Type - 02 (Without INT_MAX) 
```cpp=
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
    
// The sorting can be done using both for and while loop. 
// the looping with While is commented below.
    
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
```


## Quick Sort

> myCodeSchool
```cpp=
//        Time complexity
//        Avg case    O(n × log n)
//        Best Case   O(n × log n)
//        Worst Case  O(n^2)
//        Space Complexity  O(n)


#include <iostream>
using namespace std;

void Swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int *arr, int start, int end) {
    int pivot = arr[end];
    int partitionIndex = start;
    for (int i = start; i < end; i++) {
        if (arr[i] < pivot) {
            Swap(&arr[i], &arr[partitionIndex]);
            partitionIndex++;
        }
    }
    Swap(&arr[partitionIndex], &arr[end]);
    return partitionIndex;
}

void quickSort(int *arr, int start, int end) {
    if (start < end) {
        int partitionInd = partition(arr, start, end);
        quickSort(arr, start, partitionInd - 1);
        quickSort(arr, partitionInd + 1, end);
    }
}

int main() {
    cout << "How many numbers? ";
    int n; cin >> n;
    int *arr = new int[n];
    cout << "Enter number for Sort: ";
    for (int i = 0; i < n; i++) {
        cin >> *(arr + i);
    }
    quickSort(arr, 0, n - 1);
    cout << "After Sort: ";
    for (int i = 0; i < n; i++) {
        cout << *(arr + i) << " ";
    }
    delete[] arr;
}
```

> slide
```cpp=
//        Time complexity
//        Avg case    O(n × log n)
//        Best Case   O(n × log n)
//        Worst Case  O(n^2)
//        Space Complexity  O(n)


#include <iostream>
using namespace std;

void Swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int *arr, int start, int end) {
    int pivot = arr[end];
    int partitionIndex = start - 1;
    for (int i = start; i < end; i++) {
        if (arr[i] <= pivot) {
            partitionIndex++;
            Swap(&arr[i], &arr[partitionIndex]);
        }
    } partitionIndex++;
    Swap(&arr[partitionIndex], &arr[end]);
    return partitionIndex;
}

void quickSort(int *arr, int start, int end) {
    if (start < end) {
        int partitionInd = partition(arr, start, end);
        quickSort(arr, start, partitionInd - 1);
        quickSort(arr, partitionInd + 1, end);
    }
}

int main() {
    cout << "How many numbers? ";
    int n; cin >> n;
    int *arr = new int[n];
    cout << "Enter number for Sort: ";
    for (int i = 0; i < n; i++) {
        cin >> *(arr + i);
    }
    quickSort(arr, 0, n - 1);
    cout << "After Sort: ";
    for (int i = 0; i < n; i++) {
        cout << *(arr + i) << " ";
    }
    delete[] arr;
}
```
