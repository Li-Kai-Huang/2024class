#include <bits/stdc++.h>
#define imax 7
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data = 0, Node *next = nullptr)
    {
        this->data = data;
        this->next = next;
    }
};

class Hash_linklist
{
public:
    Node *indextable[imax];
    Hash_linklist()
    {
        for (int i = 0; i < imax; i++)
        {
            indextable[i] = nullptr;
        }
    }

    // 哈希函數
    int hashFunction(int key)
    {
        return key % imax;
    }
    // 插入資料
    void Add_Data(int val)
    {
        int index = hashFunction(val);
        Node *newNode = new Node(val);
        newNode->next = indextable[index];
        indextable[index] = newNode;
    }
    // 顯示哈希鏈表
    void display()
    {
        for (int i = 0; i < imax; i++)
        {
            cout << "Index " << i << ": ";
            Node *temp = indextable[i];
            while (temp != nullptr)
            {
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << "nullptr" << endl;
        }
    }
};

int main()
{
    Hash_linklist hashTable;

    // 插入15個資料
    vector<int> data = {5, 13,56,78,92,35,67,112,44,6,890,123,111,23,222};
    for (int val : data)
    {
        hashTable.Add_Data(val);
    }

    // 顯示哈希鏈表
    hashTable.display();

    return 0;
}
