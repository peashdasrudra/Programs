#include <iostream>
using namespace std;

// Node structure for linked list
struct Node
{
    int data;
    Node *next;
};

// Insert a new node at the beginning of the list
void insertAtBeginning(Node **head, int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
    cout << "Node with data " << data << " inserted at the beginning of the list." << endl;
}

// Insert a new node after a given node
void insertAfter(Node *prevNode, int data)
{
    if (prevNode == nullptr)
    {
        cout << "Previous node cannot be null." << endl;
        return;
    }
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
    cout << "Node with data " << data << " inserted after node with data " << prevNode->data << "." << endl;
}

// Delete a node with a given key
void deleteNode(Node **head, int key)
{
    Node *temp = *head, *prev = nullptr;

    if (temp != nullptr && temp->data == key)
    {
        *head = temp->next;
        delete temp;
        cout << "Node with data " << key << " deleted from the list." << endl;
        return;
    }

    while (temp != nullptr && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        cout << "Node with data " << key << " not found in the list." << endl;
        return;
    }

    prev->next = temp->next;
    delete temp;
    cout << "Node with data " << key << " deleted from the list." << endl;
}

// Search for a node with a given key
void search(Node *head, int key)
{
    Node *temp = head;
    int pos = 0;

    while (temp != nullptr && temp->data != key)
    {
        temp = temp->next;
        pos++;
    }

    if (temp == nullptr)
    {
        cout << "Node with data " << key << " not found in the list." << endl;
    }
    else
    {
        cout << "Node with data " << key << " found at position " << pos << "." << endl;
    }
}

// Print the linked list
void printList(Node *node)
{
    cout << "Linked list: ";
    while (node != nullptr)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

// Create a linked list from an array
Node *createListFromArray(int arr[], int n)
{
    Node *head = nullptr;
    for (int i = n - 1; i >= 0; i--)
    {
        insertAtBeginning(&head, arr[i]);
    }
    return head;
}

// Main function
int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Create a linked list from the array
    Node *head = createListFromArray(arr, n);
}
// Print the linked list

Enter the number of elements in the array : 5 Enter the elements of the array : 1 2 3 4 5

    Node with data 1 inserted at the beginning of the list.Node with data 2 inserted at the beginning of the list.Node with data 3 inserted at the beginning of the list.Node with data 4 inserted at the beginning of the list.Node with data 5 inserted at the beginning of the list.Linked list : 5 4 3 2 1
