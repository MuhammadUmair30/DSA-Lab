#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }

    void insertAtHead(int data) {
        Node* temp = new Node(data);

        if (head == NULL) {
            head = tail = temp;
            return;
        }

        temp->next = head;
        head->prev = temp;
        head = temp;
    }

    void insertAtTail(int data) {
        Node* temp = new Node(data);

        if (head == NULL) {
            head = tail = temp;
            return;
        }

        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }

    void insertAtPosition(int pos, int data) {

        if (pos == 1) {
            insertAtHead(data);
            return;
        }

        Node* temp = head;
        int cnt = 1;

        while (cnt < pos - 1) {
            temp = temp->next;
            cnt++;
        }

        if (temp == NULL) {
            cout << "Invalid Position!" << endl;
            return;
        }

        if (temp->next == NULL) {
            insertAtTail(data);
            return;
        }

        Node* nodeToInsert = new Node(data);

        nodeToInsert->next = temp->next;
        temp->next->prev = nodeToInsert;

        temp->next = nodeToInsert;
        nodeToInsert->prev = temp;
    }

    void deleteByValue(int value) {

        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;

        while (temp != NULL && temp->data != value) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Value not found!" << endl;
            return;
        }

        if (temp == head) {
            head = head->next;

            if (head != NULL)
                head->prev = NULL;
            else
                tail = NULL;

            delete temp;
            return;
        }

        if (temp == tail) {
            tail = tail->prev;
            tail->next = NULL;

            delete temp;
            return;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        delete temp;
    }

    void displayForward() {

        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;

        cout << "Forward Traversal: ";

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    void displayReverse() {

        if (tail == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = tail;

        cout << "Reverse Traversal: ";

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->prev;
        }

        cout << endl;
    }
};

int main() {

    DoublyLinkedList list;

    list.insertAtHead(10);
    list.insertAtTail(20);
    list.insertAtTail(30);
    list.insertAtPosition(2, 15);

    cout << "List after insertions:" << endl;
    list.displayForward();
    list.displayReverse();

    list.deleteByValue(15);

    cout << "\nList after deletion of 15:" << endl;
    list.displayForward();
    list.displayReverse();

    return 0;
}