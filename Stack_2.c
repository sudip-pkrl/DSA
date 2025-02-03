#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Maximum size of the stack

typedef struct Stack {
    int arr[MAX];  // Array to store stack elements
    int top;       // Index of the top element
} Stack;

// Function to initialize the stack
void initStack(Stack *s) {
    s->top = -1;
}

// Function to check if the stack is full
int isFull(Stack *s) {
    return s->top == MAX - 1;
}

// Function to check if the stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Function to push an element onto the stack
void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow! Cannot push %d\n", value);
    } else {
        s->arr[++(s->top)] = value;
        printf("%d pushed onto the stack.\n", value);
    }
}

// Function to pop an element from the stack
void pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow! No elements to pop.\n");
    } else {
        printf("%d popped from the stack.\n", s->arr[(s->top)--]);
    }
}

// Function to get the top element of the stack
void peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty. No top element.\n");
    } else {
        printf("Top element: %d\n", s->arr[s->top]);
    }
}

// Function to display all elements in the stack
void display(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty. No elements to display.\n");
    } else {
        printf("Stack elements: ");
        for (int i = s->top; i >= 0; i--) {
            printf("%d ", s->arr[i]);
        }
        printf("\n");
    }
}

int main() {
    Stack stack;
    initStack(&stack);

    int choice, value;

    do {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Check if Empty\n");
        printf("6. Check if Full\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&stack, value);
                break;

            case 2:
                pop(&stack);
                break;

            case 3:
                peek(&stack);
                break;

            case 4:
                display(&stack);
                break;

            case 5:
                if (isEmpty(&stack))
                    printf("Stack is empty.\n");
                else
                    printf("Stack is not empty.\n");
                break;

            case 6:
                if (isFull(&stack))
                    printf("Stack is full.\n");
                else
                    printf("Stack is not full.\n");
                break;

            case 7:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}


/*

Explanation:-

In this program, we have defined a Stack struct to represent the stack. 
It contains an array to store the stack elements and a top variable to keep track 
of the top element of the stack.

The initStack function is used to initialize the stack by setting the top variable to -1,
indicating that the stack is empty.

The isFull and isEmpty functions are used to check if the stack is full or empty, respectively.

The push, pop, peek, and display functions are used to perform the corresponding operations 
on the stack.

The main function provides a menu-driven interface to interact with the stack. 
It allows the user to push, pop, peek, display the stack, check if the stack is empty or full,
and exit the program. The user can choose from the options to push, pop, peek, display, 
check if empty, check if full, or exit the program.  

*/


/*

Structure Definition:

A Stack structure contains an array (arr) to store stack elements and an integer (top) 
to track the top of the stack.

Functions:

initStack(): Initializes the stack by setting top to -1.
isFull(): Returns 1 if the stack is full, 0 otherwise.
isEmpty(): Returns 1 if the stack is empty, 0 otherwise.
push(): Adds an element to the stack if it’s not full.
pop(): Removes the top element of the stack if it’s not empty.
peek(): Displays the top element without removing it.
display(): Prints all elements of the stack.

Menu-Driven Interface:

The main() function provides a menu-driven interface for the user to perform operations 
on the stack until they choose to exit.

*/