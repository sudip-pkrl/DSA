def heapify(arr, n, i):
    largest = i     # Initialize largest as root
    left = 2 * i + 1  # left child
    right = 2 * i + 2  # right child

    if left < n and arr[left] > arr[largest]:
        largest = left

    if right < n and arr[right] > arr[largest]:
        largest = right

    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        heapify(arr, n, largest)

def heap_sort(arr):
    n = len(arr)

    # Build a maxheap
    for i in range(n//2 - 1, -1, -1):
        heapify(arr, n, i)

    # Extract elements one by one
    for i in range(n-1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]  # swap
        heapify(arr, i, 0)

def print_array(arr):
    for i in arr:
        print(i, end=" ")
    print()

# Example usage
arr = [12, 11, 13, 5, 6, 7]
print("Given array:")
print_array(arr)

heap_sort(arr)

print("\nSorted array:")
print_array(arr)
