# Function to solve Tower of Hanoi
def tower_of_hanoi(n, source, destination, auxiliary):
    if n == 1:
        print(f"Move disk 1 from {source} to {destination}")
        return
    # Move n-1 disks from source to auxiliary
    tower_of_hanoi(n - 1, source, auxiliary, destination)
    # Move the nth disk to destination
    print(f"Move disk {n} from {source} to {destination}")
    # Move n-1 disks from auxiliary to destination
    tower_of_hanoi(n - 1, auxiliary, destination, source)

# Input number of disks
n = int(input("Enter the number of disks: "))
print("The moves are:")
tower_of_hanoi(n, 'A', 'C', 'B') # A is source, C is destination, B is auxiliary