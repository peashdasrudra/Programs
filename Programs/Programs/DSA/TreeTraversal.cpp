#include <iostream>

using namespace std;

// Definition of a binary tree node
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Preorder traversal { Root -> Left -> Right }
void preorderTraversal(Node *root)
{
    if (root == nullptr)
        return;

    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Inorder traversal: Left -> Root -> Right
void inorderTraversal(Node *root)
{
    if (root == nullptr)
        return;

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

// Postorder traversal: Left -> Right -> Root
void postorderTraversal(Node *root)
{
    if (root == nullptr)
        return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

int main()
{
    // Creating a binary tree
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "Preorder traversal: ";
    preorderTraversal(root);
    cout << endl;


    cout << "Inorder traversal: ";
    inorderTraversal(root);
    cout << endl;


    cout << "Postorder traversal: ";
    postorderTraversal(root);
    cout << endl;

}
