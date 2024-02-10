#include<iostream>
using namespace std;

void insertion_sort(int *arr, int n) {
    for (int i = 1; i < n; i++) {
        int item = *(arr + i);
        int j = i - 1;
        
        while (j >= 0 && *(arr + j) > item) {
            *(arr + j + 1) = *(arr + j);
            j--;
        }
        
        *(arr + j + 1) = item;
    }
}

int main() {
    int n; cin >> n;
    int *arr = new int[n];
    //int *arr = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        cin >> *(arr + i);
    }
    insertion_sort(arr, n);
    for (int i = 0; i < n; i++) {
        cout << *(arr + i) << " ";
    }
}
