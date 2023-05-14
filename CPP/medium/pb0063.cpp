#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
#63 Unique Paths II
Attempt 1: 
Use DP to solve

Complexity: O(N) 

Q: You are given an m x n integer array grid. 
   There is a robot initially located at the top-left corner (i.e., grid[0][0]). 
   The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). 
   The robot can only move either down or right at any point in time.

   An obstacle and space are marked as 1 or 0 respectively in grid. 
   A path that the robot takes cannot include any square that is an obstacle.

   Return the number of possible unique paths that the robot can take to reach the bottom-right corner.
   The testcases are generated so that the answer will be less than or equal to 2 * 109.
*/     
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0] == 1) return 0;
        int row = obstacleGrid.size();
        int column = obstacleGrid[0].size();
        vector<vector<int>> ways(row, vector<int>(column, 0));
        ways[0][0] = 1;
        for (int i = 1; i < row; i++) {
            if (obstacleGrid[i][0] == 1) 
                ways[i][0] = 0;
            else 
                ways[i][0] = ways[i - 1][0];
        }

        for (int i = 1; i < column; i++) {
            if (obstacleGrid[0][i] == 1)
                ways[0][i] = 0;
            else
                ways[0][i] = ways[0][i - 1];
        }

        for (int i = 1; i < row; i++) {
            for (int j = 1; j < column; j++) {
                if (obstacleGrid[i][j] == 1) 
                    ways[i][j] = 0;
                else 
                    ways[i][j] = ways[i - 1][j] + ways[i][j - 1];
            }
        }

        return ways.back().back();
    }
};

int main(int argc, char* argv[]) {
    Solution solution;
    vector<vector<vector<int>>> input{{{0,0,0}, {0,1,0}, {0,0,0}}, {{1,0,0}, {0,0,0}, {0,0,0}}, {{0,1,0}, {0,1,0}, {0,0,0}}};
    for (int i = 0; i < input.size(); i++) {
        cout << solution.uniquePathsWithObstacles(input[i]) << "\n";
    }   
}