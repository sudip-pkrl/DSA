#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr;
    int n, i;

    // Allocate memory for 5 integers using malloc
    n = 5;
    /*
    For user input:-
    printf("Enter the number of elements for malloc: ");
    scanf("%d", &n);
    */

    printf("Allocating memory for %d integers using malloc...\n", n);
    ptr = (int*)malloc(n * sizeof(int));

    if (ptr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Initialize and print the array elements
    for (i = 0; i < n; ++i) {
        ptr[i] = i + 1;
    }
    printf("Malloc: ");
    for (i = 0; i < n; ++i) {
        printf("%d ", ptr[i]);
    }
    printf("\n");

    // Reallocate memory for 10 integers using realloc
    n = 10;
    printf("Reallocating memory for %d integers using realloc...\n", n);
    ptr = (int*)realloc(ptr, n * sizeof(int));

    if (ptr == NULL) {
        printf("Memory reallocation failed.\n");
        return 1;
    }

    // Initialize the new elements and print the array elements
    for (i = 5; i < n; ++i) {
        ptr[i] = i + 1;
    }
    printf("Realloc: ");
    for (i = 0; i < n; ++i) {
        printf("%d ", ptr[i]);
    }
    printf("\n");

    // Allocate memory for 10 integers using calloc
    printf("Allocating memory for %d integers using calloc...\n", n);
    int *ptr_calloc = (int*)calloc(n, sizeof(int));

    if (ptr_calloc == NULL) {
        printf("Memory allocation using calloc failed.\n");
        return 1;
    }

    // Print the array elements initialized by calloc (all elements should be 0)
    printf("Calloc: ");
    for (i = 0; i < n; ++i) {
        printf("%d ", ptr_calloc[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(ptr);
    free(ptr_calloc);

    printf("Memory freed successfully.\n");
    return 0;
}
