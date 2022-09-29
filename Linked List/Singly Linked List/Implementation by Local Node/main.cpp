/*****************************
  Implementation by Local Node
*****************************/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node* next;
};

Node* pushFront(Node* head, int key) {
    Node* newNode = new Node();
    newNode -> key = key;
    newNode -> next = NULL;
    if(head != NULL) {
        newNode -> next = head;
    }
    head = newNode;
    return head;
}

Node* popFront(Node* head) {
    if(head == NULL) return head;

    Node* temp = head;
    head = head -> next;
    delete temp;
    return head;
}

Node* pushBack(Node* head, int key) {
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
    return head;
}

Node* popBack(Node* head) {
    if (head == NULL) return head;
    else if (head -> next == NULL) {
        Node *delNode = head;
        head = NULL;
        delete delNode;
        return  head;
    }

    Node* cur = head;
    while(cur -> next -> next != NULL) {
        cur = cur -> next;
    }
    Node* temp = cur -> next;
    cur -> next = NULL;
    delete temp;
    return head;
}

Node* findKey(Node* head, int search_key) {
    Node* cur = head;
    while(cur != NULL) {
        if(cur -> key == search_key){
            return cur;
        }
        cur = cur -> next;
    }
    return NULL;
}

Node* eraseKey(Node* head, int key) {
    Node* cur = head;
    Node* foundNode = findKey(head, key);
    if(foundNode != NULL) {
        if(head == foundNode) {
            head = head -> next;
        }
        else {
            while(cur -> next != foundNode) {
                cur = cur -> next;
            }
            Node* tempNode = cur;
            tempNode -> next = foundNode-> next;
        }
        delete foundNode;
    }
    else {
        cout << "Key not found" << endl;
    }
    return head;
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

Node* addBefore(Node* head, Node* nextNode, int add_value) {

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
    return head;
}

void printList(Node* head) {
    Node* cur = head;
    while(cur != NULL) {
        cout<< cur -> key << " ";
        cur = cur -> next;
    }cout<<endl;
}

int main() {
    Node* head = NULL;
    for(int i=0; i<5; i++) {
        head = pushFront(head, i);
    } // 4 3 2 1 0
    cout << "After pushing(front) 5 nodes: ";
    printList(head);

    for(int i=0; i<3; i++) {
        head = popFront(head);
    } // 1 0
    cout << "After poping(front) 3 nodes: ";
    printList(head);

    for(int i=5; i<10; i++) {
        head = pushBack(head, i);
    } // 1 0 5 6 7 8 9
    cout << "After pushing(back) 5 nodes: ";
    printList(head);

    for(int i=0; i<3; i++) {
        head = popBack(head);
    } // 1 0 5 6
    cout << "After poping(back) 3 nodes: ";
    printList(head);

    Node* a = findKey(head, 5);
    printf("Address of findKey: %d\n", a);
//  cout << "address of findKey: " << a << endl;

    head = eraseKey(head, 0);
    cout << "After erasing 1 node: ";
    printList(head); // 1 5 6

    a = findKey(head, 5);
    addAfter(a, 22);
    cout << "Using addAfter: ";
    printList(head); // 1 5 22 6

    a = findKey(head, 1);
    head = addBefore(head, a, 100);
    cout << "Using addBefore: ";
    printList(head); // 100 1 5 22 6

    a = findKey(head, 5);
    head = addBefore(head, a, 88);
    cout << "Using addBefore: ";
    printList(head); // 100 1 88 5 22 6

    return 0;
}



/*
Output

After pushing(front) 5 nodes: 4 3 2 1 0
After poping(front) 3 nodes: 1 0
After pushing(back) 5 nodes: 1 0 5 6 7 8 9
After poping(back) 3 nodes: 1 0 5 6
Address of findKey: 7280944
After erasing 1 node: 1 5 6
Using addAfter: 1 5 22 6
Using addBefore: 100 1 5 22 6
Using addBefore: 100 1 88 5 22 6

*/
