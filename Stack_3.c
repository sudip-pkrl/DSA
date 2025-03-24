#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Maximum size of the stack

int main() {
    int arr[MAX];  // Array to store stack elements
    int top = -1;  // Index of the top element
    int choice, value;

    printf("\n--- Stack Menu ---\n");

    while (1) {  // Infinite loop until the user chooses to exit
        printf("\n1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Check if Empty\n");
        printf("6. Check if Full\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 7) {  // Exit condition
            printf("Exiting program.\n");
            break;
        }

        switch (choice) {
            case 1: // Push
                printf("Enter value to push: ");
                scanf("%d", &value);
                if (top == MAX - 1) {
                    printf("Stack Overflow! Cannot push %d\n", value);
                } else {
                    arr[++top] = value;
                    printf("%d pushed onto the stack.\n", value);
                }
                break;

            case 2: // Pop
                if (top == -1) {
                    printf("Stack Underflow! No elements to pop.\n");
                } else {
                    printf("%d popped from the stack.\n", arr[top--]);
                }
                break;

            case 3: // Peek
                if (top == -1) {
                    printf("Stack is empty. No top element.\n");
                } else {
                    printf("Top element: %d\n", arr[top]);
                }
                break;

            case 4: // Display
                if (top == -1) {
                    printf("Stack is empty. No elements to display.\n");
                } else {
                    printf("Stack elements: ");
                    for (int i = top; i >= 0; i--) {
                        printf("%d ", arr[i]);
                    }
                    printf("\n");
                }
                break;

            case 5: // Check if Empty
                if (top == -1)
                    printf("Stack is empty.\n");
                else
                    printf("Stack is not empty.\n");
                break;

            case 6: // Check if Full
                if (top == MAX - 1)
                    printf("Stack is full.\n");
                else
                    printf("Stack is not full.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
