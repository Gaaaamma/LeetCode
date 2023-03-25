#include <iostream>
#include <vector>
#include <stack>
#include <numeric>
#include <queue>
using namespace std;

/*
#54 Spiral Matrix
Attempt 1: 
Simulation (use recursive to solve)

Q: Given an m x n matrix, return all elements of the matrix in spiral order.
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int m = matrix.size();
        int n = matrix[0].size();
        result.reserve(m * n);
        solve(result, matrix, 0, 0, m, n);
        return result;
    }

    void solve(vector<int>& result, vector<vector<int>>& matrix, int startM, int startN, int m, int n) {
        if (m <= 0 || n <= 0) return;
        // up
        for (int j = startN; j < startN + n; j++) 
            result.push_back(matrix[startM][j]);

        // right
        for (int i = startM + 1; i < startM + m - 1; i++)
            result.push_back(matrix[i][startN + n - 1]);

        // down
        for (int j = startN + n - 1; j >= startN; j--) {
            if (m == 1) break;
            result.push_back(matrix[startM + m - 1][j]);
        }

        // left
        for (int i = startM + m - 2; i > startM; i--) {
            if (n == 1) break;
            result.push_back(matrix[i][startN]);
        }

        // recursive
        solve(result, matrix, startM + 1, startN + 1, m - 2, n - 2);
    }
};
void show(const vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << "\n";
}
int main(int argc, char* argv[]) {
    Solution solution;
    vector<vector<vector<int>>> input{{{1,2,3}, {4,5,6}, {7,8,9}}, {{1,2,3,4,5}, {6,7,8,9,10}, {11,12,13,14,15}}, {{1,2,3,4,5}}, {{1},{2},{3},{4},{5}}};
    for (int i = 0; i < input.size(); i++) {
        show(solution.spiralOrder(input[i]));
    }
}