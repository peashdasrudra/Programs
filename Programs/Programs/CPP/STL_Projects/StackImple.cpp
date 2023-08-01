#include <iostream>
using namespace std;
// Node class for the linked list
class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};
// Stack class using a linked list
class Stack
{
private:
    Node *top; // Pointer to the top node of the stack
public:
    Stack()
    {
        top = NULL;
    }

    void push(int val)
    {
        Node *newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }
    void pop()
    {
        if (top == NULL)
        {
            cout << "Stack is empty" << endl;
            return;
        }
        Node *temp = top;
        top = top->next;
        delete temp;
    }
    int peek()
    {
        if (top == NULL)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return top->data;
    }
    bool isEmpty()
    {
        return top == NULL;
    }
};
int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);

    s.push(4);
    cout << "Stack is empty? " << s.isEmpty() << endl;
    cout << "Top element: " << s.peek() << endl;
    s.pop();
    cout << "Top element after pop: " << s.peek() << endl;
    s.pop();
    s.pop();
    s.pop();
    cout << "Stack is empty? " << s.isEmpty() << endl;
    s.pop();
    return 0;
}


1 2 3 4

Output:
Stack is empty? 0
Top element: 4
Top element after pop: 3
Stack is empty? 1
Stack is empty

