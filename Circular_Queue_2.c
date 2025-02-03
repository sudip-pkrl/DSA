#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
    int items[MAX];
    int front, rear;
} CircularQueue;

// Function prototypes
void enqueue(CircularQueue *q, int element);
int dequeue(CircularQueue *q);
void display(CircularQueue *q);
int isFull(CircularQueue *q);
int isEmpty(CircularQueue *q);

int main() {
    CircularQueue q;
    q.front = -1;
    q.rear = -1;

    int choice, element;

    while (1) {
        printf("\nCircular Queue Menu:\n");
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
void enqueue(CircularQueue *q, int element) {
    if (isFull(q)) {
        printf("Queue is full! Cannot enqueue.\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX;
    q->items[q->rear] = element;
    printf("Enqueued: %d\n", element);
}

// Dequeue function
int dequeue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1;
    }
    int element = q->items[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1; // Reset the queue
    } else {
        q->front = (q->front + 1) % MAX;
    }
    return element;
}

// Display function
void display(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    int i = q->front;
    while (1) {
        printf("%d ", q->items[i]);
        if (i == q->rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

// Check if queue is full
int isFull(CircularQueue *q) {
    return (q->rear + 1) % MAX == q->front;
}

// Check if queue is empty
int isEmpty(CircularQueue *q) {
    return q->front == -1;
}


// Explanation:-

// 1. In the main function, we create a circular queue with a max size of 5.
// 2. We use a while loop to keep the program running until the user chooses to exit.
// 3. The user can choose from the options to enqueue, dequeue, display, or exit the program.   
// 4. The enqueue option allows the user to enter an element and add it to the queue.
// 5. The dequeue option removes the first element from the queue.
// 6. The display option displays all the elements of the queue.
// 7. The isFull and isEmpty methods check if the queue is full or empty, respectively.
// 8. The main function calls the menu-driven interface until the user chooses to exit.
// 9. The program ends when the user chooses to exit.   
