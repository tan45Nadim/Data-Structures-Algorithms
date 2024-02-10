#include<iostream>
using namespace std;

void selection_sort(int *arr, int n) {
    for (int i=0; i<n-1; i++) {
        int smallest = i;
        
        for (int j=i+1; j<n; j++) {
            if (*(arr+smallest) > *(arr+j)) {
                smallest = j;
            }
        }
        
        if (i != smallest) {
            int temp = *(arr + smallest);
            *(arr + smallest) = *(arr + i);
            *(arr + i) = temp;
        }
    }
}

int main() {
    int n; cin >> n;
    int *arr = new int[n];

    for (int i=0; i<n; i++) {
        cin >> *(arr + i);
    }
    selection_sort(arr, n);
    for (int i=0; i<n; i++) {
        cout << *(arr + i) << " ";
    }
}
