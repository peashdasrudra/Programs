#include <iostream>

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

class Queue
{
private:
    Node *front;
    Node *rear;

public:
    Queue()
    {
        front = nullptr;
        rear = nullptr;
    }

    bool isEmpty()
    {
        return front == nullptr;
    }

    void enqueue(int value)
    {
        Node *newNode = new Node(value);

        if (isEmpty())
        {
            front = newNode;
            rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }

        std::cout << value << " enqueued." << std::endl;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            std::cout << "Queue is empty. Cannot dequeue." << std::endl;
            return;
        }

        Node *temp = front;
        int value = temp->data;
        front = front->next;
        delete temp;

        std::cout << value << " dequeued." << std::endl;
    }

    int getFront()
    {
        if (isEmpty())
        {
            std::cout << "Queue is empty." << std::endl;
            return -1;
        }

        return front->data;
    }

    int getRear()
    {
        if (isEmpty())
        {
            std::cout << "Queue is empty." << std::endl;
            return -1;
        }

        return rear->data;
    }
};

int main()
{
    Queue queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    std::cout << "Front: " << queue.getFront() << std::endl;
    std::cout << "Rear: " << queue.getRear() << std::endl;

    queue.dequeue();

    std::cout << "Front: " << queue.getFront() << std::endl;
    std::cout << "Rear: " << queue.getRear() << std::endl;

    return 0;
}
