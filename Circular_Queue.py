class CircularQueue:
    def __init__(self, max_size):
        self.queue = [None] * max_size
        self.max_size = max_size
        self.front = -1
        self.rear = -1

    def is_full(self):
        return (self.rear + 1) % self.max_size == self.front

    def is_empty(self):
        return self.front == -1

    def enqueue(self, element):
        if self.is_full():
            print("Queue is full! Cannot enqueue.")
        else:
            if self.front == -1:
                self.front = 0
            self.rear = (self.rear + 1) % self.max_size
            self.queue[self.rear] = element
            print(f"Enqueued: {element}")

    def dequeue(self):
        if self.is_empty():
            print("Queue is empty! Cannot dequeue.")
        else:
            element = self.queue[self.front]
            if self.front == self.rear:
                self.front = self.rear = -1  # Reset the queue
            else:
                self.front = (self.front + 1) % self.max_size
            print(f"Dequeued: {element}")
            return element

    def display(self):
        if self.is_empty():
            print("Queue is empty!")
        else:
            print("Queue elements:", end=" ")
            i = self.front
            while True:
                print(self.queue[i], end=" ")
                if i == self.rear:
                    break
                i = (i + 1) % self.max_size
            print()


def main():
    max_size = int(input("Enter the maximum size of the circular queue: "))
    queue = CircularQueue(max_size)

    while True:
        print("\nCircular Queue Menu:")
        print("1. Enqueue")
        print("2. Dequeue")
        print("3. Display")
        print("4. Exit")
        choice = input("Enter your choice: ")

        if choice == "1":
            element = input("Enter the element to enqueue: ")
            queue.enqueue(element)
        elif choice == "2":
            queue.dequeue()
        elif choice == "3":
            queue.display()
        elif choice == "4":
            print("Exiting program.")
            break
        else:
            print("Invalid choice. Please try again.")


if __name__ == "__main__":
    main()


# # Explanation:-

# CircularQueue Class:

# Implements a circular queue using a Python list.
# Contains methods for:
# is_full(): Checks if the queue has reached its maximum size.
# is_empty(): Checks if the queue is empty.
# enqueue(element): Adds an element to the rear of the queue if not full.
# dequeue(): Removes and returns the element from the front of the queue if not empty.
# display(): Prints all elements in the queue.  

# Menu-Driven Approach:

# Prompts the user with options to perform queue operations.
# Handles invalid choices and exits cleanly when the user selects "Exit".

# Dynamic Input:

# The queue size is set dynamically based on user input at the start of the program.