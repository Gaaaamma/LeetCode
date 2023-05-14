#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
#200 Number of Islands
Attempt 1: 
BFS

Q: Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
   An island is surrounded by water and is formed by 
   connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
*/
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> checked(grid.size(), vector<bool>(grid[0].size(), false));
        int counter = 0;
        queue<pair<int, int>> que;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '0' || checked[i][j]) continue;
                checked[i][j] = true;
                counter++;
                que.push({i, j});
                while (!que.empty()) {
                    int m = que.front().first;
                    int n = que.front().second;
                    que.pop();
                    if (m - 1 >= 0 && grid[m - 1][n] == '1' && checked[m - 1][n] == false) {
                        checked[m - 1][n] = true;
                        que.push({m - 1, n});
                    }
                    if (n - 1 >= 0 && grid[m][n - 1] == '1' && checked[m][n - 1] == false) {
                        checked[m][n - 1] = true;
                        que.push({m, n - 1});
                    }
                    if (m + 1 < grid.size() && grid[m + 1][n] == '1' && checked[m + 1][n] == false) {
                        checked[m + 1][n] = true;
                        que.push({m + 1, n});
                    }
                    if (n + 1 < grid[i].size() && grid[m][n + 1] == '1' && checked[m][n + 1] == false) {
                        checked[m][n + 1] = true;
                        que.push({m, n + 1});
                    }
                }
            }
        }
        return counter;
    }
};
void show(vector<vector<char>>& input) {
    for (int i = 0; i < input.size(); i++) {
        for (int j = 0; j < input[i].size(); j++) {
            cout << input[i][j];
        }
        cout << "\n";
    }
}
int main(int argc, char* argv[]) {
    Solution solution;
    vector<vector<vector<char>>> input{{{'1','1','1','1','0'}, {'1','1','0','1','0'}, {'1','1','0','0','0'}, {'0','0','0','0','0'}}, {{'1','1','0','0','0'}, {'1','1','0','0','0'}, {'0','0','1','0','0'}, {'0','0','0','1','1'}}};
    for (int i = 0; i < input.size(); i++) {
        show(input[i]);
        cout << solution.numIslands(input[i]) << "\n\n";
    }
    
}