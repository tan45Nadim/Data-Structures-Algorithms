#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node* next;
};
Node* front = NULL;
Node* rear = NULL;

void Enqueue(int key) {
    cout << key << " Enqueued" << endl;
    Node* newNode = new Node();
    newNode -> key = key;
    newNode -> next = NULL;

    if(front == NULL && rear == NULL) {
        front = rear = newNode;
        return;
    }
    else {
        rear -> next = newNode;
        rear = newNode;
    }
}

void Dequeue() {
    Node* temp = front;
    if(front == NULL) return;
    if(front == rear) {
        front = rear = NULL;
        return;
    }
    cout << front -> key << " Dequeued" << endl;
    front = front -> next;
    delete temp;
}

void getFront() {
    if(front == NULL) {
        cout << "Error! Queue is Empty" << endl;
    }
    else {
        cout << "Front value: " << front -> key << endl;
    }
}

void PrintQueue() {
    cout << "Queue Elements: ";
    Node* cur = front;
    while(cur != NULL) {
        cout << cur -> key << " ";
        cur = cur -> next;
    }cout << endl;
}

int main() {
    getFront();
    Enqueue(202);
    Enqueue(303);
    Enqueue(404);
    Enqueue(505);
    PrintQueue();

    Dequeue();
    Dequeue();
    PrintQueue();
    getFront();
}


/*
Output

Error! Queue is Empty
202 Enqueued
303 Enqueued
404 Enqueued
505 Enqueued
Queue Elements: 202 303 404 505
202 Dequeued
303 Dequeued
Queue Elements: 404 505
Front value: 404

*/
