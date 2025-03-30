# Menu driven program to show operations in doubly linked list :-

class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None

class DoublyLinkedList:
    def __init__(self):
        self.head = None

    # Insert at the beginning
    def insert_at_beginning(self, data):
        new_node = Node(data)
        new_node.next = self.head
        if self.head:
            self.head.prev = new_node
        self.head = new_node

    # Insert at the end
    def insert_at_end(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = new_node
            return
        temp = self.head
        while temp.next:
            temp = temp.next
        temp.next = new_node
        new_node.prev = temp

    # Delete a node
    def delete_node(self, data):
        temp = self.head
        while temp and temp.data != data:
            temp = temp.next
        if not temp:
            print("Node not found!")
            return
        if temp.prev:
            temp.prev.next = temp.next
        else:
            self.head = temp.next
        if temp.next:
            temp.next.prev = temp.prev
        del temp
        print("Node deleted successfully.")

    # Display the list
    def display(self):
        temp = self.head
        if not temp:
            print("List is empty!")
            return
        print("Doubly Linked List:", end=" ")
        while temp:
            print(temp.data, end=" <-> ")
            temp = temp.next
        print("NULL")

    # Search for a node
    def search(self, data):
        temp = self.head
        pos = 1
        while temp:
            if temp.data == data:
                print(f"Element found at position {pos}")
                return
            temp = temp.next
            pos += 1
        print("Element not found in the list.")

# Menu-driven interface
dll = DoublyLinkedList()
while True:
    print("\nDoubly Linked List Operations:")
    print("1. Insert at Beginning\n2. Insert at End\n3. Delete a Node\n4. Display List\n5. Search for a Node\n6. Exit")
    choice = int(input("Enter your choice: "))
    
    if choice == 1:
        value = int(input("Enter value: "))
        dll.insert_at_beginning(value)
    elif choice == 2:
        value = int(input("Enter value: "))
        dll.insert_at_end(value)
    elif choice == 3:
        value = int(input("Enter value to delete: "))
        dll.delete_node(value)
    elif choice == 4:
        dll.display()
    elif choice == 5:
        value = int(input("Enter value to search: "))
        dll.search(value)
    elif choice == 6:
        print("Exiting program...")
        break
    else:
        print("Invalid choice! Try again.")
