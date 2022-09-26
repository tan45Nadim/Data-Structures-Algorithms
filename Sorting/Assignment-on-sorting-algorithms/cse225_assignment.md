##### `main.cpp`
```cpp=
#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int *arr, int n, long long int *comparisons, long long int *swaps) {
    long long int compare = 0, SWAPS = 0;
    for (int i=0; i<n-1; i++) {
        for (int j=0; j<n-1-i; j++) {
            compare++;
            if (*(arr + j) > *(arr + j + 1)) {
                SWAPS++;
                int temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
    *comparisons = compare;
    *swaps = SWAPS;
}

void selectionSort(int *arr, int n, long long int *comparisons, long long int *swaps) {
    long long int compare = 0, SWAPS = 0;
    for (int i=0; i<n-1; i++) {
        int smallest_index = i;
        for (int j=i+1; j<n; j++) {
            compare++;
            if (*(arr + smallest_index) > *(arr + j)) {
                smallest_index = j;
            }
        }
        if (i != smallest_index) {
            SWAPS++;
            int temp = *(arr + smallest_index);
            *(arr + smallest_index) = *(arr + i);
            *(arr + i) = temp;
        }
    }
    *comparisons = compare;
    *swaps = SWAPS;
}

void insertionSort(int *arr, int n, long long int *comparisons, long long int *swaps) {
    long long int compare = 0, SWAPS  = 0;
    for (int i=0; i<n; i++) {
        int iteam = *(arr + i);
        int j = i - 1;
        compare++;
        while (j >= 0 && *(arr + j) > iteam) {
            compare++;
            *(arr + j + 1) = *(arr + j);
            SWAPS++;
            j--;
        }
        *(arr + j + 1) = iteam;
    }
    *comparisons = compare;
    *swaps = SWAPS;
}

void all_sort_calculation(int n) {
    clock_t startT, endT;
    double time_taken;
    int *bubble = new int[n];
    int *selection = new int[n];
    int *insertion = new int[n];

    for (int i=0; i<n; i++) {
        int x = rand();
        *(bubble + i) = x;
        *(selection + i) = x;
        *(insertion + i) = x;
    }

    long long int *bubble_comparisons = new long long int;
    long long int *bubble_swaps = new long long int;

    long long int *selection_comparisons = new long long int;
    long long int *selection_swaps = new long long int;

    long long int *insertion_comparisons = new long long int;
    long long int *insertion_swaps = new long long int;

    startT = clock();
    bubbleSort(bubble, n, bubble_comparisons, bubble_swaps);
    endT = clock();
    cout << "Bubble comparisons : " << *bubble_comparisons << endl;
    cout << "Bubble swaps : " << *bubble_swaps << endl;
    time_taken = (double)(endT - startT) / CLOCKS_PER_SEC;
    cout << "Time taken by Bubble Sort is : " << time_taken << " sec" << endl;;

    cout << "\n";
    startT = clock();
    selectionSort(selection, n, selection_comparisons, selection_swaps);
    endT = clock();
    cout << "Selection comparisons : " << *selection_comparisons << endl;
    cout << "Selection swaps : " << *selection_swaps << endl;
    time_taken = (double)(endT - startT) / CLOCKS_PER_SEC;
    cout << "Time taken by Selection  Sort is : " << time_taken << " sec" << endl;

    cout << "\n";
    startT = clock();
    insertionSort(insertion, n, insertion_comparisons, insertion_swaps);
    endT = clock();
    cout << "Insertion comparisons : " << *insertion_comparisons << endl;
    cout << "Insertion swaps : " << *insertion_swaps << endl;
    time_taken = (double)(endT - startT) / CLOCKS_PER_SEC;
    cout << "Time taken by Insertion Sort is : " << time_taken << " sec" << endl;
    cout << "\n\n\n";
}

int main() {
    int set01 = 15000;
    cout << "\tSet01 Value " << set01 << " : " << endl;
    all_sort_calculation(set01);

    int set02 = 32000;
    cout << "\tSet02 Value " << set02 << " : " << endl;
    all_sort_calculation(set02);

    int set03 = 66000;
    cout << "\tSet03 Value " << set03 << " : " << endl;
    all_sort_calculation(set03);

    int set04 = 100000;
    cout << "\tSet04 Value " << set04 << " : " << endl;
    all_sort_calculation(set04);

}
```

##### `output.txt`
```txt=
        Set01 Value 15000 :
Bubble comparisons : 112492500
Bubble swaps : 56212265
Time taken by Bubble Sort is : 0.381 sec

Selection comparisons : 112492500
Selection swaps : 14988
Time taken by Selection  Sort is : 0.184 sec

Insertion comparisons : 56227265
Insertion swaps : 56212265
Time taken by Insertion Sort is : 0.145 sec



        Set02 Value 32000 :
Bubble comparisons : 511984000
Bubble swaps : 257300782
Time taken by Bubble Sort is : 2.176 sec

Selection comparisons : 511984000
Selection swaps : 31989
Time taken by Selection  Sort is : 0.996 sec

Insertion comparisons : 257332782
Insertion swaps : 257300782
Time taken by Insertion Sort is : 0.759 sec



        Set03 Value 66000 :
Bubble comparisons : 2177967000
Bubble swaps : 1092343419
Time taken by Bubble Sort is : 9.968 sec

Selection comparisons : 2177967000
Selection swaps : 65985
Time taken by Selection  Sort is : 3.777 sec

Insertion comparisons : 1092409419
Insertion swaps : 1092343419
Time taken by Insertion Sort is : 3.026 sec



        Set04 Value 100000 :
Bubble comparisons : 4999950000
Bubble swaps : 2498550119
Time taken by Bubble Sort is : 23.347 sec

Selection comparisons : 4999950000
Selection swaps : 99978
Time taken by Selection  Sort is : 8.181 sec

Insertion comparisons : 2498650119
Insertion swaps : 2498550119
Time taken by Insertion Sort is : 6.302 sec
```
