def shell_sort(arr):
    n = len(arr)
    gap = n // 2
    while gap > 0:
        for i in range(gap, n):
            temp = arr[i]
            j = i
            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j - gap]
                j -= gap
            arr[j] = temp
        gap //= 2
    return arr

def main():
    print("Enter numbers separated by space:")
    user_input = input()
    arr = list(map(int, user_input.strip().split()))

    sorted_arr = shell_sort(arr.copy())
    print("Sorted using Shell Sort:", sorted_arr)

if __name__ == "__main__":
    main()
