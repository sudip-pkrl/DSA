# Program for Dijkstra's Algorithm to find shortest path.

import sys

# Number of vertices in the graph
V = 9

# Function to find the vertex with the minimum distance value
def min_distance(dist, spt_set):
    min_val = sys.maxsize
    min_index = -1
    for v in range(V):
        if not spt_set[v] and dist[v] <= min_val:
            min_val = dist[v]
            min_index = v
    return min_index

# Function to implement Dijkstra's Algorithm
def dijkstra(graph, src):
    dist = [sys.maxsize] * V  # Distance from source to each vertex
    spt_set = [False] * V  # Shortest path tree set
    
    dist[src] = 0  # Distance from source to itself is 0

    # Find the shortest path for all vertices
    for _ in range(V - 1):
        u = min_distance(dist, spt_set)  # Pick the vertex with the smallest distance
        spt_set[u] = True  # Mark the picked vertex as processed

        for v in range(V):
            # Update dist[v] if the current distance is greater than the new path through u
            if (not spt_set[v] and graph[u][v] and dist[u] != sys.maxsize and dist[u] + graph[u][v] < dist[v]):
                dist[v] = dist[u] + graph[u][v]

    # Print the shortest distance from source to all other vertices
    print("Vertex \t Distance from Source")
    for i in range(V):
        print(f"{i} \t {dist[i]}")

# Example graph
graph = [[0, 4, 0, 0, 0, 0, 0, 8, 0],
         [4, 0, 8, 0, 0, 0, 0, 11, 0],
         [0, 8, 0, 7, 0, 4, 0, 0, 2],
         [0, 0, 7, 0, 9, 14, 0, 0, 0],
         [0, 0, 0, 9, 0, 10, 0, 0, 0],
         [0, 0, 4, 14, 10, 0, 2, 0, 0],
         [0, 0, 0, 0, 0, 2, 0, 1, 6],
         [8, 11, 0, 0, 0, 0, 1, 0, 7],
         [0, 0, 2, 0, 0, 0, 6, 7, 0]]

src = 0  # Starting vertex
dijkstra(graph, src)
