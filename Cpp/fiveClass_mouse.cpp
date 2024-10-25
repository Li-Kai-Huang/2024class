/*迷宮定義：

迷宮大小為12x12，其中0表示空地（可走），1表示牆壁（不可走）。
訪問狀態和路徑記錄：

使用visited陣列記錄每個位置是否被訪問過。
使用path向量記錄當前路徑。
使用allPaths向量記錄所有找到的路徑。
方向向量：

使用dx和dy陣列表示四個方向（右、下、左、上）的移動。
安全檢查函數：

isSafe函數檢查位置(x, y)是否在迷宮範圍內且是空地且未被訪問過。
深度優先搜索 (DFS) 函數：

dfs函數用於深度優先搜索迷宮中的所有可能路徑。
當前位置(x, y)被記錄到path中。
如果到達出口(N-1, N-1)，則將當前路徑保存到allPaths中。
否則，標記當前位置為已訪問，並遞迴搜索四個方向的鄰居位置。
回溯時，將當前位置標記為未訪問並從path中移除。
打印迷宮函數：

printMaze函數用於打印迷宮的結構，其中#表示牆壁，.表示空地。
主函數：

主函數中首先打印迷宮的結構。
然後從起點(0, 0)開始進行深度優先搜索。
最後，打印所有找到的路徑，如果沒有找到路徑則打印"No path found."。*/


#include <iostream>
#include <vector>

using namespace std;

const int N = 12; // 迷宮的大小
int maze[N][N] = {
    {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1},
    {1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1},
    {1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1},
    {1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1},
    {1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1},
    {1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0}
};

bool visited[N][N] = {false};
vector<pair<int, int>> path; // 用於記錄路徑
vector<vector<pair<int, int>>> allPaths; // 用於記錄所有路徑

int dx[] = {0, 1, 0, -1}; // 方向向量，用於表示上下左右四個方向
int dy[] = {1, 0, -1, 0}; // 方向向量，用於表示上下左右四個方向

// 檢查位置 (x, y) 是否安全，即是否在迷宮範圍內且是空地且未被訪問過
bool isSafe(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 0 && !visited[x][y]);
}

void dfs(int x, int y) {
    path.push_back({x, y}); // 記錄當前位置
    if (x == N-1 && y == N-1) { // 到達出口
        allPaths.push_back(path); // 保存當前路徑
    } else {
        visited[x][y] = true;// 標記當前位置為已訪問
        for (int i = 0; i < 4; i++) {// 遍歷四個方向
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (isSafe(nx, ny)) {//遞迴的部分
                dfs(nx, ny);
            }
        }
        visited[x][y] = false; // 回溯
    }
    path.pop_back(); // 回溯，移除當前位置
}

void printMaze() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (maze [i][j]==1){
                cout << "#" << " ";
            }
            else{
                cout << "1" << " ";
            }

        }
        cout << endl;
    }
}

int main() {
    cout << "Maze:" << endl;
    printMaze();
    cout << endl;

    dfs(0, 0);
    if (!allPaths.empty()) {
        cout << "Paths found:" << endl;
        for (const auto& p : allPaths) {
            for (const auto& coord : p) {
                cout << "(" << coord.first << ", " << coord.second << ") ";
            }
            cout << endl;
        }
    } else {
        cout << "No path found." << endl;
    }

    return 0;
}