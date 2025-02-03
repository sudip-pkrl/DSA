# Menu driven program for stack implementation using list(array):-
class Stack:
    def __init__(self, max_size=100):
        self.stack = []  # Initialize an empty stack
        self.max_size = max_size  # Define maximum size of the stack

    def push(self, value):
        if len(self.stack) >= self.max_size:
            print("Stack Overflow! Cannot push", value)
        else:
            self.stack.append(value)
            print(f"{value} pushed onto the stack.")

    def pop(self):
        if not self.stack:
            print("Stack Underflow! No elements to pop.")
        else:
            value = self.stack.pop()
            print(f"{value} popped from the stack.")

    def peek(self):
        if not self.stack:
            print("Stack is empty. No top element.")
        else:
            print(f"Top element: {self.stack[-1]}")

    def display(self):
        if not self.stack:
            print("Stack is empty. No elements to display.")
        else:
            print("Stack elements:", self.stack[::-1])

    def is_empty(self):
        return len(self.stack) == 0

    def is_full(self):
        return len(self.stack) == self.max_size


def main():
    stack = Stack(max_size=5)  # Create a stack with a max size of 5
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

        if choice == 1:
            value = int(input("Enter value to push: "))
            stack.push(value)
        elif choice == 2:
            stack.pop()
        elif choice == 3:
            stack.peek()
        elif choice == 4:
            stack.display()
        elif choice == 5:
            print("Stack is empty." if stack.is_empty() else "Stack is not empty.")
        elif choice == 6:
            print("Stack is full." if stack.is_full() else "Stack is not full.")
        elif choice == 7:
            print("Exiting program.")
            break
        else:
            print("Invalid choice. Please try again.")


if __name__ == "__main__":
    main()

# # Explanation:-
# 1. In the main function, we create a stack with a max size of 5.
# 2. We use a while loop to provide a menu-driven interface to the user.
# 3. The user can choose from the options to push, pop, peek, display, check if empty, check if full, or exit the program.
# 4. The push option allows the user to enter a value and push it onto the stack.
# 5. The pop option removes the top element from the stack.
# 6. The peek option displays the top element of the stack.
# 7. The display option displays all the elements of the stack.
# 8. The is_empty and is_full methods check if the stack is empty or full, respectively.
# 9. The main function calls the menu-driven interface until the user chooses to exit.
# 10. The program ends when the user chooses to exit.


# Initialization:

# A stack is represented using a Python list.
# max_size is used to prevent stack overflow.

# Menu Options:

# Each operation (push, pop, peek, etc.) is handled based on user input.

# Edge Cases:

# Prevent pushing into a full stack (stack overflow).
# Prevent popping from an empty stack (stack underflow).