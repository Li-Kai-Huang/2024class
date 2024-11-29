#include <iostream>
using namespace std;

// 節點結構
struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
};

// 創建新節點
Node* newNode(int key) {
    Node* node = new Node();
    node->key = key;
    node->left = node->right = nullptr;
    node->height = 1; // 新節點的高度初始化為1
    return node;
}

// 獲取節點高度
int height(Node* node) {
    if (node == nullptr)
        return 0;
    return node->height;
}

// 獲取節點的平衡因子
int getBalance(Node* node) {
    if (node == nullptr)
        return 0;
    return height(node->left) - height(node->right);
}

// 右旋轉
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // 執行旋轉
    x->right = y;
    y->left = T2;

    // 更新高度
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // 返回新的根節點
    return x;
}

// 左旋轉
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // 執行旋轉
    y->left = x;
    x->right = T2;

    // 更新高度
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // 返回新的根節點
    return y;
}
// 前序遍歷
void preOrder(Node* root) {
    if (root) {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
// 插入節點
Node* insert(Node* node, int key) {
    // 1. 執行標準的BST插入
    if (node == nullptr)
        return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else // 重複的鍵不允許
        return node;
    cout << "Preorder traversal of the constructed AVL tree is \n";
    preOrder(node);
    cout << endl ;
    // 2. 更新節點的高度
    node->height = 1 + max(height(node->left), height(node->right));

    // 3. 獲取節點的平衡因子，檢查是否需要平衡
    int balance = getBalance(node);

    // 如果節點不平衡，則有四種情況

    // 左左情況
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // 右右情況
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // 左右情況
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // 右左情況
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // 返回節點指針
    return node;
}



// 中序遍歷
void inOrder(Node* root) {
    if (root) {
        inOrder(root->left);
        cout << root->key << " ";
        inOrder(root->right);
    }
}

// 後序遍歷
void postOrder(Node* root) {
    if (root) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->key << " ";
    }
}

int main() {
    Node* root = nullptr;

    // 插入節點
    root = insert(root, 50);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 30);
    root = insert(root, 45);
    root = insert(root, 42);

    // 輸出前序遍歷結果
    cout << "Preorder traversal of the constructed AVL tree is \n";
    preOrder(root);
    cout << endl;

    // 輸出中序遍歷結果
    cout << "Inorder traversal of the constructed AVL tree is \n";
    inOrder(root);
    cout << endl;

    // 輸出後序遍歷結果
    cout << "Postorder traversal of the constructed AVL tree is \n";
    postOrder(root);
    cout << endl;

    return 0;
}