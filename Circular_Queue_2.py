# Circular Queue

MAX = 5

# Global queue variables
queue = [None] * MAX
front = -1
rear = -1

def enqueue(element):
    global front, rear
    if (rear + 1) % MAX == front:
        print("Queue is full! Cannot enqueue.")
        return
    if front == -1:
        front = 0
    rear = (rear + 1) % MAX
    queue[rear] = element
    print("Enqueued:", element)

def dequeue():
    global front, rear
    if front == -1:
        print("Queue is empty! Cannot dequeue.")
        return -1
    element = queue[front]
    if front == rear:
        front = rear = -1  # Reset the queue
    else:
        front = (front + 1) % MAX
    print("Dequeued element:", element)
    return element

def display():
    if front == -1:
        print("Queue is empty!")
        return
    print("Queue elements: ", end="")
    i = front
    while True:
        print(queue[i], end=" ")
        if i == rear:
            break
        i = (i + 1) % MAX
    print()

def main():
    while True:
        print("\n-----Circular Queue Menu-----")
        print("1. Enqueue")
        print("2. Dequeue")
        print("3. Display")
        print("4. Exit")
        choice = int(input("Enter your choice: "))

        if choice == 1:
            element = int(input("Enter the element to enqueue: "))
            enqueue(element)
        elif choice == 2:
            dequeue()
        elif choice == 3:
            display()
        elif choice == 4:
            print("Exiting program.")
            break
        else:
            print("Invalid choice. Please try again.")

if __name__ == "__main__":
    main()
