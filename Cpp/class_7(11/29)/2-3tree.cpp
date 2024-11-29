#include <iostream>
#include <algorithm>
using namespace std;

class Node {
public:
    int keys[3]; // Array to store keys
    Node* children[4]; // Array to store child pointers
    int numKeys; // Number of keys in the node

    Node() {
        numKeys = 0;
        for (int i = 0; i < 4; i++) {
            children[i] = nullptr;
        }
    }
};

class TwoThreeTree {
private:
    Node* root;

    // 插入鍵到節點中
    void insert(Node*& node, int key) {
        if (node == nullptr) {
            node = new Node();
            node->keys[0] = key;
            node->numKeys = 1;
        } else {
            if (node->numKeys < 2) {
                node->keys[node->numKeys] = key;
                node->numKeys++;
                sort(node->keys, node->keys + node->numKeys);
            } else {
                // 處理節點分裂
                Node* newNode = new Node();
                int tempKeys[3] = {node->keys[0], node->keys[1], key};
                sort(tempKeys, tempKeys + 3);

                newNode->keys[0] = tempKeys[2];
                newNode->numKeys = 1;

                node->keys[0] = tempKeys[0];
                node->keys[1] = tempKeys[1];
                node->numKeys = 2;

                if (node == root) {
                    Node* newRoot = new Node();
                    newRoot->keys[0] = tempKeys[1];
                    newRoot->numKeys = 1;
                    newRoot->children[0] = node;
                    newRoot->children[1] = newNode;
                    root = newRoot;
                } else {
                    // 將新節點插入到父節點中
                    insertIntoParent(node, newNode, tempKeys[1]);
                }
            }
        }
    }

    // 將新節點插入到父節點中
    void insertIntoParent(Node* left, Node* right, int key) {
        if (left == root) {
            Node* newRoot = new Node();
            newRoot->keys[0] = key;
            newRoot->numKeys = 1;
            newRoot->children[0] = left;
            newRoot->children[1] = right;
            root = newRoot;
        } else {
            Node* parent = findParent(root, left);
            if (parent->numKeys < 2) {
                parent->keys[parent->numKeys] = key;
                parent->numKeys++;
                sort(parent->keys, parent->keys + parent->numKeys);

                for (int i = 0; i < parent->numKeys; i++) {
                    if (parent->keys[i] == key) {
                        for (int j = parent->numKeys; j > i + 1; j--) {
                            parent->children[j] = parent->children[j - 1];
                        }
                        parent->children[i + 1] = right;
                        break;
                    }
                }
            } else {
                // 處理父節點分裂
                Node* newParent = new Node();
                int tempKeys[3] = {parent->keys[0], parent->keys[1], key};
                sort(tempKeys, tempKeys + 3);

                newParent->keys[0] = tempKeys[2];
                newParent->numKeys = 1;

                parent->keys[0] = tempKeys[0];
                parent->keys[1] = tempKeys[1];
                parent->numKeys = 2;

                Node* tempChildren[4] = {parent->children[0], parent->children[1], parent->children[2], right};
                sort(tempChildren, tempChildren + 4, [tempKeys](Node* a, Node* b) {
                    return a->keys[0] < b->keys[0];
                });

                for (int i = 0; i < 2; i++) {
                    parent->children[i] = tempChildren[i];
                }
                for (int i = 2; i < 4; i++) {
                    newParent->children[i - 2] = tempChildren[i];
                }

                if (parent == root) {
                    Node* newRoot = new Node();
                    newRoot->keys[0] = tempKeys[1];
                    newRoot->numKeys = 1;
                    newRoot->children[0] = parent;
                    newRoot->children[1] = newParent;
                    root = newRoot;
                } else {
                    insertIntoParent(parent, newParent, tempKeys[1]);
                }
            }
        }
    }

    // 查找父節點
    Node* findParent(Node* root, Node* child) {
        if (root == nullptr || root == child) {
            return nullptr;
        }

        for (int i = 0; i <= root->numKeys; i++) {
            if (root->children[i] == child) {
                return root;
            }
            Node* parent = findParent(root->children[i], child);
            if (parent != nullptr) {
                return parent;
            }
        }
        return nullptr;
    }

    // 中序遍歷
    void inOrder(Node* node) {
        if (node != nullptr) {
            for (int i = 0; i < node->numKeys; i++) {
                inOrder(node->children[i]);
                cout << node->keys[i] << " ";
            }
            inOrder(node->children[node->numKeys]);
        }
    }

public:
    TwoThreeTree() {
        root = nullptr;
    }

    void insert(int key) {
        insert(root, key);
    }

    void inOrder() {
        inOrder(root);
        cout << endl;
    }
};

int main() {
    TwoThreeTree tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(5);
    tree.insert(6);
    tree.insert(12);
    tree.insert(30);
    tree.insert(7);
    tree.insert(17);

    cout << "Inorder traversal of the constructed 2-3 tree is:\n";
    tree.inOrder();

    return 0;
}