#include "QueueLinkedList.h"
#include "QueueArray.h"

using namespace std;

int main() {
    // Queue using LinkedList:
    cout << "Queue using LinkedList is running..." << endl;
    QueueLinkedList* queue = new QueueLinkedList();
    queue->isEmpty();
    queue->enqueue(12);
    queue->enqueue(23);
    queue->enqueue(10);
    queue->getFront();
    queue->getRear();
    queue->dequeue();
    queue->printQueue();
    delete queue;

    cout << "===========================================================" << endl;

    // Queue using Array:
    cout << "Queue using Array is running..." << endl;
    QueueArray queueArr;
    queueArr.enqueue(10);
    queueArr.enqueue(20);
    queueArr.enqueue(30);
    queueArr.printQueue();
    queueArr.getFront();
    queueArr.getRear();
    queueArr.size();
    queueArr.dequeue();
    queueArr.printQueue();
    queueArr.dequeue();
    queueArr.dequeue();
    queueArr.dequeue();
    queueArr.isEmpty();
    return 0;
}