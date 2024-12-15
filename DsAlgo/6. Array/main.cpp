#include <bits/stdc++.h>
#include "Queue/queueArray.h"
#include "Stack/stackArray.h"

using namespace std;

int main() {
    cout << "Queue is running..." << endl;
    QueueArray queueArr;
    queueArr.dequeue();
    queueArr.peek();
    queueArr.printQueue();
    queueArr.enqueue(12);
    queueArr.enqueue(10);
    queueArr.enqueue(120);
    queueArr.enqueue(110);
    queueArr.enqueue(100);
    queueArr.dequeue();
    queueArr.enqueue(102);
    queueArr.enqueue(105);
    queueArr.dequeue();
    queueArr.printQueue();

    cout << "Satck is running..." << endl;
    StackArray stackArr;
    stackArr.pop();
    stackArr.peek();
    stackArr.printStack();
    stackArr.push(12);
    stackArr.push(10);
    stackArr.push(120);
    stackArr.push(110);
    stackArr.push(100);
    stackArr.pop();
    stackArr.push(102);
    stackArr.push(105);
    stackArr.pop();
    stackArr.printStack();
    return 0;
}