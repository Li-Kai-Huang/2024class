#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Edge {
    int src, dest, weight;
};

// Comparator function to sort edges based on their weight
bool compareEdges(Edge a, Edge b) {
    return a.weight < b.weight;
}

// Disjoint Set Union (DSU) or Union-Find data structure
class DSU {
    vector<int> parent, rank;
public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (u != parent[u]) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    void unite(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV) {
            if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};

vector<Edge> kruskalMST(vector<Edge>& edges, int V) {
    sort(edges.begin(), edges.end(), compareEdges);
    DSU dsu(V);
    vector<Edge> mst;

    for (Edge& edge : edges) {
        if (dsu.find(edge.src) != dsu.find(edge.dest)) {
            mst.push_back(edge);
            dsu.unite(edge.src, edge.dest);
        }
    }

    return mst;
}
void printAdjacencyMatrix(vector<Edge>& mst, int V) {
    vector<vector<int>> adjMatrix(V, vector<int>(V, 0));

    for (Edge& edge : mst) {
        adjMatrix[edge.src][edge.dest] = edge.weight;
        adjMatrix[edge.dest][edge.src] = edge.weight; // 無向圖
    }

    cout << "Adjacency Matrix of the Minimum Spanning Tree:" << endl;
    cout << "    ";
    for (int i = 0; i < V; ++i) {
        cout << setw(3) << i;
    }
    cout << endl;
    for (int i = 0; i < V; ++i) {
        cout << setw(3) << i << " ";
        for (int j = 0; j < V; ++j) {
            cout << setw(3) << adjMatrix[i][j];
        }
        cout << endl;
    }
}

int main() {
    int V = 6; // Number of vertices
    vector<Edge> edges = {
        {0, 1, 10},
        {1, 2, 20},
        {1, 3, 25},
        {2, 4, 18},
        {3, 4, 22},
        {3, 5, 95},
        {4, 5, 77},
    };

    vector<Edge> mst = kruskalMST(edges, V);

    cout << "Edges in the Minimum Spanning Tree:" << endl;
    for (Edge& edge : mst) {
        cout << edge.src << " -- " << edge.dest << " == " << edge.weight << endl;
    }
    printAdjacencyMatrix(mst, V);
    return 0;
}