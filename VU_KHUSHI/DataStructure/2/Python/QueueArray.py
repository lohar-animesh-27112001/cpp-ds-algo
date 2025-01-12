class QueueArray:
    def __init__(self):
        self.arr = [None] * 100
        self.begin = -1
        self.end = -1
        self.size_of_queue = 0

    def enqueue(self, data):
        if self.is_full():
            print(f"The Queue is full. Cannot enqueue {data}!")
            return -1
        if self.is_empty():
            self.begin = 0
        self.end = (self.end + 1) % 100
        self.arr[self.end] = data
        self.size_of_queue += 1
        print(f"{data} is successfully inserted at index {self.end} in the Queue!")
        return self.end

    def is_full(self):
        return self.size_of_queue == 100

    def is_empty(self):
        return self.size_of_queue == 0

    def dequeue(self):
        if self.is_empty():
            print("The Queue is empty. Cannot dequeue!")
            return -1
        dequeued_value = self.arr[self.begin]
        self.begin = (self.begin + 1) % 100
        self.size_of_queue -= 1
        if self.size_of_queue == 0:
            self.begin = -1
            self.end = -1
        print(f"Dequeued: {dequeued_value}")
        return dequeued_value

    def get_front(self):
        if self.is_empty():
            print("There is no element in the Queue!")
            return -1
        print(f"Front element: {self.arr[self.begin]} at index {self.begin}")
        return self.arr[self.begin]

    def get_rear(self):
        if self.is_empty():
            print("There is no element in the Queue!")
            return -1
        print(f"Rear element: {self.arr[self.end]} at index {self.end}")
        return self.arr[self.end]

    def size(self):
        print(f"Number of elements in the Queue: {self.size_of_queue}")
        return self.size_of_queue

    def print_queue(self):
        if self.is_empty():
            print("The Queue is empty!")
            return
        print("[", end=" ")
        for i in range(self.size_of_queue):
            print(self.arr[(self.begin + i) % 100], end=", ")
        print("]")

# Example usage:
queue = QueueArray()
queue.enqueue(10)
queue.enqueue(20)
queue.enqueue(30)
queue.print_queue()
queue.dequeue()
queue.get_front()
queue.get_rear()
queue.size()