#include <bits/stdc++.h>
#include "signlyLinkedList.h"
#include "stackLinkedList.h"
// #include "queueLinkedList.h"
#include "doublyCircularLinkedList.h"

using namespace std;

int main() {
    // Dynamic memory allocation

    // Singly Linked List:
    cout << "Singly Linked List: " << endl;
    SignlyLinkedList* ll = new SignlyLinkedList();
    ll->insert(12);
    ll->insert(11);
    ll->insert(100);
    ll->printLinkedList();
    ll->deleteLastNode();
    ll->printLinkedList();
    ll->deleteNode(12);
    ll->insert(120);
    ll->insert(1);
    ll->insert(3);
    ll->printLinkedList();
    ll->deleteLastNode();
    ll->printLinkedList();
    ll->deleteLinkedList();
    ll->printLinkedList();
    delete ll;

    cout << "=================================" << endl;

    // Stack using Singly Linked List:
    cout << "Stack using Singly Linked List: " << endl;
    StackSinglyLinkedList* sll = new StackSinglyLinkedList();
    sll->push(12);
    sll->push(11);
    sll->push(10);
    sll->printStack();
    sll->pop();
    sll->printStack();
    sll->pop();
    sll->printStack();
    sll->deleteStack();
    sll->printStack();
    delete sll;

    cout << "=================================" << endl;

    // Doubly Circular Singly Linked List:
    cout << "Doubly-Circular-Singly Linked List: " << endl;
    DoublyCircularLinkedList* dcll = new DoublyCircularLinkedList();
    dcll->insert(10);
    dcll->insert(20);
    dcll->insertAtHead(5);
    dcll->insertAtHead(11);
    dcll->insert(99);
    dcll->insertAtHead(112);
    dcll->printDCLL();
    dcll->deleteNode(20);
    dcll->countNode();
    dcll->printDCLL();
    dcll->deleteHead();
    dcll->printDCLL();
    dcll->deleteLastNode();
    dcll->printDCLL();
    dcll->deleteLinkedList();
    dcll->printDCLL();
    delete dcll;
    return 0;
}