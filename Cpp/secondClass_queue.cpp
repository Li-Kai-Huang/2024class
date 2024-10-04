/*
我的queue是使用環形的  在初始化時 front = -1 rear = -1 
但我在執行 enqueue 時如果front = -1時會變front = 0
執行dequeue 函數:從隊列中取出元素，並更新 front 和 size 如果隊列變空，重置 front 和 rear。
然後用size去記錄長度 判斷重疊時是空還是滿 

我是使用的是github copilot

*/ 

#include <bits/stdc++.h>
#include <iostream>
#define MAX 20
using namespace std ;

class CircularQueue {
private:
    int arr[MAX];
    int front, rear, size;

public:
    CircularQueue() : front(-1), rear(-1), size(0) {}

    bool isFull() {
        return (size == MAX);
    }

    bool isEmpty() {
        return (size == 0);
    }

    bool enqueue(int x) {
        if (isFull()) {
            cout << "Queue Overflow\n";
            return false;
        } else {
            rear = (rear + 1) % MAX;
            arr[rear] = x;
            if (front == -1) front = 0;
            size++;
            return true;
        }
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return -1;
        } else {
            int x = arr[front];
            front = (front + 1) % MAX;
            size--;
            if (size == 0) {
                front = rear = -1; // Reset the queue
            }
            return x;
        }
    }

    vector<int> getQueueContents() {
        vector<int> contents;
        if (!isEmpty()) {
            int i = front;
            for (int count = 0; count < size; count++) {
                contents.push_back(arr[i]);
                i = (i + 1) % MAX;
            }
        }
        return contents;
    }
};

int main() {
    CircularQueue myQueue;

    // 將0到19放入隊列
    for (int i = 0; i < 20; ++i) {
        myQueue.enqueue(i);
    }



    // 從隊列中取出並顯示
    while (!myQueue.isEmpty()) {
        cout << myQueue.dequeue() << " ";
    }
    myQueue.enqueue(8);


        // 顯示佇列內容
    vector<int> contents = myQueue.getQueueContents();
    cout << "Queue contents: ";
    for (int val : contents) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}