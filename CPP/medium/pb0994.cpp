#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

/*
#994 Rotting Orange
Attempt 1: 
BFS 

Q: You are given an m x n grid where each cell can have one of three values:

   0 representing an empty cell,
   1 representing a fresh orange, or
   2 representing a rotten orange.
   Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.
   
   Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.
*/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> que;
        int counts = 0;
        int rotten = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) counts++;
                else if (grid[i][j] == 2) {
                    que.push({i,j});
                    counts++;
                    rotten++;
                }
            }
        }
        
        if (counts == 0 || counts == rotten) return 0;
        if (rotten == 0) return -1;

        int minutes = 0;
        while (!que.empty()) {
            int queSize = que.size();
            for (int i = 0; i < queSize; i++) {
                int m = que.front().first;
                int n = que.front().second;
                if (m - 1 >= 0 && grid[m - 1][n] == 1) {
                    grid[m - 1][n] = 2;
                    que.push({m - 1, n});
                    rotten++;
                }
                if (m + 1 < grid.size() && grid[m + 1][n] == 1) {
                    grid[m + 1][n] = 2;
                    que.push({m + 1, n});
                    rotten++;
                }
                if (n - 1 >= 0 && grid[m][n - 1] == 1) {
                    grid[m][n - 1] = 2;
                    que.push({m, n - 1});
                    rotten++;
                }
                if (n + 1 < grid[m].size() && grid[m][n + 1] == 1) {
                    grid[m][n + 1] = 2;
                    que.push({m, n + 1});
                    rotten++;
                }
                que.pop();
            }

            // Iterate
            minutes++;
            if (rotten == counts) return minutes;
        }
        return -1;
    }
};

int main(int argc, char* argv[]) {
    Solution solution;
    vector<vector<vector<int>>> input{{{2,1,1}, {1,1,0}, {0,1,1}}, {{2,1,1}, {0,1,1}, {1,0,1}}, {{0,1,1,0}}, {{0,0,0,0}}};
    for (int i = 0; i < input.size(); i++) {
        cout << solution.orangesRotting(input[i]) << "\n";
    }
}