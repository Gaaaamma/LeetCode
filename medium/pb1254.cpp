#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
#1254 Number of Closed Islands
Attempt 1: 
BFS

Q: Given a 2D grid consists of 0s (land) and 1s (water).  
   An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally 
   (all left, top, right, bottom) surrounded by 1s.
   Return the number of closed islands.
*/

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int counter = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1 || visited[i][j]) continue;
                if (BFS(grid, visited, i, j)) counter++;
            }
        }

        return counter;
    }
    
    bool BFS(const vector<vector<int>>& grid, vector<vector<bool>>& visited, int startI, int startJ) {
        bool closed = true;
        queue<pair<int, int>> que;
        visited[startI][startJ] = true;
        que.push({startI, startJ});

        while (!que.empty()) {
            pair<int, int> node = que.front();
            que.pop();

            // Check closed
            if (node.first == 0 || node.first == grid.size() - 1) closed = false;
            if (node.second == 0 || node.second == grid[0].size() - 1) closed = false;

            // Add new node
            int upI = node.first - 1;
            int downI = node.first + 1;
            int leftJ = node.second - 1;
            int rightJ = node.second + 1;
            if (upI >= 0 && grid[upI][node.second] == 0 && !visited[upI][node.second]) {
                visited[upI][node.second] = true;
                que.push({upI, node.second});
            }
            if (leftJ >= 0 && grid[node.first][leftJ] == 0 && !visited[node.first][leftJ]) {
                visited[node.first][leftJ] = true;
                que.push({node.first, leftJ});
            }
            if (downI < grid.size() && grid[downI][node.second] == 0 && !visited[downI][node.second]) {
                visited[downI][node.second] = true;
                que.push({downI, node.second});
            }
            if (rightJ < grid[0].size() && grid[node.first][rightJ] == 0 && !visited[node.first][rightJ]) {
                visited[node.first][rightJ] = true;
                que.push({node.first, rightJ});
            }
        }
        return closed;
    }
};

template<class T>
void show1D(const vector<T>& input) {
    if (input.empty()) {
        cout << "[]\n";
        return;
    }
    cout << "[";
    for (int i = 0; i < input.size() - 1; i++) {
        cout << input[i] << ",";
    }
    cout << input.back() << "]\n";
}

template<class T>
void show2DGraph(const vector<vector<T>>& input) {
    for (int i = 0; i < input.size(); i++) {
        show1D(input[i]);
    }
}

int main(int argc, char* argv[]) {
    Solution solution;
    vector<vector<vector<int>>> input{{{1,1,1,1,1,1,1,0}, {1,0,0,0,0,1,1,0}, {1,0,1,0,1,1,1,0}, {1,0,0,0,0,1,0,1}, {1,1,1,1,1,1,1,0}}, 
                                    {{0,0,1,0,0}, {0,1,0,1,0}, {0,1,1,1,0}}, 
                                    {{1,1,1,1,1,1,1}, {1,0,0,0,0,0,1}, {1,0,1,1,1,0,1}, {1,0,1,0,1,0,1}, {1,0,1,1,1,0,1}, {1,0,0,0,0,0,1}, {1,1,1,1,1,1,1}}};
    for (int i = 0; i < input.size(); i++) {
        show2DGraph(input[i]);
        cout << "Closed Islands: " << solution.closedIsland(input[i]) << "\n\n";
    }
}