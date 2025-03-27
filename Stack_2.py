MAX = 100  # Maximum size of the stack

# List to store stack elements
stack = []
top = -1  # Index of the top element

# Function to push a value onto the stack
def push(value):
    global top
    if top == MAX - 1:
        print("Stack Overflow! Cannot push " + str(value))
    else:
        stack.append(value)
        top += 1
        print(str(value) + " pushed onto the stack.")

# Function to pop a value from the stack
def pop():
    global top
    if top == -1:
        print("Stack Underflow! No elements to pop.")
    else:
        print(str(stack[top]) + " popped from the stack.")
        stack.pop()
        top -= 1

# Function to peek the top element of the stack
def peek():
    if top == -1:
        print("Stack is empty. No top element.")
    else:
        print("Top element: " + str(stack[top]))

# Function to display the elements of the stack
def display():
    if top == -1:
        print("Stack is empty. No elements to display.")
    else:
        print("Stack elements:", end=" ")
        for i in range(top, -1, -1):
            print(str(stack[i]), end=" ")
        print()

# Function to check if the stack is empty
def check_empty():
    if top == -1:
        print("Stack is empty.")
    else:
        print("Stack is not empty.")

# Function to check if the stack is full
def check_full():
    if top == MAX - 1:
        print("Stack is full.")
    else:
        print("Stack is not full.")

def main():
    while True:
        print("\n--- Stack Menu ---")
        print("1. Push")
        print("2. Pop")
        print("3. Peek")
        print("4. Display")
        print("5. Check if Empty")
        print("6. Check if Full")
        print("7. Exit")
        choice = int(input("Enter your choice: "))

        if choice == 7:
            print("Exiting program.")
            break

        if choice == 1:  # Push
            value = int(input("Enter value to push: "))
            push(value)
        elif choice == 2:  # Pop
            pop()
        elif choice == 3:  # Peek
            peek()
        elif choice == 4:  # Display
            display()
        elif choice == 5:  # Check if Empty
            check_empty()
        elif choice == 6:  # Check if Full
            check_full()
        else:
            print("Invalid choice. Please try again.")

if __name__ == "__main__":
    main()
