#include <iostream>
using namespace std;

// Node definition for Binary Search Tree
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to insert a new node into the BST
Node *insert(Node *root, int val)
{
    if (root == nullptr)
    {
        return new Node(val);
    }

    if (val < root->data)
    {
        root->left = insert(root->left, val);
    }
    else
    {
        root->right = insert(root->right, val);
    }

    return root;
}

// Function to find the minimum node in the BST
Node *findMin(Node *root)
{
    while (root->left != nullptr)
    {
        root = root->left;
    }
    return root;
}

// Function to delete a node from the BST
Node *deleteNode(Node *root, int val)
{
    if (root == nullptr)
    {
        return root;
    }

    if (val < root->data)
    {
        root->left = deleteNode(root->left, val);
    }
    else if (val > root->data)
    {
        root->right = deleteNode(root->right, val);
    }
    else
    {
        // Node with only one child or no child
        if (root->left == nullptr)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        Node *temp = findMin(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to print the inorder traversal of the BST
void inorderTraversal(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main()
{
    Node *root = nullptr;

    int n, val;
    cout << "Enter the number of elements in the Binary Search Tree: ";
    cin >> n;

    cout << "Enter the elements of the Binary Search Tree:\n";
    for (int i = 0; i < n; ++i)
    {
        cin >> val;
        root = insert(root, val);
    }

    cout << "Inorder traversal (Before Deletion): ";
    inorderTraversal(root);

    int valueToDelete;
    cout << "\nEnter a value to delete : ";
    cin >> valueToDelete;

    root = deleteNode(root, valueToDelete);

    cout << "Inorder traversal (After deletion): ";
    inorderTraversal(root);

}
