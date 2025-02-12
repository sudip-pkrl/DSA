#include <stdio.h>

// Function to perform Bubble Sort
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    int swapped;

    for (i = 0; i < n - 1; i++) {
        swapped = 0; // Flag to optimize and stop if already sorted
        
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) { 
                // Swap elements
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                
                swapped = 1; 
            }
        }

        // If no elements were swapped, break (array is already sorted)
        if (!swapped) {
            break;
        }
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Main function
int main() {
    int n;
    
    // Taking input for array size
    printf("Enter the number of elements:");
    scanf("%d", &n);

    int arr[n]; // Declare array of size n

    // Taking input for array elements
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Unsorted array: ");
    printArray(arr, n);

    // Sorting array using Bubble Sort
    bubbleSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);
    
    return 0;
}