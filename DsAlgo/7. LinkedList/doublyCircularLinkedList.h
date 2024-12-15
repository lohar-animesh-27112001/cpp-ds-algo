#ifndef HEADER_DOUBLY_CIRCULAR_LINKED_LIST
#define HEADER_DOUBLY_CIRCULAR_LINKED_LIST

#include <bits/stdc++.h>

using namespace std;

class DoublyNode {
public:
    int data;
    DoublyNode* next;
    DoublyNode* prev;
};

class DoublyCircularLinkedList {
private:
    DoublyNode* head;
public:
    DoublyCircularLinkedList() {
        cout << "DoublyCircularLinkedList constructor called !!" << endl;
        head = NULL;
    }

    DoublyNode* accessHead() {
        return head;
    }

    void insert(int value) {
        DoublyNode* node = new DoublyNode();
        node->data = value;

        if (head == NULL) {
            node->next = node;
            node->prev = node;
            head = node;
        } else {
            DoublyNode* tail = head->prev;

            node->next = head;
            node->prev = tail;
            tail->next = node;
            head->prev = node;
        }
        cout << value << " inserted successfully !!" << endl;
    }

    void insertAtHead(int value) {
        insert(value);
        head = head->prev;
    }

    void deleteNode(int value) {
        if (head == NULL) {
            cout << "There is no element to delete in the LinkedList" << endl;
            return;
        }

        DoublyNode* temp = head;
        do {
            if (temp->data == value) break;
            temp = temp->next;
        } while (temp != head);

        if (temp->data != value) {
            cout << "The node of value: " << value << " does not exist in the LinkedList !!" << endl;
            return;
        }

        if (temp->next == temp) {
            delete temp;
            head = NULL;
        } else {
            DoublyNode* prev = temp->prev;
            DoublyNode* next = temp->next;

            prev->next = next;
            next->prev = prev;

            if (temp == head) head = next;

            delete temp;
        }
        cout << value << " deleted successfully !!" << endl;
    }

    void deleteHead() {
        if (head == NULL) {
            cout << "There is no element to delete in the LinkedList" << endl;
            return;
        }
        deleteNode(head->data);
    }

    void deleteLastNode() {
        if (head == NULL) {
            cout << "There is no element to delete in the LinkedList" << endl;
            return;
        }
        deleteNode(head->prev->data);
    }

    int countNode() {
        if(head == NULL) {
            cout << "Doubly Circular Linked List is empty !!" << endl;
            return 0;
        }
        int count = 1;
        DoublyNode* temp = head;
        while(temp->next != head) {
            temp = temp->next;
            count++;
        }
        cout << "Number of nodes in the DoublyCircularSingly Linked List is: " << count << endl;
        return count;
    }

    void printDCLL() {
        if (head == NULL) {
            cout << "There is no element to print in the LinkedList" << endl;
            return;
        }
        cout << "[ ";
        cout << head->data << " -> ";
        DoublyNode* temp = head->next;
        while(temp != head) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL ]" << endl;
        return;
    }

    void deleteLinkedList() {
        if (head == NULL) {
            cout << "There is no element to delete in the LinkedList" << endl;
            return;
        }
        while (head != NULL) {
            deleteNode(head->data);
        }
        cout << "LinkedList deleted successfully !!" << endl;
    }
};

#endif
#pragma once