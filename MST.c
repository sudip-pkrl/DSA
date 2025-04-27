// Program to find Minimum Spanning Tree (MST) from a given graph.

#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define INF 99999

typedef struct {
    int u, v, weight;
} Edge;

int parent[MAX], rank[MAX];

int find(int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent[i]);
}

void unionSets(int u, int v) {
    int root_u = find(u);
    int root_v = find(v);
    if (root_u != root_v) {
        if (rank[root_u] > rank[root_v])
            parent[root_v] = root_u;
        else if (rank[root_u] < rank[root_v])
            parent[root_u] = root_v;
        else {
            parent[root_v] = root_u;
            rank[root_u]++;
        }
    }
}

int compare(const void *a, const void *b) {
    return ((Edge *)a)->weight - ((Edge *)b)->weight;
}

void kruskal(Edge edges[], int E, int V) {
    qsort(edges, E, sizeof(Edge), compare);
    
    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    int mstWeight = 0;
    printf("Edges in MST:\n");
    for (int i = 0; i < E; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].weight;

        if (find(u) != find(v)) {
            unionSets(u, v);
            printf("%d - %d: %d\n", u, v, w);
            mstWeight += w;
        }
    }
    printf("Total weight of MST: %d\n", mstWeight);
}

int main() {
    int V = 4;  // Number of vertices
    int E = 5;  // Number of edges
    Edge edges[] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    kruskal(edges, E, V);
    return 0;
}
