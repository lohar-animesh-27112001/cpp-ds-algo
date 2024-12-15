#ifndef HEADER_SINGLY_LINKED_LIST_QUEUE
#define HEADER_SINGLY_LINKED_LIST_QUEUE

#include <bits/stdc++.h>
#include "signlyLinkedList.h"

using namespace std;

class QueueSinglyLinkedList {
private:
    SignlyLinkedList* linkedlist;
public:
    // TC: O(1)
    QueueSinglyLinkedList() {
        cout << "QueueSinglyLinkedList constructor called" << endl;
        linkedlist = new SignlyLinkedList();
    }
    // TC: O(1)
    void enqueue(int value) {
        linkedlist->insert(value);
        cout << value << " pushed successfully in the Queue" << endl;
        return;
    }
    // TC: O(n)
    void dequeue() {
        if(linkedlist->accessHead() == NULL) {
            cout << "There is no element to delete in the Queue" << endl;
            return;
        } else {
            linkedlist->deleteNode(linkedlist->accessHead()->data);
            return;
        }
    }
    // TC: O(1)
    Node* getHead() {
        if(linkedlist->accessHead() == NULL) {
            cout << "In the queue, there are not element !!" << endl;
        } else {
            cout << "The head element of the Queue is: " << linkedlist->accessHead()->data << endl;
        }
        return linkedlist->accessHead();
    }
    // TC: O(n)
    void printQueue() {
        if(linkedlist->accessHead() == NULL) {
            cout << "Queue is empty" << endl;
        }
        linkedlist->printLinkedList();
        return;
    }
    // TC: O(n)
    int size() {
        Node* head = linkedlist->accessHead();
        if(head == NULL) {
            cout << "Queue is empty" << endl;
            return 0;
        }
        int length = 0;
        while (head != NULL)
        {
            head = head->next;
            length++;
        }
        cout << "Number of element in the Queue is: " << length << endl;
        return length;
    }
    // TC: O(n)
    void deleteQueue() {
        linkedlist->deleteLinkedList();
        return;
    }
    // Destructor: will run by default
    // TC: O(1)
    ~QueueSinglyLinkedList() {
        delete linkedlist;
    }
};

#endif
#pragma once