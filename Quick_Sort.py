def quick_sort(arr):
    if len(arr) <= 1:
        return arr
    else:
        pivot = arr[-1]  # choosing the last element as pivot
        left = [x for x in arr[:-1] if x <= pivot]
        right = [x for x in arr[:-1] if x > pivot]
        return quick_sort(left) + [pivot] + quick_sort(right)

def print_array(arr):
    for i in arr:
        print(i, end=" ")
    print()

# Example usage
arr = [10, 7, 8, 9, 1, 5]
print("Given array:")
print_array(arr)

sorted_arr = quick_sort(arr)

print("\nSorted array:")
print_array(sorted_arr)
