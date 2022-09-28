/******************************** Implementation by Global Node ********************************/

#include <iostream>
using namespace std;

struct Node{
    int key;
    Node* next;
    Node* prev;
};
Node* head = NULL;
Node* tail = NULL;

void InsertAtFirst(int item) {
    Node* newNode = new Node();
    newNode -> key = item;
    newNode -> next = NULL;
    newNode -> prev = NULL;

    if(head == NULL) {
        head = newNode;
        tail = newNode;
    }
    else {
        head -> prev = newNode;
        newNode -> next = head;
        head = newNode;
    }
}

void InsertAtLast(int item) {
    Node* newNode = new Node();
    newNode -> key = item;
    newNode -> next = NULL;
    newNode -> prev = NULL;

    if(head == NULL) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail -> next = newNode;
        newNode -> prev = tail;
        tail = newNode;
    }

}

void InsertPosition(int pos, int item) {
    if(pos == 1) {
        InsertAtFirst(item);
        return;
    }
    if(pos < 1) {
        cout << "Invalid position to Insert!" << endl;
        return;
    }
    Node* newNode = new Node();
    newNode -> key = item;
    newNode -> next = NULL;
    newNode -> prev = NULL;

    Node* cur = head;
    for(int i=1; i<pos-1; i++){
        cur = cur -> next;
        if(cur == NULL) {
            cout << "Invalid position to Insert!" << endl;
            return;
        }
    }

    if (cur -> next != NULL) {
        newNode -> next = cur -> next;
        cur -> next -> prev = newNode;
        cur -> next = newNode;
        newNode -> prev = cur;
    }
    else {
        newNode -> prev = cur;
        cur -> next = newNode;
    }

}

void DeleteAtFirst() {
    Node* temp = head;
    if (head == tail) {
        head = NULL;
        tail = NULL;
    }
    else {
        head = head -> next;
        head -> prev = NULL;
    }
    delete temp;
}

void DeleteAtLast() {
    Node* temp = tail;
    if (head == tail) {
        head = NULL;
        tail = NULL;
    }
    else {
        tail = tail -> prev;
        tail -> next = NULL;
    }
    delete temp;
}

void DeletePosition(int pos) {
   if(pos == 1) {
        DeleteAtFirst();
        return;
    }
    if(pos < 1) {
        cout << "Invalid position to Delete!" << endl;
        return;
    }
    Node* cur = head;
    for(int i=1;  i<pos-1; i++) {
        cur = cur -> next;
        if(cur -> next == NULL) {
            cout << "Invalid position to Delete!" << endl;
            return;
        }
    }
    if(cur -> next -> next == NULL ) {
        Node* temp = cur -> next;
        cur -> next = NULL;
        delete temp;
        return;
    }
    Node* temp = cur -> next;
    Node* after_temp = temp -> next;
    cur -> next = cur -> next -> next;
    after_temp -> prev = cur;
    delete temp;
}

void DeleteValue(int item) {
    if(head -> key == item) {
        DeleteAtFirst();
        return;
    }
    if(tail -> key == item) {
        DeleteAtLast();
        return;
    }
    Node* cur = head;
    while(cur -> next -> key != item) {
        cur = cur -> next;
        if(cur -> next == NULL) {
            cout << "Item not found!" << endl;
            return;
        }
    }
    Node* temp = cur -> next;
    Node* after_temp = temp -> next;
    cur -> next = cur -> next -> next;
    after_temp -> prev = cur;
    delete temp;
}

void Print() {
    Node* cur = head;
    while(cur != NULL) {
        cout << cur -> key << " ";
        cur = cur -> next;
    }cout << endl;
}

void Reverse() {
    Node* cur = tail;
    while(cur != NULL) {
        cout << cur -> key << " ";
        cur = cur -> prev;
    }cout << endl;
}

//void Reverse() {
//    Node *prev1, *current, *after;
//    current = head;
//    tail = head;
//    prev1 = NULL;
//    while(current != NULL) {
//        after = current -> next;
//        current -> next = prev1;
//        prev1 = current;
//        current = after;
//    }
//    head = prev1;
//}

//void Reverse() {
//    Node* temp = head;
//    if(temp == NULL) return;
//
//    while(temp -> next != NULL) {
//        temp = temp -> next;
//    }
//
//    while(temp != NULL) {
//        cout << temp -> key << " ";
//        temp = temp -> prev;
//    }cout << endl;
//}

int main() {

    InsertAtFirst(1);
    InsertAtFirst(2);
    InsertAtFirst(3);
    InsertAtFirst(4);
    InsertAtFirst(5);
    InsertAtFirst(6);
    Print(); // 6 5 4 3 2 1

    InsertAtLast(7);
    InsertAtLast(8);
    InsertAtLast(9);
    InsertAtLast(10);
    InsertAtLast(11);
    InsertAtLast(12);
    InsertAtLast(13);

    Print(); // 6 5 4 3 2 1 7 8 9 10 11 12 13

    InsertPosition(5,555);
    Print(); // 6 5 4 3 555 2 1 7 8 9 10 11 12 13

    DeleteAtFirst();
    Print(); // 5 4 3 555 2 1 7 8 9 10 11 12 13

    DeleteAtLast();
    Print(); // 5 4 3 555 2 1 7 8 9 10 11 12

    DeletePosition(6);
    Print(); // 5 4 3 555 2 7 8 9 10 11 12

    DeleteValue(11);
    Print(); // 5 4 3 555 2 7 8 9 10 12

    Reverse(); // 12 10 9 8 7 2 555 3 4 5

    return 0;
}


/*
Output

6 5 4 3 2 1
6 5 4 3 2 1 7 8 9 10 11 12 13
6 5 4 3 555 2 1 7 8 9 10 11 12 13
5 4 3 555 2 1 7 8 9 10 11 12 13
5 4 3 555 2 1 7 8 9 10 11 12
5 4 3 555 2 7 8 9 10 11 12
5 4 3 555 2 7 8 9 10 12
12 10 9 8 7 2 555 3 4 5

*/
