#ifndef HEADER6_H
#define HEADER6_H

#include <bits/stdc++.h>
#include "heapNode.h"
#include "queueArray.h"

using namespace std;

#endif
#pragma once

class MINheap {
private:
    Heap_Node* root;
    int size;

public:
    MINheap() : root(nullptr), size(0) {}

    MINheap(int value) : root(nullptr), size(0) {
        insertNode(value);
    }

    int insertNode(int value) {
        if (root == nullptr) {
            root = new (nothrow) Heap_Node;
            if (!root) {
                cerr << "Memory allocation failed!" << endl;
                return -1;
            }
            root->data = value;
            root->leftChild = nullptr;
            root->rightChild = nullptr;
            root->parent = nullptr;
            cout << "Pushed in index: " << size << endl;
            size++;
            return 1;
        }

        int height = floor(log2(size)) + 1;
        int number_elements = pow(2, height - 1);
        int last_row_elements = size - number_elements + 1;

        Heap_Node* tempNode = root;

        if (number_elements == last_row_elements) {
            while (tempNode->leftChild != nullptr) {
                if (tempNode->data > value) {
                    swap(tempNode->data, value);
                }
                tempNode = tempNode->leftChild;
            }
            Heap_Node* newNode = new (nothrow) Heap_Node;
            if (!newNode) {
                cerr << "Memory allocation failed!" << endl;
                return -1;
            }
            tempNode->leftChild = newNode;
            newNode->data = value;
            newNode->leftChild = nullptr;
            newNode->rightChild = nullptr;
            newNode->parent = tempNode;
            cout << "Pushed in index: " << size << endl;
            size++;
            return 0;
        }

        for (int i = 0; i < height; i++) {
            if (last_row_elements >= (number_elements / 2)) {
                if (tempNode->rightChild == nullptr) {
                    Heap_Node* newNode = new (nothrow) Heap_Node;
                    if (!newNode) {
                        cerr << "Memory allocation failed!" << endl;
                        return -1;
                    }
                    newNode->data = value;
                    newNode->leftChild = nullptr;
                    newNode->rightChild = nullptr;
                    newNode->parent = tempNode;

                    tempNode->rightChild = newNode;
                    cout << "Pushed in index: " << size << endl;
                    size++;
                    return 0;
                }
                if (tempNode->data > value) {
                    swap(tempNode->data, value);
                }

                tempNode = tempNode->rightChild;
                last_row_elements -= (number_elements / 2);
            } else {
                if (tempNode->leftChild == nullptr) {
                    Heap_Node* newNode = new (nothrow) Heap_Node;
                    if (!newNode) {
                        cerr << "Memory allocation failed!" << endl;
                        return -1;
                    }
                    newNode->data = value;
                    newNode->leftChild = nullptr;
                    newNode->rightChild = nullptr;
                    newNode->parent = tempNode;

                    tempNode->leftChild = newNode;
                    cout << "Pushed in index: " << size << endl;
                    size++;
                    return 0;
                }
                if (tempNode->data > value) {
                    swap(tempNode->data, value);
                }
                tempNode = tempNode->leftChild;
            }
            number_elements /= 2;
        }

        return 0;
    }

    Heap_Node* searchNode(int value) {
        Heap_Node* getNode = nullptr;
        searchNode(root, value, getNode);
        if (getNode == nullptr)
            cout << "Element is not present in the tree!" << endl;
        else
            cout << "Element found in the tree. Value: " << getNode->data << endl;
        return getNode;
    }

    void decreaseKey(int value, int newValue) {
        Heap_Node* node = searchNode(value);
        if(node == NULL) return;
        node->data = newValue;
        adjustNode(node);
        cout << "Node of value " << value << " changed into value " << newValue << " successfully !!" << endl;
    }

    void extarctMin() {
        if(root == NULL) {
            cout << "No element exist in the Tree to delete !!" << endl;
            return;
        }
        deleteNode(root->data);
        cout << "Extract Min successfully !!" << endl;
    }

    void deleteNode(int value) {
        Heap_Node* node = searchNode(value);
        if (node == nullptr) {
            cout << "Element does not exist to delete!" << endl;
        } else {
            Heap_Node* lastNode = getLastNode();
            if (lastNode == nullptr) {
                cout << "Heap is empty. Nothing to delete!" << endl;
                return;
            }
            swap(node->data, lastNode->data);
            delete lastNode;
            adjustNode(node);
            size--;
        }
    }

    void traverse() {
        cout << "Traversal options:\n"
             << "  pre - Preorder\n"
             << "  post - Postorder\n"
             << "  in - Inorder\n"
             << "  level - Level order\n"
             << "  break - Exit traversal\n";

        string option;
        while (true) {
            cout << "Enter your choice: ";
            cin >> option;
            if (option == "in") {
                cout << "[";
                inorder(root);
                cout << "]" << endl;
            } else if (option == "pre") {
                cout << "[";
                preorder(root);
                cout << "]" << endl;
            } else if (option == "post") {
                cout << "[";
                postorder(root);
                cout << "]" << endl;
            } else if (option == "level") levelorder();
            else if (option == "break") break;
            else cout << "Invalid option. Please try again." << endl;
        }
    }

    void deleteMINheap() {
        deleteMINheap(root);
        root = nullptr;
        size = 0;
    }

private:
    void searchNode(Heap_Node* node, int value, Heap_Node*& getNode) {
        if (node != nullptr) {
            if (node->data == value)
                getNode = node;
            searchNode(node->leftChild, value, getNode);
            searchNode(node->rightChild, value, getNode);
        }
    }

    Heap_Node* getLastNode() {
        if (root == nullptr)
            return nullptr;
        int height = floor(log2(size)) + 1;
        int number_elements = pow(2, height - 1);
        int last_row_elements = size - number_elements + 1;

        Heap_Node* tempNode = root;
        if (number_elements == last_row_elements) {
            while (tempNode->rightChild != nullptr) {
                tempNode = tempNode->rightChild;
            }
            return tempNode;
        }
        for (int i = 0; i < height; i++) {
            if (last_row_elements > (number_elements / 2))
                tempNode = tempNode->rightChild;
            else
                tempNode = tempNode->leftChild;
            number_elements /= 2;
        }
        return tempNode;
    }

    void adjustNode(Heap_Node* node) {
        while (node->parent && node->data < node->parent->data) {
            swap(node->data, node->parent->data);
            node = node->parent;
        }
        while(node->leftChild || node->rightChild) {
            if(node->leftChild && node->rightChild)
                if(node->data < node->leftChild->data && node->data < node->rightChild->data) break;
                else {
                    int temp = min(node->leftChild->data, node->rightChild->data);
                    if(node->leftChild->data < node->rightChild->data) {
                        node->leftChild->data = node->data;
                        node->data = temp;
                        node = node->leftChild;
                    } else {
                        node->rightChild->data = node->data;
                        node->data = temp;
                        node = node->rightChild;
                    }
                }
            else if(node->leftChild)
                if(node->data > node->leftChild->data) {
                    int temp = node->data;
                    node->data = node->leftChild->data;
                    node->leftChild->data = temp;
                    node = node->leftChild;
                } else break;
            else if(node->rightChild)
                if(node->data > node->rightChild->data) {
                    int temp = node->data;
                    node->data = node->rightChild->data;
                    node->rightChild->data = temp;
                    node = node->rightChild;
                } else break;
            else break;
        }
    }

    void deleteMINheap(Heap_Node* node) {
        if (node != nullptr) {
            deleteMINheap(node->leftChild);
            deleteMINheap(node->rightChild);
            cout << "Deleted successfully: " << node->data << endl;
            delete node;
        }
    }

    void inorder(Heap_Node* node) {
        if (node != nullptr) {
            inorder(node->leftChild);
            cout << node->data << ", ";
            inorder(node->rightChild);
        }
    }

    void preorder(Heap_Node* node) {
        if (node != nullptr) {
            cout << node->data << ", ";
            preorder(node->leftChild);
            preorder(node->rightChild);
        }
    }

    void postorder(Heap_Node* node) {
        if (node != nullptr) {
            postorder(node->leftChild);
            postorder(node->rightChild);
            cout << node->data << ", ";
        }
    }

    void levelorder() {
        if (root == nullptr) {
            cout << "[]" << endl;
            return;
        }
        QueueArray* queue = new QueueArray();
        queue->enqueue(root->data);
        cout << "[";
        while (!queue->isEmpty()) {
            Heap_Node* node = searchNode(queue->peek());
            queue->dequeue();
            cout << node->data << ", ";
            if (node->leftChild != nullptr) queue->enqueue(node->leftChild->data);
            if (node->rightChild != nullptr) queue->enqueue(node->rightChild->data);
        }
        cout << "]" << endl;
        delete queue;
    }
};
