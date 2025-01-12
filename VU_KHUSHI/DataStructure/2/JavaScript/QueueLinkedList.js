class Node {
    constructor(value) {
        this.data = value;
        this.next = null;
    }
}

class QueueLinkedList {
    constructor(value = null) {
        this.head = null;
        this.tail = null;
        this.queueSize = 0;

        if (value !== null) {
            this.head = new Node(value);
            this.tail = this.head;
            this.queueSize = 1;
            console.log(`${value} inserted successfully at the head!`);
        }
    }

    enqueue(value) {
        const newNode = new Node(value);
        if (this.head === null) {
            this.head = this.tail = newNode;
        } else {
            this.tail.next = newNode;
            this.tail = newNode;
        }
        this.queueSize++;
        console.log(`${value} inserted successfully!`);
    }

    dequeue() {
        if (this.head === null) {
            console.log("Queue is empty, nothing to delete!");
            return;
        }
        const temp = this.head;
        this.head = this.head.next;
        if (this.head === null) {
            this.tail = null;
        }
        console.log(`Deleted: ${temp.data}`);
        this.queueSize--;
    }

    getFront() {
        if (this.head === null) {
            console.log("Queue is empty!");
            return -1;
        }
        console.log(`Front element is: ${this.head.data}`);
        return this.head.data;
    }

    getRear() {
        if (this.tail === null) {
            console.log("Queue is empty!");
            return -1;
        }
        console.log(`Rear element is: ${this.tail.data}`);
        return this.tail.data;
    }

    isEmpty() {
        if (this.queueSize === 0) {
            console.log("Queue is empty!");
            return true;
        }
        console.log("Queue is not empty!");
        return false;
    }

    size() {
        console.log(`Number of elements in the queue: ${this.queueSize}`);
        return this.queueSize;
    }

    clear() {
        while (this.head !== null) {
            const temp = this.head;
            this.head = this.head.next;
            temp.next = null;
        }
        this.tail = null;
        this.queueSize = 0;
        console.log("Queue deleted successfully!");
    }
}

const queue = new QueueLinkedList();
queue.enqueue(10);
queue.enqueue(20);
queue.getFront();
queue.getRear();
queue.dequeue();
queue.size();
queue.isEmpty();
queue.clear();