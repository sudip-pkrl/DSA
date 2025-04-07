def selection_sort(arr):
    for i in range(len(arr)):
        min_idx = i
        for j in range(i + 1, len(arr)):
            if arr[j] < arr[min_idx]:
                min_idx = j
        arr[i], arr[min_idx] = arr[min_idx], arr[i]
    return arr

def main():
    print("Enter numbers separated by space:")
    user_input = input()
    arr = list(map(int, user_input.strip().split()))

    sorted_arr = selection_sort(arr.copy())
    print("Sorted using Selection Sort:", sorted_arr)

if __name__ == "__main__":
    main()
