#include <iostream>
#include <algorithm>
using namespace std;

int binarySearch(int *arr, int n, int key) {
    int first = 0;
    int last = n - 1;

    while (first <= last) {
        int mid = (first + last) / 2;

        if (*(arr + mid) == key) {
            return mid;
        } else if (*(arr + mid) > key) {
            last = mid - 1;
        } else {
            first = mid + 1;
        }
    }
    return -1;
}

int main() {
    int n; cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> *(arr + i);
    }
    sort(arr, arr+n);

    cout << "Enter a number for Search: ";
    int key; cin >> key;
    cout << binarySearch(arr, n, key) << endl;

    return 0;
}

// Time Complexity O(log(n))
// Space Complexity of O(1)
