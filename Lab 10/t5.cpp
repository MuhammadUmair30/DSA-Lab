#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

class SinglyLinkedList
{
    Node* head;

    void printRecursive(Node* temp)
    {
        if (temp == NULL)
        {
            cout << endl;
            return;
        }

        cout << temp->data << " ";
        printRecursive(temp->next);
    }

    Node* insertAtBeginningRecursive(Node* head, int value)
    {
        Node* newNode = new Node(value);
        newNode->next = head;
        return newNode;
    }

    Node* insertAtEndRecursive(Node* head, int value)
    {
        if (head == NULL)
        {
            return new Node(value);
        }

        head->next = insertAtEndRecursive(head->next, value);
        return head;
    }

    Node* insertAtPositionRecursive(Node* head, int value, int position)
    {
        if (position < 1)
            return head;

        if (position == 1)
        {
            Node* newNode = new Node(value);
            newNode->next = head;
            return newNode;
        }

        if (head == NULL)
            return head;

        head->next = insertAtPositionRecursive(head->next, value, position - 1);
        return head;
    }

    Node* deleteByValueRecursive(Node* head, int value)
    {
        if (head == NULL)
            return NULL;

        if (head->data == value)
        {
            Node* temp = head->next;
            delete head;
            return temp;
        }

        head->next = deleteByValueRecursive(head->next, value);
        return head;
    }

    Node* deleteAtPositionRecursive(Node* head, int position)
    {
        if (head == NULL || position < 1)
            return head;

        if (position == 1)
        {
            Node* temp = head->next;
            delete head;
            return temp;
        }

        head->next = deleteAtPositionRecursive(head->next, position - 1);
        return head;
    }

    int searchRecursive(Node* head, int value, int position)
    {
        if (head == NULL)
            return -1;

        if (head->data == value)
            return position;

        return searchRecursive(head->next, value, position + 1);
    }

public:
    SinglyLinkedList()
    {
        head = NULL;
    }

    void insertAtBeginning(int value)
    {
        head = insertAtBeginningRecursive(head, value);
        print();
    }

    void insertAtEnd(int value)
    {
        head = insertAtEndRecursive(head, value);
        print();
    }

    void insertAtPosition(int value, int position)
    {
        head = insertAtPositionRecursive(head, value, position);
        print();
    }

    void deleteByValue(int value)
    {
        head = deleteByValueRecursive(head, value);
        print();
    }

    void deleteAtPosition(int position)
    {
        head = deleteAtPositionRecursive(head, position);
        print();
    }

    int search(int value)
    {
        return searchRecursive(head, value, 1);
    }

    void print()
    {
        printRecursive(head);
    }
};

int main()
{
    SinglyLinkedList list;

    list.insertAtBeginning(10);
    list.insertAtBeginning(5);

    list.insertAtEnd(20);
    list.insertAtEnd(30);

    list.insertAtPosition(15, 3);

    list.deleteByValue(20);

    list.deleteAtPosition(2);

    cout << list.search(15) << endl;
    cout << list.search(100) << endl;

    list.print();

    return 0;
}