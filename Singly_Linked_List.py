# Menu driven program to show operations in singly linked list :-

class Node:
    """Class representing a node in the linked list"""
    def __init__(self, data):
        self.data = data
        self.next = None

class SinglyLinkedList:
    """Class representing the singly linked list"""
    def __init__(self):
        self.head = None

    def insert_at_beginning(self, data):
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node

    def insert_at_end(self, data):
        new_node = Node(data)
        if self.head is None:
            self.head = new_node
            return
        temp = self.head
        while temp.next:
            temp = temp.next
        temp.next = new_node

    def delete_node(self, key):
        temp = self.head

        if temp and temp.data == key:
            self.head = temp.next
            return

        prev = None
        while temp and temp.data != key:
            prev = temp
            temp = temp.next

        if not temp:
            print("Element not found.")
            return

        prev.next = temp.next

    def search_node(self, key):
        temp = self.head
        pos = 1
        while temp:
            if temp.data == key:
                print(f"Element found at position {pos}")
                return
            temp = temp.next
            pos += 1
        print("Element not found.")

    def display_list(self):
        temp = self.head
        if not temp:
            print("List is empty.")
            return
        print("Linked List:", end=" ")
        while temp:
            print(temp.data, end=" -> ")
            temp = temp.next
        print("NULL")

def menu():
    sll = SinglyLinkedList()
    while True:
        print("\n--- Singly Linked List Menu ---")
        print("1. Insert at Beginning")
        print("2. Insert at End")
        print("3. Delete a Node")
        print("4. Search for a Node")
        print("5. Display List")
        print("6. Exit")
        
        choice = int(input("Enter your choice: "))

        if choice == 1:
            value = int(input("Enter value: "))
            sll.insert_at_beginning(value)
        elif choice == 2:
            value = int(input("Enter value: "))
            sll.insert_at_end(value)
        elif choice == 3:
            value = int(input("Enter value to delete: "))
            sll.delete_node(value)
        elif choice == 4:
            value = int(input("Enter value to search: "))
            sll.search_node(value)
        elif choice == 5:
            sll.display_list()
        elif choice == 6:
            print("Exiting program.")
            break
        else:
            print("Invalid choice! Try again.")

# Run the menu-driven program
menu()
