# Program for Kruskal's Algorithm to find Minimum Spanning Tree (MST).

class DisjointSet:
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [0] * n

    def find(self, i):
        if self.parent[i] != i:
            self.parent[i] = self.find(self.parent[i])
        return self.parent[i]

    def union(self, x, y):
        rootX = self.find(x)
        rootY = self.find(y)

        if rootX != rootY:
            if self.rank[rootX] < self.rank[rootY]:
                self.parent[rootX] = rootY
            elif self.rank[rootX] > self.rank[rootY]:
                self.parent[rootY] = rootX
            else:
                self.parent[rootY] = rootX
                self.rank[rootX] += 1


class Kruskal:
    def __init__(self, vertices, edges):
        self.V = vertices
        self.edges = edges

    def run(self):
        result = []
        disjoint_set = DisjointSet(self.V)

        # Sort the edges by weight
        self.edges.sort(key=lambda edge: edge[2])

        for edge in self.edges:
            u, v, w = edge
            if disjoint_set.find(u) != disjoint_set.find(v):
                result.append(edge)
                disjoint_set.union(u, v)

        return result


# Example usage
if __name__ == "__main__":
    V = 4  # Number of vertices
    edges = [
        (0, 1, 10),
        (0, 2, 6),
        (0, 3, 5),
        (1, 3, 15),
        (2, 3, 4)
    ]

    kruskal_algorithm = Kruskal(V, edges)
    mst = kruskal_algorithm.run()

    print("Edges in the MST:")
    for edge in mst:
        print(f"{edge[0]} -- {edge[1]} == {edge[2]}")
