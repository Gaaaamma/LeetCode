#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
#1020 Number of Enclaves
Attempt 1: 
BFS

Q: You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

   A move consists of walking from one land cell to another adjacent (4-directionally) 
   land cell or walking off the boundary of the grid.
   
   Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.
*/

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int result = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                result += BFS(grid, visited, i, j);
            }
        }
        return result;
    }
    int BFS(vector<vector<int>>& grid, vector<vector<bool>>& visited, int startI, int startJ) {
        if (grid[startI][startJ] == 0 || visited[startI][startJ]) return 0;

        int counter = 0;
        bool center = true;
        queue<pair<int, int>> que;        
        visited[startI][startJ] = true;
        que.push({startI, startJ});

        while (!que.empty()) {
            pair<int, int> node = que.front();
            counter++;
            que.pop();

            // center
            if (node.first == 0 || node.first == grid.size() - 1 
            || node.second == 0 || node.second == grid[0].size() - 1) center = false;

            int upI = node.first - 1;
            int downI = node.first + 1;
            int leftJ = node.second - 1;
            int rightJ = node.second + 1;
            if (upI >= 0 && grid[upI][node.second] == 1 && !visited[upI][node.second]) {
                visited[upI][node.second] = true;
                que.push({upI, node.second});
            }
            if (downI < grid.size() && grid[downI][node.second] == 1 && !visited[downI][node.second]) {
                visited[downI][node.second] = true;
                que.push({downI, node.second});
            }
            if (leftJ >= 0 && grid[node.first][leftJ] == 1 && !visited[node.first][leftJ]) {
                visited[node.first][leftJ] = true;
                que.push({node.first, leftJ});
            }
            if (rightJ < grid[0].size() && grid[node.first][rightJ] == 1 && !visited[node.first][rightJ]) {
                visited[node.first][rightJ] = true;
                que.push({node.first, rightJ});
            }
        }
        return (center == true) ? counter : 0;
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
        cout << "Enclaves: " << solution.numEnclaves(input[i]) << "\n\n";
    }
}