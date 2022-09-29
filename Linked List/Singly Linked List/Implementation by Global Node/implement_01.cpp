/********************************
    Implementation by Global Node
********************************/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node* next;
};
Node* head = NULL;

void pushFront(int key) {
    Node* newNode = new Node();
    newNode -> key = key;
    newNode -> next = NULL;

    if(head != NULL) {
        newNode -> next = head;
    }
    head = newNode;
}

void popFront() {
    if (head == NULL) return;

    Node* temp = head;
    head = head -> next;
    delete temp;
}

void pushBack(int key) {
    Node* newNode = new Node();
    newNode -> key = key;
    newNode -> next = NULL;

    if(head == NULL) {
        head = newNode;
    }
    else {
        Node* cur = head;
        while(cur -> next != NULL) {
            cur = cur -> next;
        }
        cur -> next = newNode;
    }
}

void popBack() {
    if (head == NULL) return;
    else if (head -> next == NULL) {
        Node *delNode = head;
        head = NULL;
        delete delNode;
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

Node* findKey(int search_key) {
    Node* cur = head;
    while(cur != NULL) {
        if(cur -> key == search_key){
            return cur;
        }
        cur = cur -> next;
    }
    return NULL;
}

void eraseKey(int key) {
    Node* cur = head;
    Node* foundNode = findKey(key);
    if(foundNode != NULL) {
        if(head == foundNode) {
            head = head -> next;
        }
        else {
            while(cur -> next != foundNode) {
                cur = cur -> next;
            }
            Node* tempNode = cur;
            tempNode -> next = foundNode -> next;
        }
        delete foundNode;
    }
    else {
        cout << "Key not found" << endl;
    }
}

void addAfter(Node* prevNode, int add_value) {
    Node* newNode = new Node();
    newNode -> key = add_value;

    if(prevNode != NULL) {
        newNode -> next = prevNode -> next;
        prevNode -> next = newNode;
    }
    else {
        cout << "key not found" << endl;
    }
}

void addBefore(Node* nextNode, int add_value) {
    Node* newNode = new Node();
    newNode -> key = add_value;
    Node* cur = head;

    if(nextNode != NULL) {
        if(nextNode == head) {
            newNode -> next = head;
            head = newNode;
        }
        else {
            while(cur -> next != nextNode) {
                cur = cur -> next;
            }
            newNode -> next = nextNode;
            cur -> next = newNode;
        }
    }
    else {
        cout << "key not found" << endl;
    }
}

void printList() {
    Node* cur = head;
    while(cur != NULL) {
        cout<< cur -> key << " ";
        cur = cur -> next;
    }cout<<endl;
}

int main() {
    for(int i=0; i<5; i++) {
        pushFront(i);
    } // 4 3 2 1 0
    cout << "After pushing(front) 5 nodes: ";
    printList();

    for(int i=0; i<3; i++) {
        popFront();
    } // 1 0
    cout << "After poping(front) 3 nodes: ";
    printList();

    for(int i=5; i<10; i++) {
        pushBack(i);
    } // 1 0 5 6 7 8 9
    cout << "After pushing(back) 5 nodes: ";
    printList();

    for(int i=0; i<3; i++) {
        popBack();
    } // 1 0 5 6
    cout << "After poping(back) 3 nodes: ";
    printList();

//    Node* a = FindKey(5);
//    cout << a << endl;

    eraseKey(0);
    cout << "After erasing 1 node: ";
    printList(); // 1 5 6

    Node* a = findKey(5);
    addAfter(a, 22);
    cout << "Using addAfter: ";
    printList(); // 1 5 22 6

    a = findKey(1);
    addBefore(a, 100);
    cout << "Using addBefore: ";
    printList(); // 100 1 5 22 6

//    a = findKey(5);
    addBefore(findKey(5), 88);
    cout << "Using addBefore: ";
    printList(); // 100 1 88 5 22 6

    return 0;
}


/*
Output

After pushing(front) 5 nodes: 4 3 2 1 0
After poping(front) 3 nodes: 1 0
After pushing(back) 5 nodes: 1 0 5 6 7 8 9
After poping(back) 3 nodes: 1 0 5 6
After erasing 1 node: 1 5 6
Using addAfter: 1 5 22 6
Using addBefore: 100 1 5 22 6
Using addBefore: 100 1 88 5 22 6

*/
