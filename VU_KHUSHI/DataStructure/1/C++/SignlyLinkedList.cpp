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

// int main() {
//     // Dynamic memory allocation

//     // Singly Linked List:
//     cout << "Singly Linked List: " << endl;
//     SignlyLinkedList* ll = new SignlyLinkedList();
//     ll->insert(12);
//     ll->insert(11);
//     ll->insert(100);
//     ll->printLinkedList();
//     ll->deleteLastNode();
//     ll->printLinkedList();
//     ll->deleteNode(12);
//     ll->insert(120);
//     ll->insert(1);
//     ll->insert(3);
//     ll->printLinkedList();
//     ll->deleteLastNode();
//     ll->printLinkedList();
//     ll->deleteLinkedList();
//     ll->printLinkedList();
//     delete ll;

//     // Stack using Singly Linked List:
//     cout << "Stack using Singly Linked List: " << endl;
//     StackSinglyLinkedList* sll = new StackSinglyLinkedList();
//     sll->push(12);
//     sll->push(11);
//     sll->push(10);
//     sll->printStack();
//     sll->pop();
//     sll->printStack();
//     sll->pop();
//     sll->printStack();
//     sll->deleteStack();
//     sll->printStack();
//     delete sll;
//     return 0;
// }

#endif
#pragma once