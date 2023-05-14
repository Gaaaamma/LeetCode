#include <iostream>
#include <vector>
#include <stack>
#include <numeric>
#include <queue>
using namespace std;

/*
#64 Minimum Path Sum
Attempt 1: 
DP

Q: Given a m x n grid filled with non-negative numbers, 
   find a path from top left to bottom right, which minimizes the sum of all numbers along its path.
   Note: You can only move either down or right at any point in time.
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> cost(grid.size(), vector<int>(grid[0].size(), 0));
        cost[0][0] = grid[0][0];
        for (int j = 1; j < grid[0].size(); j++) {
            cost[0][j] = cost[0][j - 1] + grid[0][j];
        }
        for (int i = 1; i < grid.size(); i++) {
            cost[i][0] = cost[i - 1][0] + grid[i][0];
        }
        for (int i = 1; i < grid.size(); i++) {
            for (int j = 1; j < grid[i].size(); j++) {
                int minPath = min(cost[i - 1][j], cost[i][j - 1]);
                cost[i][j] = minPath + grid[i][j];
            }
        }
        return cost.back().back();
    }
};

int main(int argc, char* argv[]) {
    Solution solution;
    vector<vector<vector<int>>> input{{{1,3,1}, {1,5,1}, {4,2,1}}, {{1,2,3}, {4,5,6}}, {{1,2,3,4,5}}, {{1},{2},{3},{4},{5}}};
    for (int i = 0; i < input.size(); i++) {
        cout << solution.minPathSum(input[i]) << "\n";
    }
}