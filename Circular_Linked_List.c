// Menu driven program to show operations in circular linked list :-

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Head pointer
struct Node* head = NULL;

// Function to insert at the beginning
void insertAtBeginning(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
}

// Function to insert at the end
void insertAtEnd(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    if (head == NULL) {
        newNode->next = newNode;
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

// Function to delete a node
void deleteNode(int value) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;

    // If the node to be deleted is the head
    if (head->data == value) {
        if (head->next == head) { 
            free(head);
            head = NULL;
        } else {
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = head->next;
            free(head);
            head = temp->next;
        }
        printf("Node deleted successfully.\n");
        return;
    }

    // Searching for the node
    while (temp->next != head && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp->data == value) {
        prev->next = temp->next;
        free(temp);
        printf("Node deleted successfully.\n");
    } else {
        printf("Node not found!\n");
    }
}

// Function to display the list
void display() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(Head)\n");
}

// Function to search for a node
void search(int value) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = head;
    int pos = 1;
    do {
        if (temp->data == value) {
            printf("Element found at position %d\n", pos);
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);
    printf("Element not found in the list.\n");
}

// Menu-driven main function
int main() {
    int choice, value;
    while (1) {
        printf("\nCircular Linked List Operations:\n");
        printf("1. Insert at Beginning\n2. Insert at End\n3. Delete a Node\n4. Display List\n5. Search for a Node\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(value);
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(value);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
