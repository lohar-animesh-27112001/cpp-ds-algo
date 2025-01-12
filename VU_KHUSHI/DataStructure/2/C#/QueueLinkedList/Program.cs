using System;

namespace QueueLinkedListNamespace
{
    public class MainClass
    {
        public static void Main(string[] args)
        {
            QueueLinkedList queue = new QueueLinkedList();
            queue.IsEmpty();
            queue.Enqueue(12);
            queue.Enqueue(23);
            queue.printQueue();
            queue.Enqueue(100);
            queue.Enqueue(123);
            queue.Dequeue();
            queue.printQueue();
            queue.GetRear();
            queue.IsEmpty();
            queue.Size();
            queue.GetFront();
        }
    }

    public class Node
    {
        public int Data { get; set; }
        public Node Next { get; set; }

        public Node(int value)
        {
            Data = value;
            Next = null;
        }
    }

    public class QueueLinkedList
    {
        private Node head;
        private Node tail;
        private int queueSize;

        public QueueLinkedList()
        {
            head = null;
            tail = null;
            queueSize = 0;
        }

        public QueueLinkedList(int value)
        {
            head = new Node(value);
            tail = head;
            queueSize = 1;
            Console.WriteLine($"{value} inserted successfully at the head!");
        }

        public void Enqueue(int value)
        {
            Node newNode = new Node(value);
            if (head == null)
            {
                head = tail = newNode;
            }
            else
            {
                tail.Next = newNode;
                tail = newNode;
            }
            queueSize++;
            Console.WriteLine($"{value} inserted successfully!");
        }

        public void Dequeue()
        {
            if (head == null)
            {
                Console.WriteLine("Queue is empty, nothing to delete!");
                return;
            }
            Node temp = head;
            head = head.Next;
            if (head == null)
            {
                tail = null;
            }
            Console.WriteLine($"Deleted: {temp.Data}");
        }

        public int GetFront()
        {
            if (head == null)
            {
                Console.WriteLine("Queue is empty!");
                return -1;
            }
            Console.WriteLine($"Front element is: {head.Data}");
            return head.Data;
        }

        public int GetRear()
        {
            if (tail == null)
            {
                Console.WriteLine("Queue is empty!");
                return -1;
            }
            Console.WriteLine($"Rear element is: {tail.Data}");
            return tail.Data;
        }

        public bool IsEmpty()
        {
            if (queueSize == 0)
            {
                Console.WriteLine("Queue is empty!");
                return true;
            }
            Console.WriteLine("Queue is not empty!");
            return false;
        }

        public int Size()
        {
            Console.WriteLine($"Number of elements in the queue: {queueSize}");
            return queueSize;
        }

        public void printQueue()
        {
            Console.Write("[ Head -> ");
            Node temp = head;
            while (temp != null)
            {
                Console.Write(temp.Data + " -> ");
                temp = temp.Next;
            }
            Console.WriteLine("NULL ]");
        }
    }
}
