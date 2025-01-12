import java.util.*;

public class QueueArray {
    private int[] arr;
    private int begin;
    private int end;
    private int sizeOfQueue;

    public QueueArray() {
        arr = new int[100];
        begin = -1;
        end = -1;
        sizeOfQueue = 0;
    }

    public int enqueue(int data) {
        if (isFull()) {
            System.out.println("The Queue is full. Cannot enqueue " + data + "!");
            return -1;
        }
        if (isEmpty()) {
            begin = 0;
        }
        end = (end + 1) % 100;
        arr[end] = data;
        sizeOfQueue++;
        System.out.println(data + " is successfully inserted at index " + end + " in the Queue!");
        return end;
    }

    public boolean isFull() {
        return sizeOfQueue == 100;
    }

    public boolean isEmpty() {
        return sizeOfQueue == 0;
    }

    public int dequeue() {
        if (isEmpty()) {
            System.out.println("The Queue is empty. Cannot dequeue!");
            return -1;
        }
        int dequeuedValue = arr[begin];
        begin = (begin + 1) % 100;
        sizeOfQueue--;
        if (sizeOfQueue == 0) {
            begin = -1;
            end = -1;
        }
        System.out.println("Dequeued: " + dequeuedValue);
        return dequeuedValue;
    }

    public int getFront() {
        if (isEmpty()) {
            System.out.println("There is no element in the Queue!");
            return -1;
        }
        System.out.println("Front element: " + arr[begin] + " at index " + begin);
        return arr[begin];
    }

    public int getRear() {
        if (isEmpty()) {
            System.out.println("There is no element in the Queue!");
            return -1;
        }
        System.out.println("Rear element: " + arr[end] + " at index " + end);
        return arr[end];
    }

    public int size() {
        System.out.println("Number of elements in the Queue: " + sizeOfQueue);
        return sizeOfQueue;
    }

    public void printQueue() {
        if (isEmpty()) {
            System.out.println("The Queue is empty!");
            return;
        }
        System.out.print("[ ");
        for (int i = 0; i < sizeOfQueue; i++) {
            System.out.print(arr[(begin + i) % 100] + ", ");
        }
        System.out.println("]");
    }

    public static void main(String[] args) {
        QueueArray queue = new QueueArray();
        queue.enqueue(10);
        queue.enqueue(20);
        queue.enqueue(30);
        queue.printQueue();
        queue.dequeue();
        queue.getFront();
        queue.getRear();
        queue.size();
    }
}