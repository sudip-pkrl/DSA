# Program to find Minimum Spanning Tree (MST) from a given graph.

class DisjointSet:
    def __init__(self, vertices):
        self.parent = [i for i in range(vertices)]
        self.rank = [0] * vertices

    def find(self, u):
        if self.parent[u] != u:
            self.parent[u] = self.find(self.parent[u])  # Path compression
        return self.parent[u]

    def union(self, u, v):
        root_u = self.find(u)
        root_v = self.find(v)
        if root_u != root_v:
            if self.rank[root_u] > self.rank[root_v]:
                self.parent[root_v] = root_u
            elif self.rank[root_u] < self.rank[root_v]:
                self.parent[root_u] = root_v
            else:
                self.parent[root_v] = root_u
                self.rank[root_u] += 1

def kruskal(vertices, edges):
    edges.sort(key=lambda x: x[2])  # Sort edges by weight
    ds = DisjointSet(vertices)
    mst = []
    mst_weight = 0

    for u, v, weight in edges:
        if ds.find(u) != ds.find(v):
            ds.union(u, v)
            mst.append((u, v, weight))
            mst_weight += weight

    print("Edges in MST:")
    for u, v, weight in mst:
        print(f"{u} - {v}: {weight}")
    print(f"Total weight of MST: {mst_weight}")

# Example usage
vertices = 4  # Number of vertices
edges = [
    (0, 1, 10),
    (0, 2, 6),
    (0, 3, 5),
    (1, 3, 15),
    (2, 3, 4)
]

kruskal(vertices, edges)
