class Node:
    def __init__(self, value):
        self.data = value
        self.next = None


class QueueLinkedList:
    def __init__(self, value=None):
        self.head = None
        self.tail = None
        self.queue_size = 0

        if value is not None:
            self.enqueue(value)
            print(f"{value} inserted successfully at the head!")

    def enqueue(self, value):
        new_node = Node(value)
        if self.head is None:
            self.head = self.tail = new_node
        else:
            self.tail.next = new_node
            self.tail = new_node
        self.queue_size += 1
        print(f"{value} inserted successfully!")

    def dequeue(self):
        if self.head is None:
            print("Queue is empty, nothing to delete!")
            return
        temp = self.head
        self.head = self.head.next
        if self.head is None:
            self.tail = None
        print(f"Deleted: {temp.data}")
        del temp
        self.queue_size -= 1

    def get_front(self):
        if self.head is None:
            print("Queue is empty!")
            return -1
        print(f"Front element is: {self.head.data}")
        return self.head.data

    def get_rear(self):
        if self.tail is None:
            print("Queue is empty!")
            return -1
        print(f"Rear element is: {self.tail.data}")
        return self.tail.data

    def is_empty(self):
        if self.queue_size == 0:
            print("Queue is empty!")
            return True
        print("Queue is not empty!")
        return False

    def size(self):
        print(f"Number of elements in the queue: {self.queue_size}")
        return self.queue_size
    
    def printQueue(self):
        temp = self.head;
        print("[ Head -> ", end = "")
        while(temp != None):
            print(temp.data, end = " -> ")
            temp = temp.next
        print("NULL ]")

    def __del__(self):
        while self.head is not None:
            temp = self.head
            self.head = self.head.next
            del temp
        print("Queue deleted successfully!")


def main():
    queue = QueueLinkedList()
    while True:
        print("\nMenu:")
        print("1. Enqueue")
        print("2. Dequeue")
        print("3. Get Front")
        print("4. Get Rear")
        print("5. Check if Empty")
        print("6. Get Size")
        print("7. Print Queue")
        print("8. Exit")

        choice = input("Enter your choice: ")
        if choice == '1':
            value = int(input("Enter the value to enqueue: "))
            queue.enqueue(value)
        elif choice == '2':
            queue.dequeue()
        elif choice == '3':
            queue.get_front()
        elif choice == '4':
            queue.get_rear()
        elif choice == '5':
            queue.is_empty()
        elif choice == '6':
            queue.size()
        elif choice == '7':
            queue.printQueue()
        elif choice == '8':
            print("Exiting program. Goodbye!")
            break
        else:
            print("Invalid choice. Please try again.")

if __name__ == "__main__":
    main()