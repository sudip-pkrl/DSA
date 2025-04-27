# Complete program for Breadth First Search Traversal (BFS).

from collections import deque

def bfs(graph, start_vertex):
    visited = set()
    queue = deque()

    visited.add(start_vertex)
    queue.append(start_vertex)

    print("Breadth First Traversal starting from vertex", start_vertex, ":")

    while queue:
        vertex = queue.popleft()
        print(vertex, end=" ")

        for neighbor in graph[vertex]:
            if neighbor not in visited:
                visited.add(neighbor)
                queue.append(neighbor)
    print()

def main():
    graph = {}
    vertices = int(input("Enter number of vertices: "))

    for i in range(vertices):
        edges = list(map(int, input(f"Enter neighbors of vertex {i} (space-separated): ").split()))
        graph[i] = edges

    start_vertex = int(input(f"Enter the starting vertex (0-{vertices-1}): "))
    bfs(graph, start_vertex)

if __name__ == "__main__":
    main()
