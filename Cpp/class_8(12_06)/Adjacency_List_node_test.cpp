#include <bits/stdc++.h>
using namespace std ;
class Node {
public:
    int value;
    Node* next ;
        Node (int value){
            this -> value = value ;
            next = nullptr;
        }
    
};

int main() {
    Node* head[6]; // 指針陣列
    for (int i = 0; i < 6; i++) {
        head[i] = nullptr; // 初始化指針為 nullptr
    }

    int data[14][2] = {{1, 2}, {1, 5}, {2, 1}, {2, 3}, {2, 4}, {3, 2}, {3, 4},
                       {3, 5}, {4, 2}, {4, 3}, {4, 5}, {5, 1}, {5, 3}, {5, 4}};

    // 建立相鄰表
    for (int i = 0; i < 14; i++) {
        int src = data[i][0];
        int dest = data[i][1];
        Node* newNode = new Node(dest);
        newNode->next = head[src];
        head[src] = newNode;
    }

    // 顯示相鄰表
    for (int i = 1; i <= 5; i++) {
        cout << "Adjacency list of vertex " << i << ": ";
        Node* temp = head[i];
        while (temp != nullptr) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    return 0;
}