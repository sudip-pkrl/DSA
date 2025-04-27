// Program for Dijkstra's Algorithm to find shortest path.

#include <stdio.h>
#include <limits.h>

#define V 9 // Number of vertices in graph

// Function to find the vertex with the minimum distance value
int minDistance(int dist[], int sptSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (sptSet[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to implement Dijkstra's Algorithm
void dijkstra(int graph[V][V], int src) {
    int dist[V];  // The output array dist[i] holds the shortest distance from src to i
    int sptSet[V]; // sptSet[i] will be true if vertex i is included in shortest path tree

    // Initialize all distances as INFINITE and sptSet[] as false
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;  // Use INT_MAX to represent infinity
        sptSet[i] = 0;      // Mark all vertices as not processed
    }

    dist[src] = 0; // Distance from source to itself is 0

    // Find the shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet); // Pick the minimum distance vertex from the set of vertices
        sptSet[u] = 1; // Mark the picked vertex as processed

        // Update dist[] for the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++) {
            // Update dist[v] if and only if it's not in sptSet, there's an edge from u to v, and the total distance is smaller than the current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the constructed distance array
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX) {
            printf("%d \t\t INF\n", i);  // INF means there's no path from src to i
        } else {
            printf("%d \t\t %d\n", i, dist[i]);
        }
    }
}

int main() {
    // Example graph (adjacency matrix representation)
    int graph[V][V] = { 
        { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } 
    };

    int src = 0;  // Starting vertex
    printf("Running Dijkstra's Algorithm...\n");
    dijkstra(graph, src);

    return 0;
}