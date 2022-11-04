# Binary Tree

## Binary Tree

### Height of Binary Tree (Recursive Call)
```cpp=
int FindHeight(BstNode* root) {
    if(root == NULL) {
        return -1;
    }
    else {
        return max(FindHeight(root -> left), FindHeight(root -> right)) +1;
    }
}
```
### Traversal of Binary Tree 

![](https://i.imgur.com/dBd6eqK.png)

```
Insertion of Elements (11): 30 25 28 18 23 12 50 75 39 47 42
```

* Beadth First 
    * Level Order
    (30,25,50,18,28,39,75,12,23,47,42)
* Depth First
    * Preorder (Root, Left, Right)
    (30,25,18,12,23,28,50,39,47,42,75)
    * Inorder (Left, Root, Right)
    (12,18,23,25,28,30,39,42,47,50,75)
    * Postorder (Left, Right, Root)
    (12,23,18,28,25,42,47,39,75,50,30)

```
                30
               /  \ 
             25    50 
            /  \   / \
           18  28 39 75
          / \      \
         12  23    47
                   /
                  42
```

#### Breadth First or Level Order Traversal
```cpp=
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
```

#### Depth First (Preorder) Traversal
```cpp=
void PreOrder(BstNode* root) {
    if(root == NULL) return;

    cout << root -> data << " ";
    PreOrder(root -> left);
    PreOrder(root -> right);
}
```

#### Depth First (Inorder) Traversal
```cpp=
void InOrder(BstNode* root) {
    if(root == NULL) return;

    InOrder(root -> left);
    cout << root -> data << " ";
    InOrder(root -> right);
}
```

#### Depth First (Postorder) Traversal
```cpp=
void PostOrder(BstNode* root) {
    if(root == NULL) return;

    PostOrder(root -> left);
    PostOrder(root -> right);
    cout << root -> data << " ";
}
```

### Check if Binary Search Tree
> `ref. mycodeschool`
```cpp=
bool IsSubtreeLesser(BstNode* root, int value) {
    if(root == NULL) return true;
    if(root -> data <= value
    && IsSubtreeLesser(root -> left, value)
    && IsSubtreeLesser(root -> right, value)) {
        return true;
    }
    else return false;
}

bool IsSubtreeGreater(BstNode* root, int value) {
    if(root == NULL) return true;
    if(root -> data > value
    && IsSubtreeGreater(root -> left, value)
    && IsSubtreeGreater(root -> right, value)) {
        return true;
    }
    else return false;
}

bool IsBinarySearchTree(BstNode* root) {
    if(root == NULL) return true;
    if(IsSubtreeLesser(root -> left, root -> data)
    && IsSubtreeGreater(root -> right, root -> data)
    && IsBinarySearchTree(root -> left)
    && IsBinarySearchTree(root -> right)) {
        return true;
    }
    else return false;
}

```

> `ref. mycodeschool (efficient approach)`
```cpp=
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
```

## Binary Search Tree

### Insert Element (Recursive Call)
```cpp=
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
```

### Search Element (Recursive Call)
```cpp=
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
```

### Find Node (Recursive Call)
```cpp=
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
```

### Find Minimum (Recursive Call)
```cpp=
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
```
### Find Minimum (Iterative call)
```cpp=
// Iterative call
BstNode* FindMinimum(BstNode* root) {
    while(root -> left != NULL) {
        root = root -> left;
    }
    return root;
}
```

### Find Maximum (Recursive Call) 
```cpp=
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
```

### Delete Item (Recursive Call)
```cpp=
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
```
