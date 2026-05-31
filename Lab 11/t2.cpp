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

int main()
{
    Node* root = new Node(40);

    root->left = new Node(20);
    root->right = new Node(60);

    root->left->left = new Node(10);
    root->left->right = new Node(30);

    root->right->left = new Node(50);
    root->right->right = new Node(70);

    cout << "Inorder Traversal: ";
    inorder(root);

    cout << endl;

    cout << "Preorder Traversal: ";
    preorder(root);

    cout << endl;

    return 0;
}

//This program performs recursive inorder and preorder traversal on a binary tree.A binary tree is a structure in 
//which each node can have two children : a left child and a right child.In the program, each node stores a value 
//and pointers to its left and right children.The tree used in the program contains the values 40, 20, 60, 10, 30, 
//50, and 70 arranged in tree form.The inorder traversal works with the rule Left->Root->Right.This means the 
//program first visits the left side of the tree, then prints the current node, and finally visits the right side.
//By following this rule, the output becomes 10 20 30 40 50 60 70. The function uses recursion, which means the 
//function calls itself again and again for smaller parts of the tree until no node is left.The preorder traversal 
//follows the rule Root->Left->Right.In this method, the program first prints the current node, then moves to the 
//left subtree, and after that to the right subtree.For the given tree, the preorder output is 40 20 10 30 60 50 70.
//Here, the root node is printed before its children.Recursion is useful in tree traversal because a tree is made 
//of smaller subtrees, so the same function can be used repeatedly for each part of the tree.The condition root ==
//NULL is very important because it tells the function when to stop.Without this condition, the function would keep
//calling itself forever and the program would crash.