#include <iostream>
#include <string>
using namespace std;

class BSTNode
{
public:
    int isbn;
    string title;
    BSTNode* left;
    BSTNode* right;

    BSTNode(int i, string t)
    {
        isbn = i;
        title = t;
        left = NULL;
        right = NULL;
    }
};

class ListNode
{
public:
    int isbn;
    string title;
    ListNode* next;

    ListNode(int i, string t)
    {
        isbn = i;
        title = t;
        next = NULL;
    }
};

class BST
{
public:
    BSTNode* root;

    BST()
    {
        root = NULL;
    }

    BSTNode* insert(BSTNode* root, int isbn, string title)
    {
        if (root == NULL)
            return new BSTNode(isbn, title);

        if (isbn < root->isbn)
            root->left = insert(root->left, isbn, title);
        else
            root->right = insert(root->right, isbn, title);

        return root;
    }

    void insert(int isbn, string title)
    {
        root = insert(root, isbn, title);
    }
};

void convertToList(BSTNode* root, ListNode*& head, ListNode*& tail)
{
    if (root == NULL)
        return;

    convertToList(root->left, head, tail);

    ListNode* newNode = new ListNode(root->isbn, root->title);

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }

    convertToList(root->right, head, tail);
}

void printList(ListNode* head)
{
    while (head != NULL)
    {
        cout << "ISBN: " << head->isbn
            << "  Title: " << head->title << endl;
        head = head->next;
    }
}

int main()
{
    BST library;

    library.insert(105, "Data Structures");
    library.insert(101, "Programming Fundamentals");
    library.insert(120, "Database Systems");
    library.insert(110, "Operating Systems");
    library.insert(103, "Object Oriented Programming");
    library.insert(130, "Computer Networks");

    ListNode* head = NULL;
    ListNode* tail = NULL;

    convertToList(library.root, head, tail);

    cout << "Library Catalog (Sorted by ISBN)" << endl;
    printList(head);

    return 0;
}