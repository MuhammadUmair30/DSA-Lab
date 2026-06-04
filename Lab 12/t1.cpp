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

class BST
{
public:
    Node* root;

    BST()
    {
        root = NULL;
    }

    Node* insert(Node* root, int value)
    {
        if (root == NULL)
            return new Node(value);

        if (value < root->data)
            root->left = insert(root->left, value);
        else if (value > root->data)
            root->right = insert(root->right, value);

        return root;
    }

    void insert(int value)
    {
        root = insert(root, value);
    }

    void inorder(Node* root)
    {
        if (root == NULL)
            return;

        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    void preorder(Node* root)
    {
        if (root == NULL)
            return;

        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }

    void postorder(Node* root)
    {
        if (root == NULL)
            return;

        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }

    bool search(Node* root, int key)
    {
        if (root == NULL)
            return false;

        if (root->data == key)
            return true;

        if (key < root->data)
            return search(root->left, key);

        return search(root->right, key);
    }
};

int main()
{
    BST tree;

    int n, value;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter values: ";
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        tree.insert(value);
    }

    cout << "\nInorder Traversal: ";
    tree.inorder(tree.root);

    cout << "\nPreorder Traversal: ";
    tree.preorder(tree.root);

    cout << "\nPostorder Traversal: ";
    tree.postorder(tree.root);

    int key;
    cout << "\n\nEnter key to search: ";
    cin >> key;

    if (tree.search(tree.root, key))
        cout << "Key found in BST";
    else
        cout << "Key not found in BST";

    return 0;
}