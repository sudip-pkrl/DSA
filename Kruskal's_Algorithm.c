// Program for Kruskal's Algorithm to find Minimum Spanning Tree (MST).

#include <stdio.h>
#include <stdlib.h>

// Structure to represent a graph edge
struct Edge {
    int src, dest, weight;
};

// Structure to represent a subset for union-find
struct Subset {
    int parent;
    int rank;
};

// Function to compare two edges (for sorting)
int compareEdges(const void *a, const void *b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

// Find function for union-find
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Union function for union-find
void unionSets(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Function to implement Kruskal's Algorithm
void kruskal(struct Edge edges[], int V, int E) {
    struct Edge result[V]; // This will store the MST
    int e = 0;  // Count of edges in MST
    int i = 0;  // Initial index of sorted edges
    struct Subset *subsets = (struct Subset*) malloc(V * sizeof(struct Subset));

    // Initialize subsets (each vertex is its own parent)
    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Sort all edges in non-decreasing order by weight
    qsort(edges, E, sizeof(edges[0]), compareEdges);

    // Iterate over sorted edges and add them to the MST
    while (e < V - 1 && i < E) {
        struct Edge next_edge = edges[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        // If including this edge does not form a cycle
        if (x != y) {
            result[e++] = next_edge;
            unionSets(subsets, x, y);
        }
    }

    // Print the constructed MST
    printf("Edges in the MST:\n");
    for (i = 0; i < e; i++)
        printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);

    free(subsets);
}

int main() {
    int V = 4; // Number of vertices
    int E = 5; // Number of edges

    struct Edge edges[] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    kruskal(edges, V, E);

    return 0;
}
