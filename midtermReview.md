
# 資料結構複習資料

## 1. 鏈結串列（Linked List）

鏈結串列是一種線性資料結構，由一系列節點（Node）組成，每個節點包含資料和指向下一個節點的指標。鏈結串列的特點是可以動態分配記憶體，方便插入和刪除操作，但訪問效率較低。

### 鏈結串列節點的結構

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;    // 儲存資料
    Node* next;  // 指向下一個節點的指標

    Node(int val) : data(val), next(nullptr) {}  // 節點構造函數
};
```

### 添加節點

#### 在鏈結串列的頭部插入

```cpp
void insertAtHead(Node*& head, int val) {
    Node* newNode = new Node(val);  // 創建新節點
    newNode->next = head;           // 新節點指向目前的頭節點
    head = newNode;                 // 更新頭節點為新節點
}
```

#### 在鏈結串列的尾部插入

```cpp
void insertAtTail(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}
```

### 刪除節點

#### 刪除指定值的節點

```cpp
void deleteNode(Node*& head, int val) {
    if (head == nullptr) return;
    if (head->data == val) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr && temp->next->data != val) {
        temp = temp->next;
    }
    if (temp->next != nullptr) {
        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }
}
```

---

## 2. 二元樹（Binary Tree）

二元樹是一種樹形資料結構，每個節點最多有兩個子節點，分別是左子節點和右子節點。

### 二元樹節點的結構

```cpp
struct TreeNode {
    int data;            // 節點資料
    TreeNode* left;      // 左子節點
    TreeNode* right;     // 右子節點

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}  // 節點構造函數
};
```

### 前序遍歷（Preorder Traversal）

前序遍歷的順序是先訪問根節點，然後訪問左子樹，最後訪問右子樹。

```cpp
void preorderTraversal(TreeNode* root) {
    if (root != nullptr) {
        cout << root->data << " ";       // 訪問根節點
        preorderTraversal(root->left);    // 遞迴訪問左子樹
        preorderTraversal(root->right);   // 遞迴訪問右子樹
    }
}
```

### 中序遍歷（Inorder Traversal）

中序遍歷的順序是先訪問左子樹，然後訪問根節點，最後訪問右子樹。

```cpp
void inorderTraversal(TreeNode* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);     // 遞迴訪問左子樹
        cout << root->data << " ";        // 訪問根節點
        inorderTraversal(root->right);    // 遞迴訪問右子樹
    }
}
```

### 後序遍歷（Postorder Traversal）

後序遍歷的順序是先訪問左子樹，然後訪問右子樹，最後訪問根節點。

```cpp
void postorderTraversal(TreeNode* root) {
    if (root != nullptr) {
        postorderTraversal(root->left);   // 遞迴訪問左子樹
        postorderTraversal(root->right);  // 遞迴訪問右子樹
        cout << root->data << " ";        // 訪問根節點
    }
}
```

### 二元樹遍歷範例

假設二元樹結構如下：

```
    A
   / \
  B   C
 / \   \
D   E   F
```

遍歷結果：

- **前序遍歷**：`A B D E C F`
- **中序遍歷**：`D B E A C F`
- **後序遍歷**：`D E B F C A`

### 主程式測試

以下範例展示如何創建二元樹並進行三種遍歷：

```cpp
int main() {
    // 創建二元樹
    TreeNode* root = new TreeNode('A');
    root->left = new TreeNode('B');
    root->right = new TreeNode('C');
    root->left->left = new TreeNode('D');
    root->left->right = new TreeNode('E');
    root->right->right = new TreeNode('F');

    cout << "前序遍歷: ";
    preorderTraversal(root);
    cout << endl;

    cout << "中序遍歷: ";
    inorderTraversal(root);
    cout << endl;

    cout << "後序遍歷: ";
    postorderTraversal(root);
    cout << endl;

    return 0;
}
```

### 執行結果

```
前序遍歷: A B D E C F
中序遍歷: D B E A C F
後序遍歷: D E B F C A
```

---

以上內容提供了鏈結串列的基本操作和二元樹的三種遍歷方式的詳細說明及 C++ 實現程式碼。希望這些內容能幫助你更好地理解鏈結串列和二元樹的基本知識！