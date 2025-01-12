#ifndef QUEUE_LINKED_LIST
#define QUEUE_LINKED_LIST

#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class QueueLinkedList {
private:
    Node* head;
    Node* tail;
    int queueSize;

public:
    QueueLinkedList() : head(nullptr), tail(nullptr), queueSize(0) {}

    QueueLinkedList(int value) : head(new Node(value)), tail(head), queueSize(1) {
        cout << value << " inserted successfully at the head!" << endl;
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        queueSize++;
        cout << value << " inserted successfully!" << endl;
    }

    void dequeue() {
        if (head == nullptr) {
            cout << "Queue is empty, nothing to delete!" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head == nullptr) {
            tail = nullptr;
        }
        cout << "Deleted: " << temp->data << endl;
        delete temp;
        queueSize--;
    }

    int getFront() const {
        if (head == nullptr) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        cout << "Front element is: " << head->data << endl;
        return head->data;
    }

    int getRear() const {
        if (tail == nullptr) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        cout << "Rear element is: " << tail->data << endl;
        return tail->data;
    }

    bool isEmpty() const {
        if (queueSize == 0) {
            cout << "Queue is empty!" << endl;
            return true;
        }
        cout << "Queue is not empty!" << endl;
        return false;
    }

    int size() const {
        cout << "Number of elements in the queue: " << queueSize << endl;
        return queueSize;
    }

    void printQueue() {
        Node* temp = head;
        cout << "[ Head -> ";
        while(temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL ]" << endl;
    }

    ~QueueLinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        cout << "Queue deleted successfully!" << endl;
    }
};

#endif // QUEUE_LINKED_LIST
#pragma once