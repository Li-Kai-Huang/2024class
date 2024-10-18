#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(int value) {
        Node* temp = new Node();
        temp->data = value;
        temp->next = nullptr;
        if (front == nullptr && rear == nullptr) {
            front = rear = temp;
        } else {
            rear->next = temp;
            rear = temp;
        }
    }

    int dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        int data = temp->data;
        delete temp;
        return data;
    }

    int peek() {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return front->data;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
        } else {
            Node* temp = front;
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.display();
    q.enqueue(20);
    q.display();
    q.dequeue();
    q.display();
    return 0;
}