#include <iostream>
using namespace std;

class Node {
public:
    int songID;
    string songName;
    float duration;

    Node* next;
    Node* prev;

    Node(int id, string name, float dur) {
        songID = id;
        songName = name;
        duration = dur;

        next = NULL;
        prev = NULL;
    }
};

class Playlist {
private:
    Node* head;
    Node* tail;
    Node* current;

public:

    Playlist() {
        head = NULL;
        tail = NULL;
        current = NULL;
    }

    void addSong(int id, string name, float dur) {

        Node* temp = new Node(id, name, dur);

        if (head == NULL) {
            head = tail = temp;
            current = head;
            return;
        }

        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }

    void displayPlaylist() {

        if (head == NULL) {
            cout << "Playlist is empty!\n";
            return;
        }

        Node* temp = head;

        cout << "\n----- Playlist -----\n";

        while (temp != NULL) {
            cout << "ID: " << temp->songID
                << " | Name: " << temp->songName
                << " | Duration: " << temp->duration
                << " mins\n";

            temp = temp->next;
        }

        cout << endl;
    }

    void deleteSong(string name) {

        if (head == NULL) {
            cout << "Playlist is empty!\n";
            return;
        }

        Node* temp = head;

        while (temp != NULL && temp->songName != name) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Song not found!\n";
            return;
        }

        if (temp == head) {

            head = head->next;

            if (head != NULL)
                head->prev = NULL;
            else
                tail = NULL;

            delete temp;
            cout << "Song deleted successfully!\n";
            return;
        }

        if (temp == tail) {

            tail = tail->prev;
            tail->next = NULL;

            delete temp;
            cout << "Song deleted successfully!\n";
            return;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        delete temp;

        cout << "Song deleted successfully!\n";
    }

    void playCurrent() {

        if (current == NULL) {
            cout << "No song available!\n";
            return;
        }

        cout << "\nNow Playing: "
            << current->songName
            << " (" << current->duration << " mins)\n";
    }

    void playNext() {

        if (current == NULL) {
            cout << "Playlist is empty!\n";
            return;
        }

        if (current->next == NULL) {
            cout << "Already at last song!\n";
            return;
        }

        current = current->next;

        playCurrent();
    }

    void playPrevious() {

        if (current == NULL) {
            cout << "Playlist is empty!\n";
            return;
        }

        if (current->prev == NULL) {
            cout << "Already at first song!\n";
            return;
        }

        current = current->prev;

        playCurrent();
    }

    void reversePlaylist() {

        if (head == NULL) {
            return;
        }

        Node* currentNode = head;
        Node* temp = NULL;

        while (currentNode != NULL) {

            temp = currentNode->prev;
            currentNode->prev = currentNode->next;
            currentNode->next = temp;

            currentNode = currentNode->prev;
        }

        temp = head;
        head = tail;
        tail = temp;

        cout << "\nPlaylist reversed successfully!\n";
    }
};

int main() {

    Playlist p;

    p.addSong(1, "Shape of You", 4.2);
    p.addSong(2, "Blinding Lights", 3.5);
    p.addSong(3, "Perfect", 4.8);
    p.addSong(4, "Believer", 3.9);

    p.displayPlaylist();

    p.playCurrent();

    p.playNext();
    p.playNext();

    p.playPrevious();

    p.deleteSong("Perfect");

    p.displayPlaylist();

    p.reversePlaylist();

    p.displayPlaylist();

    return 0;
}