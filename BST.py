# Menu driven program to perform various operations in Binary Search Tree (BST).

class Node:
    def __init__(self, data):
        self.data = data
        self.left = self.right = None

class BST:
    def __init__(self):
        self.root = None

    def insert(self, root, key):
        if root is None:
            return Node(key)
        if key < root.data:
            root.left = self.insert(root.left, key)
        else:
            root.right = self.insert(root.right, key)
        return root

    def delete(self, root, key):
        if root is None:
            return root
        if key < root.data:
            root.left = self.delete(root.left, key)
        elif key > root.data:
            root.right = self.delete(root.right, key)
        else:
            if root.left is None:
                return root.right
            elif root.right is None:
                return root.left
            temp = self.find_min(root.right)
            root.data = temp.data
            root.right = self.delete(root.right, temp.data)
        return root

    def find_min(self, root):
        while root.left:
            root = root.left
        return root

    def search(self, root, key):
        if root is None or root.data == key:
            return root
        if key < root.data:
            return self.search(root.left, key)
        return self.search(root.right, key)

    def inorder(self, root):
        if root:
            self.inorder(root.left)
            print(root.data, end=" ")
            self.inorder(root.right)

    def preorder(self, root):
        if root:
            print(root.data, end=" ")
            self.preorder(root.left)
            self.preorder(root.right)

    def postorder(self, root):
        if root:
            self.postorder(root.left)
            self.postorder(root.right)
            print(root.data, end=" ")

if __name__ == "__main__":
    bst = BST()
    while True:
        print("\n\n--- Binary Search Tree Operations ---")
        print("1. Insert\n2. Delete\n3. Search\n4. Inorder Traversal\n5. Preorder Traversal\n6. Postorder Traversal\n7. Exit")
        choice = int(input("Enter your choice: "))

        if choice == 1:
            val = int(input("Enter value to insert: "))
            bst.root = bst.insert(bst.root, val)
        elif choice == 2:
            val = int(input("Enter value to delete: "))
            bst.root = bst.delete(bst.root, val)
        elif choice == 3:
            val = int(input("Enter value to search: "))
            if bst.search(bst.root, val):
                print(f"{val} found in BST.")
            else:
                print(f"{val} not found in BST.")
        elif choice == 4:
            print("Inorder Traversal:", end=" ")
            bst.inorder(bst.root)
            print()
        elif choice == 5:
            print("Preorder Traversal:", end=" ")
            bst.preorder(bst.root)
            print()
        elif choice == 6:
            print("Postorder Traversal:", end=" ")
            bst.postorder(bst.root)
            print()
        elif choice == 7:
            print("Exiting program.")
            break
        else:
            print("Invalid choice! Try again.")
