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

class StackNode
{
public:
    Node* treeNode;
    StackNode* next;
};

class Stack
{
    StackNode* topNode;

public:
    Stack()
    {
        topNode = NULL;
    }

    void push(Node* node)
    {
        StackNode* newNode = new StackNode;
        newNode->treeNode = node;
        newNode->next = topNode;
        topNode = newNode;
    }

    Node* pop()
    {
        if (topNode == NULL)
            return NULL;

        StackNode* temp = topNode;
        Node* node = temp->treeNode;
        topNode = topNode->next;
        delete temp;
        return node;
    }

    bool isEmpty()
    {
        return topNode == NULL;
    }
};

void DFS(Node* root)
{
    if (root == NULL)
    {
        cout << "Tree is empty";
        return;
    }

    Stack s;
    s.push(root);

    while (!s.isEmpty())
    {
        Node* current = s.pop();
        cout << current->data << " ";

        if (current->right != NULL)
            s.push(current->right);

        if (current->left != NULL)
            s.push(current->left);
    }
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

    cout << "DFS Traversal: ";
    DFS(root);

    return 0;
}

//This program performs DFS traversal without using the built - in stack library.Instead, a custom stack is created
//using linked list nodes.The stack stores tree nodes and works on the LIFO rule, which means the last inserted 
//node is removed first.
//The root node 40 is pushed into the stack first.Then the program repeatedly removes the top node, prints it, and
//pushes its children.The right child is pushed before the left child so that the left child is processed first.
//The traversal follows the order :
//Root->Left->Right
//So the output becomes :
//DFS Traversal : 40 20 10 30 60 50 70