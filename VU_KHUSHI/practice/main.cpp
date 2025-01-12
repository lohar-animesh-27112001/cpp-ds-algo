#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
};

class CircularDoublyLinkedList {
private:
    Node* head;
public:
    CircularDoublyLinkedList() {
        head = NULL;
    }

    void insertNode(int value) {
        Node* node = new Node();
        node->data = value;
        node->next = NULL;
        node->prev = NULL;

        if (head == NULL) {
            head = node;
            node->next = head;
            node->prev = head;
            return;
        }

        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }

        temp->next = node;
        node->prev = temp;
        node->next = head;
        head->prev = node;
    }

    void deleteNode(int value) {
        if (head == NULL) {
            cout << "The linked list is empty." << endl;
            return;
        }

        Node* temp = head;

        while (temp->data != value) {
            temp = temp->next;
            if (temp == head) {
                cout << "The value does not exist in the linked list." << endl;
                return;
            }
        }

        if (temp->next == temp) {
            delete temp;
            head = NULL;
            return;
        }

        Node* tempPrev = temp->prev;
        Node* tempNext = temp->next;

        tempPrev->next = tempNext;
        tempNext->prev = tempPrev;

        if (temp == head) {
            head = tempNext;
        }

        delete temp;
    }

    void printLinkedList() {
        if (head == NULL) {
            cout << "The linked list is empty." << endl;
            return;
        }

        Node* temp = head;
        cout << "Linked list: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    void deleteLinkedList() {
        if (head == NULL) return;

        Node* node = head;
        Node* nodeNext;

        do {
            nodeNext = node->next;
            delete node;
            node = nodeNext;
        } while (node != head);

        head = NULL;
    }
};

int main() {
    CircularDoublyLinkedList* ll = new CircularDoublyLinkedList();
    ll->insertNode(12);
    ll->insertNode(11);
    ll->insertNode(10);
    ll->printLinkedList();

    ll->deleteNode(11);
    ll->printLinkedList();

    ll->deleteLinkedList();
    ll->printLinkedList();

    delete ll;
}
