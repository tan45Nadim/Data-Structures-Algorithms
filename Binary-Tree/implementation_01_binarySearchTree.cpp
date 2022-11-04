#include <iostream>
#include <queue>
using namespace std;

struct BstNode {
    int data;
    BstNode* left;
    BstNode* right;
};

BstNode* CreateNewNode(int data) {
    BstNode* newNode = new BstNode();
    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}

BstNode* Insert(BstNode* root, int data) {
    if (root == NULL) {
        root = CreateNewNode(data);
    }
    else if (data <= root -> data) {
        root -> left = Insert(root -> left, data);
    }
    else {
        root -> right = Insert(root -> right, data);
    }
    return root;
}

bool Search(BstNode* root, int searchValue) {
    if(root == NULL) {
        return false;
    }
    else if (root -> data == searchValue) {
        return true;
    }
    else if (root -> data >= searchValue) {
        return Search(root -> left, searchValue);
    }
    else {
        return Search(root -> right, searchValue);
    }
}

void LevelOrder(BstNode* root) {
    if(root == NULL) return;
    queue <BstNode*> Q;
    Q.push(root);
    while(!Q.empty()) {
        BstNode* current = Q.front();
        Q.pop();
        cout << current -> data << " ";

        if(current -> left != NULL)
            Q.push(current -> left);
        if(current -> right != NULL)
            Q.push(current -> right);
    }
}

void PreOrder(BstNode* root) {
    if(root == NULL) return;

    cout << root -> data << " ";
    PreOrder(root -> left);
    PreOrder(root -> right);

}

void PostOrder(BstNode* root) {
    if(root == NULL) return;

    PostOrder(root -> left);
    PostOrder(root -> right);
    cout << root -> data << " ";
}

void InOrder(BstNode* root) {
    if(root == NULL) return;

    InOrder(root -> left);
    cout << root -> data << " ";
    InOrder(root -> right);
}

int FindMinimum(BstNode* root) {
    if(root == NULL) {
        cout << "Error: Empty Tree!" << endl;
        return -1;
    }
    else if(root -> left == NULL) {
        return root -> data;
    }
    return FindMinimum(root -> left);
}

// Iterative call
BstNode* FindMin(BstNode* root) {
    while(root -> left != NULL) {
        root = root -> left;
    }
    return root;
}

int FindMaximum(BstNode* root) {
    if(root == NULL) {
        cout << "Error: Empty Tree!" << endl;
        return -1;
    }
    else if(root -> right == NULL) {
        return root -> data;
    }
    return FindMaximum(root -> right);
}

BstNode* FindNode(BstNode *root, int data) {
    if(root == NULL) {
        return NULL;
    }
    else if(root -> data == data) {
        return root;
    }
    else if(root -> data > data) {
        return FindNode(root -> left, data);
    }
    else {
        return FindNode(root -> right, data);
    }
}

int FindHeight(BstNode* root) {
    if(root == NULL) {
        return -1;
    }
    else {
        return max(FindHeight(root -> left), FindHeight(root -> right)) +1;
    }
}

BstNode* DeleteItem(BstNode* root, int data) {
    if(root == NULL) return root;
    else if(data < root -> data)
        root -> left = DeleteItem(root -> left, data);
    else if(data > root -> data)
        root -> right = DeleteItem(root -> right, data);
    else {
        //case 1: No Child
        if(root -> left == NULL && root -> right == NULL) {
            delete root;
            root = NULL;
        }
        //case 2: One Child
        else if(root -> left == NULL) {
            BstNode* temp = root;
            root = root -> right;
            delete temp;
        }
        else if(root -> right == NULL) {
            BstNode* temp = root;
            root = root -> left;
            delete temp;
        }
        //case 3: Two Children
        else {
            BstNode* temp = FindMin(root -> right);
            root -> data = temp -> data;
            root -> right = DeleteItem(root -> right, temp -> data);
        }
    }
    return root;
}

int main() {
    BstNode* root = NULL;

    cout << "How many number to Insert : ";
    int n; cin >> n;

    cout << "Enter " << n << " number : ";
    for(int i=0; i<n; i++) {
        int x; cin >> x;
        root = Insert(root, x);
    }

    cout << "\nLevelOrder: ";
    LevelOrder(root);
    cout << "\nPostOrder : ";
    PostOrder(root);
    cout << "\nPreOrder  : ";
    PreOrder(root);
    cout << "\nInOrder   : ";
    InOrder(root);

    int num;
    cout << "\n\nEnter a number to search : ";
    cin >> num;

    if(Search(root, num))
        cout << num << " is Found" << endl;
    else
        cout << num << " is Not Found" << endl;


    int mini = FindMinimum(root);
    cout << "\nMinimum value: " << mini << endl;

    int maxi = FindMaximum(root);
    cout << "Maximum value: " << maxi << endl;

    int height = FindHeight(root);
    cout << "Height: " << height << endl;

    cout << "Enter a number to find Node: ";
    int i; cin >> i;
    BstNode* fn = FindNode(root,i);
    cout << "Find Node: " <<fn << endl;

    cout << "Enter a Number for Delete: ";
    int d; cin >> d;
    root = DeleteItem(root, d);
    cout << "After delete InOrder: ";
    InOrder(root);

    return 0;
}


/*
Output:

How many number to Insert : 11
Enter 11 number : 30 25 28 18 23 12 50 75 39 47 42

LevelOrder: 30 25 50 18 28 39 75 12 23 47 42
PostOrder : 12 23 18 28 25 42 47 39 75 50 30
PreOrder  : 30 25 18 12 23 28 50 39 47 42 75
InOrder   : 12 18 23 25 28 30 39 42 47 50 75

Enter a number to search : 55
55 is Not Found

Minimum value: 12
Maximum value: 75
Height: 4
Enter a number to find Node: 23
Find Node: 0xfa5ad0
Enter a Number for Delete: 23
After delete InOrder: 12 18 25 28 30 39 42 47 50 75

*/
