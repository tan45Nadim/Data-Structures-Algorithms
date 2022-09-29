#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node* next;
};
Node* top = NULL;

void Push(int key) {
    cout << key << " Inserted" << endl;
    Node* newNode = new Node();
    newNode -> key = key;
    newNode -> next = NULL;

    if(top != NULL) {
        newNode -> next = top;
    }
    top = newNode;
}

void Pop() {
    if(top == NULL) {
        cout << "Error! Stack is Empty" << endl;
        return;
    }
    cout << top -> key << " Deleted" << endl;
    Node* temp = top;
    top = top -> next;
    delete temp;
}

void getTop() {
    if(top == NULL) {
        cout << "Error! Stack is Empty.." << endl;
        return;
    }
    cout << "Top value: " << top -> key << endl;
}

void PrintStack() {
    cout << "Stack Elements: ";
    Node* cur = top;
    while(cur != NULL) {
        cout << cur -> key << " ";
        cur = cur -> next;
    } cout << endl;
}

int main() {
    Push(19);
    Push(28);
    Push(37);
    getTop();
    Push(46);
    PrintStack();

    Pop();
    Pop();
    PrintStack();

    getTop();
}

/*
Output

19 Inserted
28 Inserted
37 Inserted
Top value: 37
46 Inserted
Stack Elements: 46 37 28 19
46 Deleted
37 Deleted
Stack Elements: 28 19
Top value: 28

*/
