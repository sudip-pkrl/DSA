#include <stdio.h>
#define TABLE_SIZE 10

int hashTable[TABLE_SIZE];

void initialize() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = -1; // -1 indicates empty slot
    }
}

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

void insert(int key) {
    int index = hashFunction(key);
    int originalIndex = index;
    while (hashTable[index] != -1) {
        index = (index + 1) % TABLE_SIZE;
        if (index == originalIndex) {
            printf("Hash table is full! Cannot insert %d\n", key);
            return;
        }
    }
    hashTable[index] = key;
}

void display() {
    printf("\nHash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("%d => %d\n", i, hashTable[i]);
    }
}

int main() {
    int n, key;
    initialize();

    printf("Enter the number of elements to insert: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter key %d: ", i + 1);
        scanf("%d", &key);
        insert(key);
    }

    display();

    return 0;
}
