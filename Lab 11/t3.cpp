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

void BFS(Node* root)
{
    if (root == NULL)
    {
        cout << "Tree is empty";
        return;
    }

    Node* arr[100];
    int front = 0, rear = 0;

    arr[rear++] = root;

    while (front < rear)
    {
        Node* current = arr[front++];
        cout << current->data << " ";

        if (current->left != NULL)
        {
            arr[rear++] = current->left;
        }

        if (current->right != NULL)
        {
            arr[rear++] = current->right;
        }
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

    cout << "BFS / Level-Order Traversal: ";
    BFS(root);

    return 0;
}

//This program performs Breadth First Search(BFS), also called Level - Order Traversal, on a binary tree.In BFS, 
//the nodes are visited level by level from left to right.First, the root node is printed, then all nodes of the 
//second level, then all nodes of the third level, and so on.A queue is used in BFS because a queue works on the
//FIFO rule, which means “First In, First Out.” The first node inserted into the queue is the first one removed.In 
//the program, the root node 40 is inserted into the queue first.Then the program repeatedly removes the front 
//node from the queue, prints it, and inserts its left and right children into the queue if they exist.For the
//given tree, the traversal starts from 40, then visits 20 and 60, and after that visits 10, 30, 50, and 70. 
//Therefore, the output becomes :
//BFS / Level - Order Traversal : 40 20 60 10 30 50 70
//The condition if (root == NULL) is important because it checks whether the tree is empty.If the tree has no 
//nodes, the function stops safely without causing errors.