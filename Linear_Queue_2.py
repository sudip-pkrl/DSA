# Linear Queue

MAX = 5

# Global queue variables
queue = [None] * MAX
front = -1
rear = -1

def enqueue(element):
    global front, rear
    if rear == MAX - 1:
        print("Queue is full! Cannot enqueue.")
        return
    if front == -1:
        front = 0
    rear += 1
    queue[rear] = element

def dequeue():
    global front, rear
    if front == -1:
        print("Queue is empty! Cannot dequeue.")
        return -1
    element = queue[front]
    if front == rear:
        front = rear = -1
    else:
        front += 1
    return element

def display():
    if front == -1:
        print("Queue is empty!")
        return
    print("Queue elements: ", end="")
    for i in range(front, rear + 1):
        print(queue[i], end=" ")
    print()

def main():
    while True:
        print("\n-----Queue Menu-----")
        print("1. Enqueue")
        print("2. Dequeue")
        print("3. Display")
        print("4. Exit")
        choice = int(input("Enter your choice: "))

        if choice == 1:
            element = int(input("Enter the element to enqueue: "))
            enqueue(element)
        elif choice == 2:
            element = dequeue()
            if element != -1:
                print("Dequeued element:", element)
        elif choice == 3:
            display()
        elif choice == 4:
            print("Exiting program.")
            break
        else:
            print("Invalid choice. Please try again.")

if __name__ == "__main__":
    main()