# Menu driven program for linked list implementation of linear queue :-

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Queue:
    def __init__(self):
        self.front = self.rear = None
    
    # Check if the queue is empty
    def is_empty(self):
        return self.front is None
    
    # Enqueue operation
    def enqueue(self, value):
        new_node = Node(value)
        if self.rear is None:
            self.front = self.rear = new_node
            return
        
        self.rear.next = new_node
        self.rear = new_node
    
    # Dequeue operation
    def dequeue(self):
        if self.is_empty():
            print("Queue is empty!")
            return None
        
        value = self.front.data
        self.front = self.front.next
        
        if self.front is None:
            self.rear = None
        
        return value
    
    # Display queue elements
    def display(self):
        if self.is_empty():
            print("Queue is empty!")
            return
        
        temp = self.front
        print("Queue elements:", end=" ")
        while temp:
            print(temp.data, end=" ")
            temp = temp.next
        print()

# Menu-driven program
def main():
    queue = Queue()

    while True:
        print("\nMenu:")
        print("1. Enqueue")
        print("2. Dequeue")
        print("3. Display Queue")
        print("4. Exit")
        choice = int(input("Enter your choice: "))

        if choice == 1:
            value = int(input("Enter value to enqueue: "))
            queue.enqueue(value)
        elif choice == 2:
            value = queue.dequeue()
            if value is not None:
                print("Dequeued value:", value)
        elif choice == 3:
            queue.display()
        elif choice == 4:
            print("Exiting...")
            break
        else:
            print("Invalid choice! Please try again.")

if __name__ == "__main__":
    main()
