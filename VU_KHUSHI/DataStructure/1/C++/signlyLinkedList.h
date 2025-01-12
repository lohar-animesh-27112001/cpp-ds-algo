#ifndef HEADER_SINGLY_LINKED_LIST
#define HEADER_SINGLY_LINKED_LIST

#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class SignlyLinkedList {
private:
    Node* head;
public:
    // TC: O(1)
    SignlyLinkedList() {
        head = NULL;
        cout << "Constructor has been successfully called" << endl;
    }
    // TC: 0(1)
    Node* accessHead() {
        return head;
    }
    // TC: O(1)
    void insertInHead(int value) {
        Node* node = new Node();
        node->data = value;
        node->next = NULL;
        node->next = head;
        head = node;
        cout << value << " pushed successfully in the head !!" << endl;
        return;
    }
    // TC: O(n)
    void insert(int value) {
        Node* node = new Node();
        node->data = value;
        node->next = NULL;
        if(head == NULL) {
            head = node;
            return;
        }
        if(head->next == NULL) {
            head->next = node;
            return;
        }
        Node* temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = node;
        return;
    }
    // TC: O(n)
    void printLinkedList() {
        if(head == NULL) {
            cout << "LinkedList is empty" << endl;
            return;
        }
        Node* temp = head;
        cout << "Linked List: ";
        while(temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
        return;
    }
    // TC: O(n)
    void deleteLinkedList() {
        Node* temp = head;
        Node* tempNext = NULL;
        while(temp != NULL) {
            tempNext = temp->next;
            delete temp;
            temp = tempNext;
        }
        head = NULL;
        cout << "Linked List deleted successfully" << endl;
        return;
    }
    // TC: O(n)
    void deleteNode(int value) {
        if(head == nullptr) {
            cout << "There is no element to delete" << endl;
            return;
        }
        if(head->data == value) {
            Node* temp = head;
            head = temp->next;
            delete temp;
            cout << value << " deleted successfully" << endl;
            return;
        }
        Node* tempPrev = head;
        Node* temp = head->next;
        while(temp != nullptr && temp->data != value) {
            tempPrev = temp;
            temp = temp->next;
        }
        if(temp == nullptr) {
            cout << "The node is not exist in the LinkedList" << endl;
            return;
        }
        tempPrev->next = temp->next;
        cout << temp->data << " deleted successfully" << endl;
        delete temp;
    }
    // TC: O(n)
    void deleteLastNode() {
        if(head == NULL) {
            cout << "There is not element to delete" << endl;
            return;
        }
        if(head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        Node* tempPrev;
        while(temp->next != NULL) {
            tempPrev = temp;
            temp = temp->next;
        }
        tempPrev->next = NULL;
        cout << temp->data << " deleted successfully" << endl;
        delete temp;
    }
};

#endif
#pragma once