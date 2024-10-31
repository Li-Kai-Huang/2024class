
# ��Ƶ��c�Ʋ߸��

## 1. �쵲��C�]Linked List�^

�쵲��C�O�@�ؽu�ʸ�Ƶ��c�A�Ѥ@�t�C�`�I�]Node�^�զ��A�C�Ӹ`�I�]�t��ƩM���V�U�@�Ӹ`�I�����СC�쵲��C���S�I�O�i�H�ʺA���t�O����A��K���J�M�R���ާ@�A���X�ݮĲv���C�C

### �쵲��C�`�I�����c

```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;    // �x�s���
    Node* next;  // ���V�U�@�Ӹ`�I������

    Node(int val) : data(val), next(nullptr) {}  // �`�I�c�y���
};
```

### �K�[�`�I

#### �b�쵲��C���Y�����J

```cpp
void insertAtHead(Node*& head, int val) {
    Node* newNode = new Node(val);  // �Ыطs�`�I
    newNode->next = head;           // �s�`�I���V�ثe���Y�`�I
    head = newNode;                 // ��s�Y�`�I���s�`�I
}
```

#### �b�쵲��C���������J

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

### �R���`�I

#### �R�����w�Ȫ��`�I

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

## 2. �G����]Binary Tree�^

�G����O�@�ؾ�θ�Ƶ��c�A�C�Ӹ`�I�̦h����Ӥl�`�I�A���O�O���l�`�I�M�k�l�`�I�C

### �G����`�I�����c

```cpp
struct TreeNode {
    int data;            // �`�I���
    TreeNode* left;      // ���l�`�I
    TreeNode* right;     // �k�l�`�I

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}  // �`�I�c�y���
};
```

### �e�ǹM���]Preorder Traversal�^

�e�ǹM�������ǬO���X�ݮڸ`�I�A�M��X�ݥ��l��A�̫�X�ݥk�l��C

```cpp
void preorderTraversal(TreeNode* root) {
    if (root != nullptr) {
        cout << root->data << " ";       // �X�ݮڸ`�I
        preorderTraversal(root->left);    // ���j�X�ݥ��l��
        preorderTraversal(root->right);   // ���j�X�ݥk�l��
    }
}
```

### ���ǹM���]Inorder Traversal�^

���ǹM�������ǬO���X�ݥ��l��A�M��X�ݮڸ`�I�A�̫�X�ݥk�l��C

```cpp
void inorderTraversal(TreeNode* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);     // ���j�X�ݥ��l��
        cout << root->data << " ";        // �X�ݮڸ`�I
        inorderTraversal(root->right);    // ���j�X�ݥk�l��
    }
}
```

### ��ǹM���]Postorder Traversal�^

��ǹM�������ǬO���X�ݥ��l��A�M��X�ݥk�l��A�̫�X�ݮڸ`�I�C

```cpp
void postorderTraversal(TreeNode* root) {
    if (root != nullptr) {
        postorderTraversal(root->left);   // ���j�X�ݥ��l��
        postorderTraversal(root->right);  // ���j�X�ݥk�l��
        cout << root->data << " ";        // �X�ݮڸ`�I
    }
}
```

### �G����M���d��

���]�G���𵲺c�p�U�G

```
    A
   / \
  B   C
 / \   \
D   E   F
```

�M�����G�G

- **�e�ǹM��**�G`A B D E C F`
- **���ǹM��**�G`D B E A C F`
- **��ǹM��**�G`D E B F C A`

### �D�{������

�H�U�d�Үi�ܦp��ЫؤG����öi��T�عM���G

```cpp
int main() {
    // �ЫؤG����
    TreeNode* root = new TreeNode('A');
    root->left = new TreeNode('B');
    root->right = new TreeNode('C');
    root->left->left = new TreeNode('D');
    root->left->right = new TreeNode('E');
    root->right->right = new TreeNode('F');

    cout << "�e�ǹM��: ";
    preorderTraversal(root);
    cout << endl;

    cout << "���ǹM��: ";
    inorderTraversal(root);
    cout << endl;

    cout << "��ǹM��: ";
    postorderTraversal(root);
    cout << endl;

    return 0;
}
```

### ���浲�G

```
�e�ǹM��: A B D E C F
���ǹM��: D B E A C F
��ǹM��: D E B F C A
```

---

�H�W���e���ѤF�쵲��C���򥻾ާ@�M�G���𪺤T�عM���覡���Բӻ����� C++ ��{�{���X�C�Ʊ�o�Ǥ��e�����U�A��n�a�z���쵲��C�M�G���𪺰򥻪��ѡI