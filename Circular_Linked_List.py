# Menu driven program to show operations in circular linked list :-

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class CircularLinkedList:
    def __init__(self):
        self.head = None

    # Insert at the beginning
    def insert_at_beginning(self, data):
        new_node = Node(data)
        if not self.head:
            new_node.next = new_node
            self.head = new_node
        else:
            temp = self.head
            while temp.next != self.head:
                temp = temp.next
            temp.next = new_node
            new_node.next = self.head
            self.head = new_node

    # Insert at the end
    def insert_at_end(self, data):
        new_node = Node(data)
        if not self.head:
            new_node.next = new_node
            self.head = new_node
        else:
            temp = self.head
            while temp.next != self.head:
                temp = temp.next
            temp.next = new_node
            new_node.next = self.head

    # Delete a node
    def delete_node(self, data):
        if not self.head:
            print("List is empty!")
            return

        temp = self.head
        prev = None

        # If the node to be deleted is the head
        if temp.data == data:
            if temp.next == self.head:
                self.head = None
            else:
                while temp.next != self.head:
                    temp = temp.next
                temp.next = self.head.next
                self.head = self.head.next
            print("Node deleted successfully.")
            return

        prev = self.head
        temp = self.head.next

        while temp != self.head:
            if temp.data == data:
                prev.next = temp.next
                print("Node deleted successfully.")
                return
            prev = temp
            temp = temp.next

        print("Node not found!")

    # Display the list
    def display(self):
        if not self.head:
            print("List is empty!")
            return
        temp = self.head
        print("Circular Linked List:", end=" ")
        while True:
            print(temp.data, end=" -> ")
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
cll = CircularLinkedList()
while True:
    print("\nCircular Linked List Operations:")
    print("1. Insert at Beginning\n2. Insert at End\n3. Delete a Node\n4. Display List\n5. Search for a Node\n6. Exit")
    choice = int(input("Enter your choice: "))
    
    if choice == 1:
        value = int(input("Enter value: "))
        cll.insert_at_beginning(value)
    elif choice == 2:
        value = int(input("Enter value: "))
        cll.insert_at_end(value)
    elif choice == 3:
        value = int(input("Enter value to delete: "))
        cll.delete_node(value)
    elif choice == 4:
        cll.display()
    elif choice == 5:
        value = int(input("Enter value to search: "))
        cll.search(value)
    elif choice == 6:
        print("Exiting program...")
        break
    else:
        print("Invalid choice! Try again.")
