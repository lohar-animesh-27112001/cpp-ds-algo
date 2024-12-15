#ifndef HEADER_STACK
#define HEADER_STACK

#include <bits/stdc++.h>

using namespace std;

class StackArray {
private:
    int array[100];
    int count;
public:
    StackArray() : count(0) {}
    int push(int value) {
        if(isFull()) {
            cout << "Stack is Overflowed !!" << endl;
            return -1;
        }
        array[count] = value;
        count++;
        return count - 1;
    }
    int pop() {
        if(isEmpty()) {
            cout << "Stack is underflowed !!" << endl;
            return -1;
        }
        count--;
        return count + 1;
    }
    int peek() {
        if(isEmpty()) {
            cout << "Stack is underflowed !!" << endl;
            return -1;
        }
        cout << "Last element of the stack is: " << array[count] << endl;
        return array[count];
    }
    bool isFull() {return count == 100;}
    bool isEmpty() {return count == 0;}
    int countStack() {
        cout << "Number of elements in the stack is: " << count << endl;
        return count;
    }
    void printStack() {
        cout << "[";
        for(int i = 0; i < count; i++) {
            cout << array[i];
            if (i != count - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
};

#endif
#pragma once