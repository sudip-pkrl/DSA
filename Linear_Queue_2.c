#include <stdio.h>
#include <stdlib.h>

#define MAX 5

// Queue structure
typedef struct {
    int items[MAX];
    int front, rear;
} Queue;

// Function prototypes
void enqueue(Queue *q, int element);
int dequeue(Queue *q);
void display(Queue *q);
int isFull(Queue *q);
int isEmpty(Queue *q);

int main() {
    Queue q;
    q.front = -1;
    q.rear = -1;

    int choice, element;

    while (1) {
        printf("\nQueue Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &element);
                enqueue(&q, element);
                break;

            case 2:
                element = dequeue(&q);
                if (element != -1) {
                    printf("Dequeued element: %d\n", element);
                }
                break;

            case 3:
                display(&q);
                break;

            case 4:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Enqueue function
void enqueue(Queue *q, int element) {
    if (isFull(q)) {
        printf("Queue is full! Cannot enqueue.\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = element;
    printf("Enqueued: %d\n", element);
}

// Dequeue function
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1;
    }
    int element = q->items[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1; // Reset the queue
    } else {
        q->front++;
    }
    return element;
}

// Display function
void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

// Check if queue is full
int isFull(Queue *q) {
    return q->rear == MAX - 1;
}

// Check if queue is empty
int isEmpty(Queue *q) {
    return q->front == -1;
}

// Explanation:-

// 1. In the main function, we create a queue with a max size of 5.
// 2. We use a while loop to keep the program running until the user chooses to exit.
// 3. The user can choose from the options to enqueue, dequeue, display, or exit the program.   
// 4. The enqueue option allows the user to enter an element and add it to the queue.
// 5. The dequeue option removes the first element from the queue.
// 6. The display option displays all the elements of the queue.
// 7. The isFull and isEmpty methods check if the queue is full or empty, respectively.
// 8. The main function calls the menu-driven interface until the user chooses to exit.
// 9. The program ends when the user chooses to exit.


/*

Explanation:-

Queue Structure:

Contains front and rear to track the queue's front and rear positions.
Uses an array (items[MAX]) to store the queue elements.

Functions:

enqueue(): Adds an element to the rear of the queue if not full.
dequeue(): Removes and returns an element from the front if not empty.
display(): Prints all elements in the queue.
isFull(): Checks if the queue is full.
isEmpty(): Checks if the queue is empty.

Menu-Driven:

The user is repeatedly presented with options to perform queue operations.
Exits only when the user selects the "Exit" option.

*/