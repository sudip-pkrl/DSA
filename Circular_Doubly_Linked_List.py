# Menu driven program to show operations in circular doubly linked list :-

class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None

class CircularDoublyLinkedList:
    def __init__(self):
        self.head = None

    # Insert at the beginning
    def insert_at_beginning(self, data):
        new_node = Node(data)
        if not self.head:
            new_node.next = new_node
            new_node.prev = new_node
            self.head = new_node
        else:
            last = self.head.prev
            new_node.next = self.head
            new_node.prev = last
            last.next = new_node
            self.head.prev = new_node
            self.head = new_node

    # Insert at the end
    def insert_at_end(self, data):
        new_node = Node(data)
        if not self.head:
            new_node.next = new_node
            new_node.prev = new_node
            self.head = new_node
        else:
            last = self.head.prev
            new_node.next = self.head
            new_node.prev = last
            last.next = new_node
            self.head.prev = new_node

    # Delete a node
    def delete_node(self, data):
        if not self.head:
            print("List is empty!")
            return

        temp = self.head
        while temp.data != data:
            temp = temp.next
            if temp == self.head:
                print("Node not found!")
                return

        if temp.next == temp:  # Only one node
            self.head = None
        else:
            temp.prev.next = temp.next
            temp.next.prev = temp.prev
            if temp == self.head:
                self.head = temp.next
        del temp
        print("Node deleted successfully.")

    # Display the list
    def display(self):
        if not self.head:
            print("List is empty!")
            return
        temp = self.head
        print("Circular Doubly Linked List:", end=" ")
        while True:
            print(temp.data, end=" <-> ")
            temp = temp.next
            if temp == self.head:
                break
        print("(Head)")

    # Search for a node
    def search(self, data):
        if not self.head:
            print("List is empty!")
            return
        temp = self.head
        pos = 1
        while True:
            if temp.data == data:
                print(f"Element found at position {pos}")
                return
            temp = temp.next
            pos += 1
            if temp == self.head:
                break
        print("Element not found in the list.")

# Menu-driven interface
cdll = CircularDoublyLinkedList()
while True:
    print("\nCircular Doubly Linked List Operations:")
    print("1. Insert at Beginning\n2. Insert at End\n3. Delete a Node\n4. Display List\n5. Search for a Node\n6. Exit")
    choice = int(input("Enter your choice: "))
    
    if choice == 1:
        value = int(input("Enter value: "))
        cdll.insert_at_beginning(value)
    elif choice == 2:
        value = int(input("Enter value: "))
        cdll.insert_at_end(value)
    elif choice == 3:
        value = int(input("Enter value to delete: "))
        cdll.delete_node(value)
    elif choice == 4:
        cdll.display()
    elif choice == 5:
        value = int(input("Enter value to search: "))
        cdll.search(value)
    elif choice == 6:
        print("Exiting program...")
        break
    else:
        print("Invalid choice! Try again.")
