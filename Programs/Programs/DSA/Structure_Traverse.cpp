#include <iostream>

using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Function to insert a node at the end of the linked list
void insert(Node** head, int value) {
    // Create a new node
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;
    
    // If the list is empty, make the new node the head
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    // Traverse to the end of the list
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    // Insert the new node at the end of the list
    temp->next = newNode;
}

// Function to traverse and print the linked list
void traverse(Node* head) {
    if (head == NULL) {
        cout << "The list is empty." << endl;
        return;
    }
    
    cout << "The list is: ";
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;
    
    // Prompt user to enter values for the linked list
    int numValues;
    cout << "How many values do you want to add to the list? ";
    cin >> numValues;
    
    for (int i = 0; i < numValues; i++) {
        int value;
        cout << "Enter value #" << i+1 << ": ";
        cin >> value;
        insert(&head, value);
    }
    
    traverse(head);
    
    return 0;
}
