#include <iostream>

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BST {
private:
    TreeNode* root;

    void insert(TreeNode*& node, int value) {
        if (node == nullptr) {
            node = new TreeNode(value);
        } else if (value < node->data) {
            insert(node->left, value);
        } else {
            insert(node->right, value);
        }
    }

    void inorderTraversal(TreeNode* node) const {
        if (node != nullptr) {
            inorderTraversal(node->left);
            std::cout << node->data << " ";
            inorderTraversal(node->right);
        }
    }

public:
    BST() : root(nullptr) {}

    void insert(int value) {
        insert(root, value);
    }

    void inorder() const {
        inorderTraversal(root);
        std::cout << std::endl;
    }
};

int main() {
    BST tree;
    int value;

    //std::cout << "請輸入整數（輸入 0 結束）：\n";
    //while (true) {
        std::cout << "輸入數字: ";
        for(int i=0 ; i<8; i++){
        std::cin >> value;

        /*if (value == 0) {
            break;  // 結束輸入
        }*/

        tree.insert(value);
        }
    //}

    std::cout << "中序遍歷結果: ";
    tree.inorder();  // 輸出中序遍歷結果

    return 0;
}
