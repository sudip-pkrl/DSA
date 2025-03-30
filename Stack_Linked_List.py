# Menu driven program for linked list implementation of stack :-

class Node:
    """Class representing a Node in the linked list"""
    def __init__(self, data):
        self.data = data
        self.next = None

class Stack:
    """Class representing Stack using a linked list"""
    def __init__(self):
        self.top = None

    def push(self, value):
        """Pushes an element onto the stack"""
        new_node = Node(value)
        new_node.next = self.top
        self.top = new_node
        print(f"{value} pushed to stack")

    def pop(self):
        """Pops an element from the stack"""
        if self.top is None:
            print("Stack underflow!")
            return None
        popped_value = self.top.data
        self.top = self.top.next
        print(f"Popped value: {popped_value}")
        return popped_value

    def display(self):
        """Displays the stack"""
        if self.top is None:
            print("Stack is empty!")
            return
        temp = self.top
        print("Stack elements:")
        while temp:
            print(temp.data, end=" -> ")
            temp = temp.next
        print("NULL")

def menu():
    """Menu-driven function to use the stack"""
    stack = Stack()
    
    while True:
        print("\nStack Menu (Linked List Implementation):")
        print("1. Push\n2. Pop\n3. Display\n4. Exit")
        choice = int(input("Enter your choice: "))

        if choice == 1:
            value = int(input("Enter value to push: "))
            stack.push(value)
        elif choice == 2:
            stack.pop()
        elif choice == 3:
            stack.display()
        elif choice == 4:
            print("Exiting...")
            break
        else:
            print("Invalid choice! Try again.")

# Run the menu-driven program
if __name__ == "__main__":
    menu()
