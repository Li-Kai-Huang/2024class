#include <bits/stdc++.h>
using namespace std ;

class Stack {
private:
    static const int MAX = 20; // 堆疊的最大容量
    int arr[MAX]; // 用來儲存堆疊元素的陣列
    int top; // 指向堆疊頂端的索引

public:
    Stack() : top(-1) {} // 建構子，初始化 top 為 -1，表示堆疊是空的

    bool push(int x) {
        if (top >= (MAX - 1)) {
            cout << "Stack Overflow"; // 堆疊滿了，無法再加入元素
            return false;
        } else {
            arr[++top] = x; // 將元素 x 放入堆疊，並更新 top
            return true;
        }
    }

    int pop() {
        if (top < 0) {
            cout << "Stack Underflow"; // 堆疊是空的，無法取出元素
            return 0;
        } else {
            int x = arr[top--]; // 取出堆疊頂端的元素，並更新 top
            return x;
        }
    }

    int peek() {
        if (top < 0) {
            cout << "Stack is Empty"; // 堆疊是空的，無法查看頂端元素
            return 0;
        } else {
            return arr[top]; // 返回堆疊頂端的元素，但不移除它
        }
    }

    bool isEmpty() {
        return (top < 0); // 檢查堆疊是否為空
    }
};int main() {
    Stack myStack;

    // 將0到19放入堆疊
    for (int i = 0; i < 20; ++i) {
        myStack.push(i);
    }

    // 從堆疊中取出並顯示
    while (!myStack.isEmpty()) {
        cout << myStack.peek() << " ";
        myStack.pop();
    }

    return 0;
}