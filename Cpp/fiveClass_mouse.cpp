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

int dx[] = {0, 1, 0, -1}; // 方向向量
int dy[] = {1, 0, -1, 0};

bool isSafe(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 0 && !visited[x][y]);
}

void dfs(int x, int y) {
    path.push_back({x, y}); // 記錄當前位置
    if (x == N-1 && y == N-1) { // 到達出口
        allPaths.push_back(path); // 保存當前路徑
    } else {
        visited[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (isSafe(nx, ny)) {
                dfs(nx, ny);
            }
        }
        visited[x][y] = false; // 回溯
    }
    path.pop_back(); // 回溯
}

int main() {
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