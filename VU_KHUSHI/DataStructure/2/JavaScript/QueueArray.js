class QueueArray {
    constructor() {
        this.arr = new Array(100);
        this.begin = -1;
        this.end = -1;
        this.sizeOfQueue = 0;
    }

    enqueue(data) {
        if (this.isFull()) {
            console.log(`The Queue is full. Cannot enqueue ${data}!`);
            return -1;
        }
        if (this.isEmpty()) {
            this.begin = 0;
        }
        this.end = (this.end + 1) % 100;
        this.arr[this.end] = data;
        this.sizeOfQueue++;
        console.log(`${data} is successfully inserted at index ${this.end} in the Queue!`);
        return this.end;
    }

    isFull() {
        return this.sizeOfQueue === 100;
    }

    isEmpty() {
        return this.sizeOfQueue === 0;
    }

    dequeue() {
        if (this.isEmpty()) {
            console.log("The Queue is empty. Cannot dequeue!");
            return -1;
        }
        const dequeuedValue = this.arr[this.begin];
        this.begin = (this.begin + 1) % 100;
        this.sizeOfQueue--;
        if (this.sizeOfQueue === 0) {
            this.begin = -1;
            this.end = -1;
        }
        console.log(`Dequeued: ${dequeuedValue}`);
        return dequeuedValue;
    }

    getFront() {
        if (this.isEmpty()) {
            console.log("There is no element in the Queue!");
            return -1;
        }
        console.log(`Front element: ${this.arr[this.begin]} at index ${this.begin}`);
        return this.arr[this.begin];
    }

    getRear() {
        if (this.isEmpty()) {
            console.log("There is no element in the Queue!");
            return -1;
        }
        console.log(`Rear element: ${this.arr[this.end]} at index ${this.end}`);
        return this.arr[this.end];
    }

    size() {
        console.log(`Number of elements in the Queue: ${this.sizeOfQueue}`);
        return this.sizeOfQueue;
    }

    printQueue() {
        if (this.isEmpty()) {
            console.log("The Queue is empty!");
            return;
        }
        let output = "[ ";
        for (let i = 0; i < this.sizeOfQueue; i++) {
            output += `${this.arr[(this.begin + i) % 100]}, `;
        }
        output = output.slice(0, -2) + " ]"; // Remove trailing comma and space
        console.log(output);
    }
}

// Example usage:
const queue = new QueueArray();
queue.enqueue(10);
queue.enqueue(20);
queue.getFront();
queue.getRear();
queue.printQueue();
queue.dequeue();
queue.size();
queue.printQueue();
