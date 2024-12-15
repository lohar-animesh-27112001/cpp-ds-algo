#ifndef HEADER_SINGLY_LINKED_LIST_STACK
#define HEADER_SINGLY_LINKED_LIST_STACK

#include <bits/stdc++.h>
#include "signlyLinkedList.h"

using namespace std;

// Stack : push, pop, peek/top, isEmpty, size
class StackSinglyLinkedList {
private:
    SignlyLinkedList* linkedlist;
public:
    // Constructor: will run by default
    // TC: O(1)
    StackSinglyLinkedList() {
        cout << "StackSinglyLinkedList constructor called" << endl;
        linkedlist = new SignlyLinkedList();
    }
    // TC: O(n)
    void push(int value) {
        linkedlist->insert(value);
        cout << value << " pushed" << endl;
        return;
    }
    // TC: O(n)
    void pop() {
        linkedlist->deleteLastNode();
        cout << "Poped successfully" << endl;
        return;
    }
    // TC: O(n)
    bool isEmpty() {
        if(linkedlist->accessHead() == NULL) {
            cout << "Stack is empty" << endl;
            return true;
        } else{
            cout << "Stack is not empty" << endl;
            return false;
        }
    }
    // TC: O(n)
    int peek() {
        Node* head = linkedlist->accessHead();
        if(head == NULL) {
            cout << "Stack is empty" << endl;
            return INT_MIN;
        }
        while (head->next != NULL)
        {
            head = head->next;
        }
        cout << "Last element of the stack is: " << head->data << endl;
        return head->data;
    }
    // TC: O(n)
    int size() {
        Node* head = linkedlist->accessHead();
        if(head == NULL) {
            cout << "Stack is empty" << endl;
            return 0;
        }
        int length = 0;
        while (head != NULL)
        {
            head = head->next;
            length++;
        }
        cout << "Number of element in the stack is: " << length << endl;
        return length;
    }
    // TC: O(n)
    void printStack() {
        if(linkedlist->accessHead() == NULL) {
            cout << "Stack is empty" << endl;
        }
        linkedlist->printLinkedList();
        return;
    }
    // TC: O(n)
    void deleteStack() {
        linkedlist->deleteLinkedList();
        return;
    }
    // Destructor: will run by default
    // TC: O(1)
    ~StackSinglyLinkedList() {
        delete linkedlist;
    }
};

#endif
#pragma once