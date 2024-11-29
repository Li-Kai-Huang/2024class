#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    int numVertices; // 頂點數量
    vector<vector<int>> adjMatrix; // 相鄰矩陣

public:
    // 構造函數
    Graph(int vertices) {
        numVertices = vertices;
        adjMatrix.resize(vertices, vector<int>(vertices, 0)); // 初始化相鄰矩陣為0
    }

    // 添加邊
    void addEdge(int src, int dest) {
        adjMatrix[src][dest] = 1;
        adjMatrix[dest][src] = 1; // 無向圖
    }

    // 移除邊
    void removeEdge(int src, int dest) {
        adjMatrix[src][dest] = 0;
        adjMatrix[dest][src] = 0; // 無向圖
    }

    // 顯示圖
    void display() {
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g(10);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(2, 6);
    g.addEdge(3, 7);
    g.addEdge(4, 7);
    g.addEdge(5, 8);
    g.addEdge(6, 8);
    g.addEdge(9, 7);
    g.addEdge(8, 9);

    cout << "Adjacency Matrix of the graph:" << endl;
    g.display();

    return 0;
}