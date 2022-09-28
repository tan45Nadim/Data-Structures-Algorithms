/******************************** Implementation by Global Node ********************************/

#include<bits/stdc++.h>
using namespace std;
struct Node {
    int key;
    Node* next;
    Node* prev;
};
Node* head = NULL;
Node* tail = NULL;

void pushFront(int key) {
    Node* newNode = new Node();
    newNode -> key = key;
    newNode -> next = NULL;
    newNode -> prev = NULL;

    if (head == NULL) {
       head = newNode;
       tail = newNode;
    }
    else {
        head -> prev = newNode;
        newNode -> next = head;
        head = newNode;
    }
}

void pushBack(int key) {
    Node* newNode = new Node();
    newNode -> key = key;
    newNode -> next = NULL;
    newNode -> prev = NULL;

    if (head == NULL) {
       head = newNode;
       tail = newNode;
    }
    else {
        tail -> next = newNode;
        newNode -> prev = tail;
        tail = newNode;
    }
}

void popFront() {
    if (head == tail) {
        head = NULL;
        tail = NULL;
    }
    else {
        Node* temp = head;
        head = head -> next;
        head -> prev = NULL;
        delete temp;
    }
}

void popBack() {
    if (head == tail) {
        tail = NULL;
        head = NULL;
    }
    else {
        Node* temp = tail;
        tail -> prev -> next  = NULL;
        tail = tail -> prev;
        delete temp;
    }
}

void printList() {
    Node* cur = head;
    while (cur != NULL) {
        cout << cur -> key << " ";
        cur = cur -> next;
    }cout << endl;
}

void reversePrintList() {
    Node* cur = tail;
    while(cur != NULL) {
        cout << cur -> key << " ";
        cur = cur -> prev;
    }
    cout << endl;
}

int main() {

    for(int i=0; i<5; i++) {
        pushFront(i);
    }
    cout << "After pushing(front) 5 nodes: ";
    printList();
    cout << "Reverse order Print: ";
    reversePrintList();


    for(int i=6; i<12; i++) {
        pushBack(i);
    }
    cout << "After pushing(back) 6 nodes: ";
    printList();
    cout << "Reverse order Print: ";
    reversePrintList();


    for(int i=0; i<2; i++) {
        popFront();
    }
    cout << "After poping(front) 2 nodes: ";
    printList();
    cout << "Reverse order Print: ";
    reversePrintList();


    for(int i=0; i<3; i++) {
        popBack();
    }
    cout << "After poping(back) 3 nodes: ";
    printList();
    cout << "Reverse order Print: ";
    reversePrintList();
}


/*
Output

After pushing(front) 5 nodes: 4 3 2 1 0
Reverse order Print: 0 1 2 3 4
After pushing(back) 6 nodes: 4 3 2 1 0 6 7 8 9 10 11
Reverse order Print: 11 10 9 8 7 6 0 1 2 3 4
After poping(front) 2 nodes: 2 1 0 6 7 8 9 10 11
Reverse order Print: 11 10 9 8 7 6 0 1 2
After poping(back) 3 nodes: 2 1 0 6 7 8
Reverse order Print: 8 7 6 0 1 2

*/
