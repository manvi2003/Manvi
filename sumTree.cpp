#include <iostream>
using namespace std;

// A binary tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor to create a new node
    Node(int item) {
        data = item;
        left = right = nullptr;
    }
};

class BinaryTree {
public:
    Node* root;

    // Constructor for the BinaryTree
    BinaryTree() {
        root = nullptr;
    }

    // Convert a given tree to a tree where every node contains the sum of
    // values of nodes in the left and right subtrees in the original tree
    int toSumTree(Node* node) {
        if (node == nullptr)
            return 0;

        // Store the original value of the node
        int ori = node->data;

        // Recursively call for the left and right subtrees and store the sum as the new value of this node
        node->data = toSumTree(node->left) + toSumTree(node->right);

        // Return the sum of values under this subtree (including original value)
        return node->data + ori;
    }

    // A utility function to do inorder traversal of the tree
    void printInorder(Node* node) {
        if (node == nullptr)
            return;

        printInorder(node->left);
        cout << node->data << " ";
        printInorder(node->right);
    }
};

int main() {
    BinaryTree tree;

    /* Constructing tree given in the above figure */
    tree.root = new Node(10);
    tree.root->left = new Node(-2);
    tree.root->right = new Node(6);
    tree.root->left->left = new Node(8);
    tree.root->left->right = new Node(-4);
    tree.root->right->left = new Node(7);
    tree.root->right->right = new Node(5);

    // Convert the tree to a sum tree
    tree.toSumTree(tree.root);

    // Print inorder traversal of the converted tree to test result of toSumTree()
    cout << "Inorder Traversal of the resultant tree is:\n";
    tree.printInorder(tree.root);

    return 0;
}
