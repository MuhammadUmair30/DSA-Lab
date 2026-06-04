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
        else
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

    void display()
    {
        inorder(root);
        cout << endl;
    }
};

bool isIdentical(Node* root1, Node* root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;

    if (root1 == NULL || root2 == NULL)
        return false;

    if (root1->data != root2->data)
        return false;

    return isIdentical(root1->left, root2->left) &&
        isIdentical(root1->right, root2->right);
}

int main()
{
    BST tree1, tree2;

    int values1[] = { 50, 30, 70, 20, 40, 60, 80 };
    int values2[] = { 50, 30, 70, 20, 40, 60, 80 };

    for (int i = 0; i < 7; i++)
        tree1.insert(values1[i]);

    for (int i = 0; i < 7; i++)
        tree2.insert(values2[i]);

    cout << "BST 1 (Inorder): ";
    tree1.display();

    cout << "BST 2 (Inorder): ";
    tree2.display();

    if (isIdentical(tree1.root, tree2.root))
        cout << "Both BSTs are identical." << endl;
    else
        cout << "Both BSTs are not identical." << endl;

    return 0;
}