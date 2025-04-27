def binary_search(arr, key):
    low = 0
    high = len(arr) - 1
    
    while low <= high:
        mid = (low + high) // 2
        if arr[mid] == key:
            return mid
        elif arr[mid] < key:
            low = mid + 1
        else:
            high = mid - 1
    return -1

n = int(input("Enter number of elements: "))
arr = []

print(f"Enter {n} sorted elements:")
for _ in range(n):
    arr.append(int(input()))

key = int(input("Enter element to search: "))

index = binary_search(arr, key)

if index != -1:
    print(f"Element found at position {index+1} (index {index})")
else:
    print("Element not found.")
