#include <bits/stdc++.h>
#define SIZE 5
using namespace std ;
int A[SIZE];
int front = -1, rear = -1;

bool isEmpty() {
    return (rear == -1 && front == -1);
}

bool isFull() {
    return (front == ((rear + 1) % SIZE));
}

void Enqueue(int key) {
    if(isFull()) {
        cout << "Queue is already Full" << endl;
        return;
    }
    if(isEmpty()) {
        rear = 0;
        front = 0;
    }
    else {
        rear = (rear + 1) % SIZE;
    }
    A[rear] = key;
}

void Dequeue() {
    if(isEmpty()) {
        cout << "Queue is already Empty" << endl;
        return;
    }
    if(rear == front) {
        rear = -1;
        front = -1;
    }
    else {
        front = (front + 1) % SIZE;
    }
}

int Front() {
    if(front == -1) {
        cout << "Error! Cannot return top from empty queue" << endl;
        return -1;
    }
    return A[front];
}

void PrintQueue() {
    // Finding number of elements in queue
    int cnt = (SIZE + rear - front) % SIZE + 1;
    for(int i=0; i<cnt; i++) {
        int index = (front + i) % SIZE;
        cout << A[index] << " ";
    }cout << endl;
}

int main() {
    Enqueue(1);
    Enqueue(2);
    Enqueue(3);
    Enqueue(4);
    Enqueue(5); PrintQueue();
    Enqueue(6); PrintQueue();
    cout << "Front: " << Front() << endl;

    Dequeue();
    Dequeue(); PrintQueue();
    cout << Front() << endl;

    Enqueue(13); PrintQueue();
    Enqueue(14);
    Enqueue(15); PrintQueue();

   cout << "Front: " << Front() << endl;
}


/*
Output

1 2 3 4 5
Queue is already Full
1 2 3 4 5
Front: 1
3 4 5
3
3 4 5 13
Queue is already Full
3 4 5 13 14
Front: 3

*/
