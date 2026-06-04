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

    Node* findMin(Node* root)
    {
        while (root->left != NULL)
            root = root->left;

        return root;
    }

    Node* deleteNode(Node* root, int key)
    {
        if (root == NULL)
            return NULL;

        if (key < root->data)
        {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->data)
        {
            root->right = deleteNode(root->right, key);
        }
        else
        {
            if (root->left == NULL && root->right == NULL)
            {
                delete root;
                return NULL;
            }

            if (root->left == NULL)
            {
                Node* temp = root->right;
                delete root;
                return temp;
            }

            if (root->right == NULL)
            {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            Node* successor = findMin(root->right);
            root->data = successor->data;
            root->right = deleteNode(root->right, successor->data);
        }

        return root;
    }

    void deleteValue(int key)
    {
        root = deleteNode(root, key);
    }
};

int main()
{
    BST tree;

    int n, value;

    cout << "Enter number of nodes: ";
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

    int delKey;
    cout << "\n\nEnter key to delete: ";
    cin >> delKey;

    tree.deleteValue(delKey);

    cout << "\nBST after deletion (Inorder): ";
    tree.inorder(tree.root);

    return 0;
}