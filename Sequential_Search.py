def sequential_search(arr, key):
    for i in range(len(arr)):
        if arr[i] == key:
            return i
    return -1

n = int(input("Enter number of elements: "))
arr = []

print(f"Enter {n} elements:")
for _ in range(n):
    arr.append(int(input()))

key = int(input("Enter element to search: "))

index = sequential_search(arr, key)

if index != -1:
    print(f"Element found at position {index+1} (index {index})")
else:
    print("Element not found.")
