# Complete program for Depth First Traversal (BFS).

def dfs(graph, start_vertex):
    visited = set()
    stack = []

    stack.append(start_vertex)

    print("Depth First Traversal starting from vertex", start_vertex, ":")

    while stack:
        vertex = stack.pop()

        if vertex not in visited:
            print(vertex, end=" ")
            visited.add(vertex)

            for neighbor in reversed(graph[vertex]):
                if neighbor not in visited:
                    stack.append(neighbor)
    print()

def main():
    graph = {}
    vertices = int(input("Enter number of vertices: "))

    for i in range(vertices):
        edges = list(map(int, input(f"Enter neighbors of vertex {i} (space-separated): ").split()))
        graph[i] = edges

    start_vertex = int(input(f"Enter the starting vertex (0-{vertices-1}): "))
    dfs(graph, start_vertex)

if __name__ == "__main__":
    main()
