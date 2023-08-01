#include <iostream>
using namespace std;

// Creating node for linkedlist
class Node
{
public:
    int data;
    Node *next;
};

// Creating linklist
class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    // Insert node at a certain position
    void insert(int data, int pos)
    {
        Node *newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;

        if (pos == 0)
        {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node *curr = head;
        for (int i = 0; i < pos - 1 && curr != nullptr; i++)
        {
            curr = curr->next;
        }
        if (curr == nullptr)
        {
            cout << "Invalid position!" << endl;
            return;
        }
        newNode->next = curr->next;
        curr->next = newNode;
    }

    // Delete node at a certain position
    void deleteNode(int pos)
    {
        if (head == nullptr)
        {
            cout << "List is empty!" << endl;
            return;
        }

        if (pos == 0)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node *curr = head;
        Node *prev = nullptr;
        for (int i = 0; i < pos && curr != nullptr; i++)
        {
            prev = curr;
            curr = curr->next;
        }
        if (curr == nullptr)
        {
            cout << "Invalid position!" << endl;
            return;
        }
        prev->next = curr->next;
        delete curr;
    }

    // Traverse the linked list and print its elements
    void traverse()
    {
        Node *curr = head;
        while (curr != nullptr)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    // Search for a certain element and return its position
    int search(int data)
    {
        Node *curr = head;
        int pos = 0;
        while (curr != nullptr)
        {
            if (curr->data == data)
            {
                return pos;
            }
            curr = curr->next;
            pos++;
        }
        return -1;
    }
};

int main()
{
    LinkedList list;

    // Insert nodes at certain positions
    list.insert(10, 0);
    list.insert(20, 1);
    list.insert(30, 2);
    list.insert(40, 3);
    list.insert(50, 4);
    list.insert(60, 5);

    // Print the linked list
    cout << "Linked list after insertion: ";
    list.traverse();

    // Delete a node at a certain position
    list.deleteNode(2);

    // Print the linked list
    cout << "Linked list after deletion: ";
    list.traverse();

    // Search for an element and print its position
    int pos = list.search(40);
    if (pos == -1)
    {
        cout << "Element not found!" << endl;
    }
    else
    {
        cout << "Element found at position " << pos << endl;
    }

    return 0;
}
