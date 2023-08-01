#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree {
private:
    Node* root;

public:
    BinaryTree() {
        root = nullptr;
    }

    void insert(int value) {
        Node* newNode = new Node(value);

        if (root == nullptr) {
            root = newNode;
            return;
        }

        Node* curr = root;
        while (true) {
            if (value <= curr->data) {
                if (curr->left == nullptr) {
                    curr->left = newNode;
                    break;  // Break the loop after inserting the node
                }
                curr = curr->left;
            } else {
                if (curr->right == nullptr) {
                    curr->right = newNode;
                    break;  // Break the loop after inserting the node
                }
                curr = curr->right;
            }
        }
    }

    void traverse() {
        traverseTree(root);
    }

private:
    void traverseTree(Node* node) {
        if (node == nullptr)
            return;

        std::cout << node->data << " ";
        traverseTree(node->left);
        traverseTree(node->right);
    }
};

int main() {
    BinaryTree tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(1);
    tree.insert(4);

    std::cout << "Tree traversal: ";
    tree.traverse();
    std::cout << std::endl;

    return 0;
}
