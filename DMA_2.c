#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr1, *ptr2, *ptr3;
    int n, i;

    // Using malloc
    printf("Enter the number of elements for malloc: ");
    scanf("%d", &n);
    ptr1 = (int *)malloc(n * sizeof(int));
    if (ptr1 == NULL) {
        printf("Memory allocation failed for malloc.\n");
        return 1;
    }
    printf("Memory allocated using malloc.\n");

    // Initializing and printing malloc memory
    for (i = 0; i < n; i++) {
        ptr1[i] = i + 1;
        printf("%d ", ptr1[i]);
    }
    printf("\n");

    // Using calloc
    printf("\nEnter the number of elements for calloc: ");
    scanf("%d", &n);
    ptr2 = (int *)calloc(n, sizeof(int));
    if (ptr2 == NULL) {
        printf("Memory allocation failed for calloc.\n");
        free(ptr1); // Free the previously allocated memory
        return 1;
    }
    printf("Memory allocated using calloc.\n");

    // Printing calloc memory (initialized to zero)
    for (i = 0; i < n; i++) {
        printf("%d ", ptr2[i]);
    }
    printf("\n");

    // Using realloc
    printf("\nEnter the new size for realloc: ");
    scanf("%d", &n);
    ptr1 = (int *)realloc(ptr1, n * sizeof(int));
    if (ptr1 == NULL) {
        printf("Memory reallocation failed.\n");
        free(ptr2); // Free other allocated memory
        return 1;
    }
    printf("Memory reallocated using realloc.\n");

    // Initializing and printing reallocated memory
    for (i = 0; i < n; i++) {
        ptr1[i] = i + 10;
        printf("%d ", ptr1[i]);
    }
    printf("\n");

    // Freeing memory
    free(ptr1);
    free(ptr2);
    printf("\nMemory freed successfully.\n");

    return 0;
}
