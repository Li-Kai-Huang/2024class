#include <bits/stdc++.h>
using namespace std;

const int V = 7; // 頂點數量

// Dijkstra算法計算最短路徑
vector<int> dijkstra(vector<vector<int>>& graph, int src) {
    vector<int> dist(V, INT_MAX); // 用於存儲每個頂點的最短距離
    dist[src] = 0; // 初始化源節點的距離為0
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 優先隊列
    pq.push({0, src}); // 將源節點加入優先隊列

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                pq.push({dist[v], v});
            }
        }
    }

    return dist; // 返回最短距離
}

void printShortestPaths(vector<int>& dist, int src) {
    cout << "Vertex\tDistance from Source " << src << endl;
    for (int i = 0; i < V; i++) {
        cout << i << "\t" << dist[i] << endl;
    }
}

int main() {
    vector<tuple<int, int, int>> edges = {
        {0, 1, 4},
        {0, 2, 6},
        {0, 3, 6},
        {1, 2, 1},
        {1, 4, 7},
        {2, 4, 6},
        {2, 5, 4},
        {3, 2, 2},
        {3, 5, 5},
        {4, 2, 6},
        {4, 6, 6},
        {5, 4, 1},
        {5, 6, 8},
    };

    vector<vector<int>> graph(V, vector<int>(V, 0));

    for (auto& edge : edges) {
        int u, v, w;
        tie(u, v, w) = edge;
        graph[u][v] = w;
        graph[v][u] = w; // 無向圖
    }

    int src = 0; // 源節點
    vector<int> dist = dijkstra(graph, src);

    printShortestPaths(dist, src);

    return 0;
}