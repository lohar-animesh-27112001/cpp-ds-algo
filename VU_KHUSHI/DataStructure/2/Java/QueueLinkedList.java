import java.util.*;

public class QueueLinkedList {
    private static class Node {
        int data;
        Node next;

        Node(int value) {
            this.data = value;
            this.next = null;
        }
    }

    private Node head;
    private Node tail;
    private int queueSize;

    // Default constructor
    public QueueLinkedList() {
        this.head = null;
        this.tail = null;
        this.queueSize = 0;
    }

    // Constructor with an initial value
    public QueueLinkedList(int value) {
        this.head = new Node(value);
        this.tail = this.head;
        this.queueSize = 1;
        System.out.println(value + " inserted successfully at the head!");
    }

    // Method to enqueue a new element
    public void enqueue(int value) {
        Node newNode = new Node(value);
        if (head == null) {
            head = tail = newNode;
        } else {
            tail.next = newNode;
            tail = newNode;
        }
        queueSize++;
        System.out.println(value + " inserted successfully!");
    }

    // Method to dequeue an element
    public void dequeue() {
        if (head == null) {
            System.out.println("Queue is empty, nothing to delete!");
            return;
        }
        Node temp = head;
        head = head.next;
        if (head == null) {
            tail = null;
        }
        System.out.println("Deleted: " + temp.data);
        queueSize--;
    }

    // Method to get the front element
    public int getFront() {
        if (head == null) {
            System.out.println("Queue is empty!");
            return -1;
        }
        System.out.println("Front element is: " + head.data);
        return head.data;
    }

    // Method to get the rear element
    public int getRear() {
        if (tail == null) {
            System.out.println("Queue is empty!");
            return -1;
        }
        System.out.println("Rear element is: " + tail.data);
        return tail.data;
    }

    // Method to check if the queue is empty
    public boolean isEmpty() {
        if (queueSize == 0) {
            System.out.println("Queue is empty!");
            return true;
        }
        System.out.println("Queue is not empty!");
        return false;
    }

    // Method to get the size of the queue
    public int size() {
        System.out.println("Number of elements in the queue: " + queueSize);
        return queueSize;
    }

    // Destructor-like method to clear the queue
    public void clear() {
        while (head != null) {
            Node temp = head;
            head = head.next;
            temp = null;
        }
        tail = null;
        queueSize = 0;
        System.out.println("Queue deleted successfully!");
    }

    public static void main(String[] args) {
        QueueLinkedList queue = new QueueLinkedList();
        queue.enqueue(10);
        queue.enqueue(20);
        queue.getFront();
        queue.getRear();
        queue.dequeue();
        queue.size();
        queue.isEmpty();
        queue.clear();
    }
}
