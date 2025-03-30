// Menu driven program to show operations in list :-

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insertAtEnd(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    
    if (head == NULL) {
        head = newNode;
        return;
    }
    
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteNode(int value) {
    struct Node* temp = head, *prev = NULL;
    
    if (temp != NULL && temp->data == value) {
        head = temp->next;
        free(temp);
        return;
    }
    
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }
    
    if (temp == NULL) return;
    
    prev->next = temp->next;
    free(temp);
}

void displayList() {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int searchList(int value) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == value)
            return 1;
        temp = temp->next;
    }
    return 0;
}

int main() {
    int choice, value;
    do {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Search\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(value);
                break;
            case 3:
                displayList();
                break;
            case 4:
                printf("Enter value to search: ");
                scanf("%d", &value);
                if (searchList(value))
                    printf("Value found in list.\n");
                else
                    printf("Value not found in list.\n");
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);
    
    return 0;
}
