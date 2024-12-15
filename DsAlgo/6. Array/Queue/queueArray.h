#ifndef HEADER_QUEUE
#define HEADER_QUEUE

#include <bits/stdc++.h>

using namespace std;

class QueueArray {
private:
    int array[100];
    int count;

public:
    QueueArray() : count(0) {}

    void enqueue(int value) {
        if (isFull()) {
            cout << value << " can't dequeue, Queue overflowed !!" << endl;
            return;
        }
        array[count++] = value;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue underflowed, there is no element to dequeue !!" << endl;
            return;
        }
        for (int i = 0; i < count - 1; i++) {
            array[i] = array[i + 1];
        }
        count--;
    }

    int countQueue() const {
        cout << "Number of elements in the queue is: " << count << endl;
        return count;
    }

    int peek() const {
        if (isEmpty()) {
            cout << "There is no element in the queue" << endl;
            return -1;
        } else {
            cout << "The first element of the queue is: " << array[0] << endl;
            return array[0];
        }
    }

    bool isEmpty() const {
        return count == 0;
    }

    bool isFull() const {
        return count == 100;
    }

    void printQueue() const {
        cout << "[";
        for (int i = 0; i < count; i++) {
            cout << array[i];
            if (i != count - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
};

#endif // HEADER_QUEUE
#pragma once