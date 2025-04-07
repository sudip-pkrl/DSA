def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key
    return arr

def main():
    print("Enter numbers separated by space:")
    user_input = input()
    arr = list(map(int, user_input.strip().split()))

    sorted_arr = insertion_sort(arr.copy())
    print("Sorted using Insertion Sort:", sorted_arr)

if __name__ == "__main__":
    main()
