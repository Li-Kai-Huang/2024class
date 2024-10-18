#include <iostream>

template <typename T>
class Node
{
public:
    T data;
    Node *next;

    Node(T value) : data(value), next(nullptr) {}
};

template <typename T>
class LinkedListStack
{
private:
    Node<T> *top;

public:
    LinkedListStack() : top(nullptr) {}

    ~LinkedListStack()
    {
        while (!isEmpty())
        {
            pop();
        }
    }

    void push(T value)
    {
        Node<T> *newNode = new Node<T>(value);
        newNode->next = top;
        top = newNode;
    }

    void pop()
    {
        if (isEmpty())
        {
            std::cerr << "Stack underflow" << std::endl;
            return;
        }
        Node<T> *temp = top;
        top = top->next;
        delete temp;
    }

    T peek()
    {
        if (isEmpty())
        {
            std::cerr << "Stack is empty" << std::endl;
            throw std::runtime_error("Stack is empty");
        }
        return top->data;
    }

    bool isEmpty()
    {
        return top == nullptr;
    }

    void display()
    {
        Node<T> *current = top;
        while (current != nullptr)
        {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main()
{
    LinkedListStack<int> stack;

    // 將10個數值放入堆疊
    for (int i = 1; i <= 10; ++i)
    {
        stack.push(i);
    }

    std::cout << "Stack elements after pushing 10 elements: ";
    stack.display();

    // 取出11個數值
    for (int i = 0; i < 11; ++i)
    {
        stack.pop();
        std::cout << "Stack elements after popping 11 elements: ";
        stack.display();
    }

    return 0;
}