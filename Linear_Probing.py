TABLE_SIZE = 10

class HashTable:
    def __init__(self):
        self.table = [-1] * TABLE_SIZE

    def hash_function(self, key):
        return key % TABLE_SIZE

    def insert(self, key):
        index = self.hash_function(key)
        original_index = index
        while self.table[index] != -1:
            index = (index + 1) % TABLE_SIZE
            if index == original_index:
                print(f"Hash table is full! Cannot insert {key}")
                return
        self.table[index] = key

    def display(self):
        print("\nHash Table:")
        for i in range(TABLE_SIZE):
            print(f"{i} => {self.table[i]}")

if __name__ == "__main__":
    ht = HashTable()

    n = int(input("Enter the number of elements to insert: "))

    for i in range(n):
        key = int(input(f"Enter key {i + 1}: "))
        ht.insert(key)

    ht.display()
