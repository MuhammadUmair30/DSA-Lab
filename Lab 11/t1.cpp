#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

class BinaryTree
{
public:
    Node* root;

    BinaryTree()
    {
        root = NULL;
    }

    void printLeafNodes(Node* node)
    {
        if (node == NULL)
            return;

        if (node->left == NULL && node->right == NULL)
        {
            cout << node->data << " ";
            return;
        }

        printLeafNodes(node->left);
        printLeafNodes(node->right);
    }
};

int main()
{
    BinaryTree tree;

    tree.root = new Node(40);

    Node* node20 = new Node(20);
    Node* node60 = new Node(60);
    Node* node10 = new Node(10);
    Node* node30 = new Node(30);
    Node* node50 = new Node(50);
    Node* node70 = new Node(70);

    tree.root->left = node20;
    tree.root->right = node60;

    node20->left = node10;
    node20->right = node30;

    node60->left = node50;
    node60->right = node70;

    cout << "Root Node: " << tree.root->data << endl;
    cout << "Left Child of Root: " << tree.root->left->data << endl;
    cout << "Right Child of Root: " << tree.root->right->data << endl;

    cout << "Leaf Nodes: ";
    tree.printLeafNodes(tree.root);

    return 0;
}