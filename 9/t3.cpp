#include <iostream>
using namespace std;

class Node {
public:
    int playerID;
    int score;
    Node* next;

    Node(int id, int score) {
        this->playerID = id;
        this->score = score;
        this->next = NULL;
    }
};

class CircularLinkedList {
private:
    Node* tail;
    Node* current;

public:

    CircularLinkedList() {
        tail = NULL;
        current = NULL;
    }

    void addPlayer(int id, int score) {

        Node* newNode = new Node(id, score);

        if (tail == NULL) {
            tail = newNode;
            tail->next = tail;
            current = tail;
        }

        else {
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
        }

        cout << "Player " << id << " joined the game.\n";
    }

    void displayPlayers() {

        if (tail == NULL) {
            cout << "No players in the game.\n";
            return;
        }

        Node* temp = tail->next;

        cout << "\nPlayers in Game:\n";

        do {
            cout << "Player ID: " << temp->playerID
                << " | Score: " << temp->score << endl;

            temp = temp->next;

        } while (temp != tail->next);

        cout << endl;
    }

    void nextTurn() {

        if (current == NULL) {
            cout << "No players available.\n";
            return;
        }

        cout << "Current Turn: Player "
            << current->playerID << endl;

        current = current->next;
    }

    void skipPlayer() {

        if (current == NULL) {
            cout << "No players available.\n";
            return;
        }

        cout << "Skipping Player "
            << current->playerID << endl;

        current = current->next;

        cout << "Next Turn: Player "
            << current->playerID << endl;

        current = current->next;
    }

    void removePlayer(int id) {

        if (tail == NULL) {
            cout << "Game is empty.\n";
            return;
        }

        Node* curr = tail->next;
        Node* prev = tail;

        do {

            if (curr->playerID == id) {

                if (curr == tail && curr->next == tail) {

                    tail = NULL;
                    current = NULL;
                }

                else {

                    prev->next = curr->next;

                    if (curr == tail) {
                        tail = prev;
                    }

                    if (curr == current) {
                        current = curr->next;
                    }
                }

                delete curr;

                cout << "Player " << id
                    << " removed from game.\n";

                return;
            }

            prev = curr;
            curr = curr->next;

        } while (curr != tail->next);

        cout << "Player not found.\n";
    }

    bool checkWinner() {

        if (tail != NULL && tail->next == tail) {

            cout << "\nGame Over!\n";
            cout << "Winner is Player "
                << tail->playerID << endl;

            return true;
        }

        return false;
    }
};

int main() {

    CircularLinkedList game;

    game.addPlayer(101, 50);
    game.addPlayer(102, 70);
    game.addPlayer(103, 40);
    game.addPlayer(104, 90);

    game.displayPlayers();

    game.nextTurn();
    game.nextTurn();

    game.skipPlayer();

    game.removePlayer(103);
    game.displayPlayers();

    game.removePlayer(102);
    game.displayPlayers();

    game.removePlayer(104);
    game.displayPlayers();

    game.checkWinner();

    return 0;
}