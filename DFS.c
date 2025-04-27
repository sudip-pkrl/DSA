// Complete program for Depth First Traversal (BFS).

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Stack structure for DFS
struct Stack {
    int items[MAX];
    int top;
};

struct Stack* createStack() {
    struct Stack* s = (struct Stack*)malloc(sizeof(struct Stack));
    s->top = -1;
    return s;
}

int isEmpty(struct Stack* s) {
    return s->top == -1;
}

void push(struct Stack* s, int value) {
    if (s->top == MAX - 1)
        printf("\nStack is Full!!");
    else
        s->items[++(s->top)] = value;
}

int pop(struct Stack* s) {
    if (isEmpty(s)) {
        printf("\nStack is empty");
        return -1;
    } else {
        return s->items[(s->top)--];
    }
}

// DFS function
void dfs(int adj[][MAX], int vertices, int startVertex) {
    int visited[MAX] = {0};
    struct Stack* s = createStack();

    push(s, startVertex);

    printf("Depth First Traversal starting from vertex %d:\n", startVertex);

    while (!isEmpty(s)) {
        int currentVertex = pop(s);

        if (!visited[currentVertex]) {
            printf("%d ", currentVertex);
            visited[currentVertex] = 1;
        }

        for (int i = vertices - 1; i >= 0; i--) {
            if (adj[currentVertex][i] == 1 && !visited[i]) {
                push(s, i);
            }
        }
    }
    printf("\n");
}

int main() {
    int vertices;
    int adj[MAX][MAX];
    int startVertex;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter the starting vertex (0-%d): ", vertices-1);
    scanf("%d", &startVertex);

    dfs(adj, vertices, startVertex);

    return 0;
}
