#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prev;

    Node(int d)
    {
        data = d;
        next = NULL;
        prev = NULL;
    }
};

class DoublyLinkedList
{
    Node* head;

    void printForwardRecursive(Node* temp)
    {
        if (temp == NULL)
        {
            cout << endl;
            return;
        }

        cout << temp->data << " ";
        printForwardRecursive(temp->next);
    }

    void printReverseRecursive(Node* temp)
    {
        if (temp == NULL)
            return;

        printReverseRecursive(temp->next);
        cout << temp->data << " ";
    }

    Node* insertAtBeginningRecursive(Node* head, int value)
    {
        Node* newNode = new Node(value);

        newNode->next = head;

        if (head != NULL)
            head->prev = newNode;

        return newNode;
    }

    Node* insertAtEndRecursive(Node* head, int value)
    {
        if (head == NULL)
            return new Node(value);

        head->next = insertAtEndRecursive(head->next, value);

        if (head->next != NULL)
            head->next->prev = head;

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

            if (head != NULL)
                head->prev = newNode;

            return newNode;
        }

        if (head == NULL)
            return head;

        head->next = insertAtPositionRecursive(head->next, value, position - 1);

        if (head->next != NULL)
            head->next->prev = head;

        return head;
    }

    Node* deleteByValueRecursive(Node* head, int value)
    {
        if (head == NULL)
            return NULL;

        if (head->data == value)
        {
            Node* temp = head->next;

            if (temp != NULL)
                temp->prev = NULL;

            delete head;
            return temp;
        }

        head->next = deleteByValueRecursive(head->next, value);

        if (head->next != NULL)
            head->next->prev = head;

        return head;
    }

    Node* deleteAtPositionRecursive(Node* head, int position)
    {
        if (head == NULL || position < 1)
            return head;

        if (position == 1)
        {
            Node* temp = head->next;

            if (temp != NULL)
                temp->prev = NULL;

            delete head;
            return temp;
        }

        head->next = deleteAtPositionRecursive(head->next, position - 1);

        if (head->next != NULL)
            head->next->prev = head;

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

    bool palindromeRecursive(Node*& left, Node* right)
    {
        if (right == NULL)
            return true;

        bool check = palindromeRecursive(left, right->next);

        if (!check)
            return false;

        bool same = (left->data == right->data);

        left = left->next;

        return same;
    }

public:
    DoublyLinkedList()
    {
        head = NULL;
    }

    void insertAtBeginning(int value)
    {
        head = insertAtBeginningRecursive(head, value);
    }

    void insertAtEnd(int value)
    {
        head = insertAtEndRecursive(head, value);
    }

    void insertAtPosition(int value, int position)
    {
        head = insertAtPositionRecursive(head, value, position);
    }

    void deleteByValue(int value)
    {
        head = deleteByValueRecursive(head, value);
    }

    void deleteAtPosition(int position)
    {
        head = deleteAtPositionRecursive(head, position);
    }

    int search(int value)
    {
        return searchRecursive(head, value, 1);
    }

    void printForward()
    {
        printForwardRecursive(head);
    }

    void printReverse()
    {
        printReverseRecursive(head);
        cout << endl;
    }

    bool isPalindrome()
    {
        Node* left = head;
        return palindromeRecursive(left, head);
    }
};

int main()
{
    DoublyLinkedList list;

    list.insertAtBeginning(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);
    list.insertAtEnd(2);
    list.insertAtEnd(1);

    list.printForward();
    list.printReverse();

    cout << list.search(3) << endl;

    list.deleteByValue(3);
    list.printForward();

    list.insertAtPosition(3, 3);
    list.printForward();

    if (list.isPalindrome())
        cout << "Palindrome" << endl;
    else
        cout << "Not Palindrome" << endl;

    return 0;
}