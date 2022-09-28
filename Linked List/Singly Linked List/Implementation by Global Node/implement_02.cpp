/********************************
    Implementation by Global Node
********************************/

#include <iostream>
using namespace std;

struct Node{
    int key;
    Node* next;
};
Node* head = NULL;

void InsertAtFirst(int item) {
    Node* newNode = new Node();
    newNode -> key = item;
    newNode -> next = NULL;

    if(head != NULL)
        newNode -> next = head;

    head = newNode;
}

void InsertAtLast(int item) {
    Node* newNode = new Node();
    newNode -> key = item;
    newNode -> next = NULL;

    if(head == NULL) {
        head = newNode;
        return;
    }

    Node* cur = head;
    while(cur -> next != NULL) {
        cur = cur -> next;
    }
    cur -> next = newNode;
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

    Node* cur = head;
    for(int i=1; i<pos-1; i++) {
        cur = cur -> next;
        if(cur == NULL) {
            cout << "Invalid position to Insert!" << endl;
            return;
        }
    }
    newNode -> next = cur -> next;
    cur -> next = newNode;
}

void DeleteAtFirst() {
    if(head == NULL) {
        cout << "List is already empty!";
        return;
    }

    Node* temp = head;
    head = head -> next;
    delete temp;
}

void DeleteAtLast() {
    if(head == NULL) {
        cout << "List is already empty!";
        return;
    }
    else if(head -> next == NULL) {
        Node* temp = head;
        head = NULL;
        delete temp;
        return;
    }

    Node* cur = head;
    while(cur -> next -> next != NULL) {
        cur = cur -> next;
    }
    Node* temp = cur -> next;
    cur -> next = NULL;
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
    for(int i=1; i<pos-1; i++) {
        cur = cur -> next;
        if(cur -> next == NULL) {
            cout << "Invalid position to Delete!" << endl;
            return;
        }
    }
    Node* temp = cur -> next;
    cur -> next = cur -> next -> next;
    delete temp;

}


void DeleteValue(int item) {
    if(head -> key == item) {
    DeleteAtFirst();
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
    cur -> next = cur -> next -> next;
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
    Node *prev, *current, *after;
    current = head;
    prev = NULL;
    while(current != NULL) {
        after = current -> next;
        current -> next = prev;
        prev = current;
        current = after;
    }
    head = prev;
}

int main() {
    InsertAtFirst(11);
    InsertAtFirst(22);
    InsertAtFirst(33);
    InsertAtFirst(44);
    InsertAtFirst(55);
    InsertAtFirst(66);
    Print(); // 66 55 44 33 22 11

    InsertAtLast(1);
    InsertAtLast(2);
    InsertAtLast(3);
    InsertAtLast(4);
    Print(); // 66 55 44 33 22 11 1 2 3 4

    DeleteAtFirst();
    DeleteAtFirst();
    Print(); // 44 33 22 11 1 2 3 4

    DeleteAtLast();
    DeleteAtLast();
    Print(); // 44 33 22 11 1 2

    InsertPosition(3,999);
    Print(); // 44 33 999 22 11 1 2

    DeletePosition(5);
    Print(); // 44 33 999 22 1 2

    DeleteValue(22);
    Print(); // 44 33 999 1 2

    Reverse();
    Print(); // 2 1 999 33 44

    return 0;
}


/*
Output

66 55 44 33 22 11
66 55 44 33 22 11 1 2 3 4
44 33 22 11 1 2 3 4
44 33 22 11 1 2
44 33 999 22 11 1 2
44 33 999 22 1 2
44 33 999 1 2
2 1 999 33 44

*/
