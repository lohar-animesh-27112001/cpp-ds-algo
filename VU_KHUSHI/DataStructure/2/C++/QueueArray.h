#ifndef QUEUE_ARRAY
#define QUEUE_ARRAY

#include <iostream>
using namespace std;

class QueueArray {
private:
    int arr[100];
    int begin;
    int end;
    int sizeOfQueue;

public:
    QueueArray() : begin(-1), end(-1), sizeOfQueue(0) {}

    int enqueue(int data) {
        if (isFull()) {
            cout << "The Queue is full. Cannot enqueue " << data << "!" << endl;
            return -1;
        }
        if (isEmpty()) {
            begin = 0;
        }
        end = (end + 1) % 100;
        arr[end] = data;
        sizeOfQueue++;
        cout << data << " is successfully inserted at index " << end << " in the Queue!" << endl;
        return end;
    }

    bool isFull() const {
        return sizeOfQueue == 100;
    }

    bool isEmpty() const {
        return sizeOfQueue == 0;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "The Queue is empty. Cannot dequeue!" << endl;
            return -1;
        }
        int dequeuedValue = arr[begin];
        begin = (begin + 1) % 100;
        sizeOfQueue--;
        if (sizeOfQueue == 0) {
            begin = -1;
            end = -1;
        }
        cout << "Dequeued: " << dequeuedValue << endl;
        return dequeuedValue;
    }

    int getFront() const {
        if (isEmpty()) {
            cout << "There is no element in the Queue!" << endl;
            return -1;
        }
        cout << "Front element: " << arr[begin] << " at index " << begin << endl;
        return arr[begin];
    }

    int getRear() const {
        if (isEmpty()) {
            cout << "There is no element in the Queue!" << endl;
            return -1;
        }
        cout << "Rear element: " << arr[end] << " at index " << end << endl;
        return arr[end];
    }

    int size() const {
        cout << "Number of elements in the Queue: " << sizeOfQueue << endl;
        return sizeOfQueue;
    }

    void printQueue() const {
        if (isEmpty()) {
            cout << "The Queue is empty!" << endl;
            return;
        }
        cout << "[ ";
        for (int i = 0; i < sizeOfQueue; i++) {
            cout << arr[(begin + i) % 100] << ", ";
        }
        cout << "]" << endl;
    }

    ~QueueArray() {
        begin = -1;
        end = -1;
        sizeOfQueue = 0;
    }
};

#endif
#pragma once