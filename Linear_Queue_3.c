// Linear Queue :-

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

// Global queue variables
int queue[MAX];
int front = -1, rear = -1;

void enqueue(int element) {
    if (rear == MAX - 1) {
        printf("Queue is full! Cannot enqueue.\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = element;
}

int dequeue() {
    if (front == -1) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1;
    }
    int element = queue[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
    return element;
}

void display() {
    if (front == -1) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice, element;

    while (1) {
        printf("\n-----Queue Menu-----\n");
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
                enqueue(element);
                break;

            case 2:
                element = dequeue();
                if (element != -1) {
                    printf("Dequeued element: %d\n", element);
                }
                break;

            case 3:
                display();
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