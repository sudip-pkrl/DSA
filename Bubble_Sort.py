def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        swapped = False
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:  # Swap if the element is greater
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swapped = True
        if not swapped:  # Stop if already sorted
            break

# Taking input from the user
n = int(input("Enter the number of elements: "))
arr = list(map(int, input("Enter the elements separated by spaces: ").split()))

print("Unsorted array:", arr)
bubble_sort(arr)
print("Sorted array:", arr)
