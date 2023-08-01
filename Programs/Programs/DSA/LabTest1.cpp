#include <bits/stdc++.h>
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

    // Insert node at the end
    void insertAtEnd(int data)
    {
        Node *newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *curr = head;
            while (curr->next != nullptr)
            {
                curr = curr->next;
            }
            curr->next = newNode;
        }
    }

    // Inserting at beginning
    void insertAtBeginning(int data)
    {
        Node *newNode = new Node;
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }

    // Inerting in middle
    void insertAtMiddle(int data)
    {
        Node *newNode = new Node;
        newNode->data = data;
        Node *slow = head;
        Node *fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        newNode->next = slow->next;
        slow->next = newNode;
    }

    // Inserting the array
    void insertArray(int arr[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > 0)
            {
                insertAtEnd(arr[i]);
            }
            else if (arr[i] < 0)
            {
                insertAtBeginning(arr[i]);
            }
            else
            {
                insertAtMiddle(arr[i]);
            }
        }
    }

    // Print the linked list in the correct order
    void print()
    {
        Node *curr = head;
        cout << "The List is: ";
        while (curr != nullptr)
        {

            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    LinkedList list;
    list.insertArray(arr, n);
    list.print();
    return 0;
}
