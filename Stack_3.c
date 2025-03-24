#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Maximum size of the stack

int arr[MAX];  // Array to store stack elements
int top = -1;  // Index of the top element

// Function to push a value onto the stack
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot push %d\n", value);
    } else {
        arr[++top] = value;
        printf("%d pushed onto the stack.\n", value);
    }
}

// Function to pop a value from the stack
void pop() {
    if (top == -1) {
        printf("Stack Underflow! No elements to pop.\n");
    } else {
        printf("%d popped from the stack.\n", arr[top--]);
    }
}

// Function to peek the top element of the stack
void peek() {
    if (top == -1) {
        printf("Stack is empty. No top element.\n");
    } else {
        printf("Top element: %d\n", arr[top]);
    }
}

// Function to display the elements of the stack
void display() {
    if (top == -1) {
        printf("Stack is empty. No elements to display.\n");
    } else {
        printf("Stack elements: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

// Function to check if the stack is empty
void check_empty() {
    if (top == -1)
        printf("Stack is empty.\n");
    else
        printf("Stack is not empty.\n");
}

// Function to check if the stack is full
void check_full() {
    if (top == MAX - 1)
        printf("Stack is full.\n");
    else
        printf("Stack is not full.\n");
}

int main() {
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
                push(value);
                break;

            case 2: // Pop
                pop();
                break;

            case 3: // Peek
                peek();
                break;

            case 4: // Display
                display();
                break;

            case 5: // Check if Empty
                check_empty();
                break;

            case 6: // Check if Full
                check_full();
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
