# Menu driven program to show operations in list :-

class Node:
    """A node in the linked list"""
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    """Linked List with basic operations"""
    def __init__(self):
        self.head = None

    def insert(self, data):
        """Insert a node at the end of the list"""
        new_node = Node(data)
        if not self.head:
            self.head = new_node
        else:
            temp = self.head
            while temp.next:
                temp = temp.next
            temp.next = new_node
        print(f"{data} inserted into the list.")

    def delete(self, key):
        """Delete a node by value"""
        temp = self.head

        if temp and temp.data == key:
            self.head = temp.next
            temp = None
            print(f"{key} deleted from the list.")
            return

        prev = None
        while temp and temp.data != key:
            prev = temp
            temp = temp.next

        if not temp:
            print(f"{key} not found in the list.")
            return

        prev.next = temp.next
        temp = None
        print(f"{key} deleted from the list.")

    def display(self):
        """Display the linked list"""
        temp = self.head
        if not temp:
            print("The list is empty.")
            return
        print("Linked List:", end=" ")
        while temp:
            print(temp.data, end=" -> ")
            temp = temp.next
        print("None")

    def search(self, key):
        """Search for an element in the list"""
        temp = self.head
        pos = 1
        while temp:
            if temp.data == key:
                print(f"{key} found at position {pos}.")
                return
            temp = temp.next
            pos += 1
        print(f"{key} not found in the list.")

def menu():
    """Display menu and handle user input"""
    linked_list = LinkedList()

    while True:
        print("\nMenu:")
        print("1. Insert")
        print("2. Delete")
        print("3. Display")
        print("4. Search")
        print("5. Exit")
        
        choice = input("Enter your choice: ")

        if choice == '1':
            data = int(input("Enter the value to insert: "))
            linked_list.insert(data)
        elif choice == '2':
            key = int(input("Enter the value to delete: "))
            linked_list.delete(key)
        elif choice == '3':
            linked_list.display()
        elif choice == '4':
            key = int(input("Enter the value to search: "))
            linked_list.search(key)
        elif choice == '5':
            print("Exiting the program.")
            break
        else:
            print("Invalid choice! Please enter a number between 1 and 5.")

if __name__ == "__main__":
    menu()
