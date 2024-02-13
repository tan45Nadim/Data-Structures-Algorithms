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
