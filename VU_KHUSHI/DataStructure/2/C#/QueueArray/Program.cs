using System;

public class QueueArray
{
    public static void Main(string[] args)
    {
        QueueArray queue = new QueueArray();
        queue.Enqueue(10);
        queue.Enqueue(20);
        queue.Enqueue(30);
        queue.Enqueue(40);
        queue.PrintQueue();
        queue.GetFront();
        queue.GetRear();
        queue.Dequeue();
        queue.PrintQueue();
        queue.Size();
        queue.Enqueue(50);
        queue.Enqueue(60);
        queue.PrintQueue();
        queue.GetFront();
        queue.GetRear();
    }
    private int[] arr = new int[100];
    private int begin = -1;
    private int end = -1;
    private int sizeOfQueue = 0;

    public QueueArray() { }

    public int Enqueue(int data)
    {
        if (IsFull())
        {
            Console.WriteLine($"The Queue is full. Cannot enqueue {data}!");
            return -1;
        }
        if (IsEmpty())
        {
            begin = 0;
        }
        end = (end + 1) % 100;
        arr[end] = data;
        sizeOfQueue++;
        Console.WriteLine($"{data} is successfully inserted at index {end} in the Queue!");
        return end;
    }

    public bool IsFull()
    {
        return sizeOfQueue == 100;
    }

    public bool IsEmpty()
    {
        return sizeOfQueue == 0;
    }

    public int Dequeue()
    {
        if (IsEmpty())
        {
            Console.WriteLine("The Queue is empty. Cannot dequeue!");
            return -1;
        }
        int dequeuedValue = arr[begin];
        begin = (begin + 1) % 100;
        sizeOfQueue--;
        if (sizeOfQueue == 0)
        {
            begin = -1;
            end = -1;
        }
        Console.WriteLine($"Dequeued: {dequeuedValue}");
        return dequeuedValue;
    }

    public int GetFront()
    {
        if (IsEmpty())
        {
            Console.WriteLine("There is no element in the Queue!");
            return -1;
        }
        Console.WriteLine($"Front element: {arr[begin]} at index {begin}");
        return arr[begin];
    }

    public int GetRear()
    {
        if (IsEmpty())
        {
            Console.WriteLine("There is no element in the Queue!");
            return -1;
        }
        Console.WriteLine($"Rear element: {arr[end]} at index {end}");
        return arr[end];
    }

    public int Size()
    {
        Console.WriteLine($"Number of elements in the Queue: {sizeOfQueue}");
        return sizeOfQueue;
    }

    public void PrintQueue()
    {
        if (IsEmpty())
        {
            Console.WriteLine("The Queue is empty!");
            return;
        }
        Console.Write("[ ");
        for (int i = 0; i < sizeOfQueue; i++)
        {
            Console.Write(arr[(begin + i) % 100] + ", ");
        }
        Console.WriteLine("]");
    }
}