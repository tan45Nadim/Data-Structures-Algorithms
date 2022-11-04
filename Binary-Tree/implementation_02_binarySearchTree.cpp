#include <iostream>
#include <queue>
using namespace std;

struct BstNode {
    int data;
    BstNode* left;
    BstNode* right;
};

BstNode* getNewNode(int data) {
    BstNode* newNode = new BstNode();
    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}

bool IsBstUtil(BstNode* root, int minValue, int maxValue) {
    if(root == NULL) return true;
    if(root -> data > minValue && root -> data < maxValue
    && IsBstUtil(root -> left, minValue, root -> data)
    && IsBstUtil(root ->right, root -> data, maxValue)) {
        return true;
    }
    else return false;
}

bool IsBinarySearchTree(BstNode* root) {
    return IsBstUtil(root, INT_MIN, INT_MAX);
}


int main() {
    BstNode* root = NULL;

    root = getNewNode(100);
    BstNode* node1 = getNewNode(50);
    BstNode* node2 = getNewNode(200);
    BstNode* node3 = getNewNode(10);
    BstNode* node4 = getNewNode(150);
    BstNode* node5 = getNewNode(170);
    BstNode* node6 = getNewNode(160);
    BstNode* node7 = getNewNode(220);

    root -> left = node1;
    root -> right = node2;
    node1 -> left = node3;
    node2 -> left = node4;
    node2 -> right = node7;
    node4 -> right = node5;
    node5 -> left = node6;


    bool isbst = IsBinarySearchTree(root);
    if(isbst)
        cout << "This Binary Tree is a Binary Search Tree." << endl;
    else
        cout << "This Binary Tree is NOT a Binary Search Tree." << endl;
  
    return 0;
}


//             100
//            /   \
//           50   200
//          /    /   \
//         10   150  220
//                \
//                170
//               /
//              160          

/*
Output:

This Binary Tree is a Binary Search Tree.
*/
