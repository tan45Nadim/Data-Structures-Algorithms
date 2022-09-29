#include <bits/stdc++.h>
#define SIZE 10
using namespace std;

int A[SIZE];
int top = -1;

void Push(int key) {
    if (top == SIZE -1) {
        cout << "Error! Stack is Full" << endl;
        return;
    }
    top++;
    A[top] = key;
}

void pop() {
    if(top == -1) {
        cout << "Error! Stack is Empty" << endl;
        return;
    }
    top--;
}

void Top() {
    cout << "Top value: " << A[top] << endl;
}

void PrintStack() {
    for( int i=0; i<=top; i++) {
        cout << A[i] << " ";
    } cout << endl;
}

int main() {
    Push(12);
    Push(13);
    Push(14);
    Push(15);
    Push(16);
    PrintStack();

    pop();
    pop();
    PrintStack();

    Top();
}


/*
Output

12 13 14 15 16
12 13 14
Top value: 14

*/
