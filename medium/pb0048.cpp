#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
using namespace std;

/*
#48 Rotate Image
Attempt 1: 
simulation

Q: You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
   You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. 
   DO NOT allocate another 2D matrix and do the rotation.
*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if (matrix.size() == 1) return;
        solve(matrix, 0, 0, matrix.size());
    }
    void solve(vector<vector<int>>& matrix, int startI, int startJ, int n) {
        if (n <= 1) return;
        for (int j = startJ; j < startJ + n - 1; j++) {
            int tmp = matrix[startI][j];
            matrix[startI][j] = matrix[startI + n - 1 - (j - startJ)][startJ];
            matrix[startI + n - 1 - (j - startJ)][startJ] = matrix[startI + n - 1][startJ + n - 1 - (j - startJ)];
            matrix[startI + n - 1][startJ + n - 1 - (j - startJ)] = matrix[startI + (j - startJ)][startJ + n - 1];
            matrix[startI + (j - startJ)][startJ + n - 1] = tmp;
        }
        solve(matrix, startI + 1, startJ + 1, n - 2);
    }
};
void show(const vector<vector<int>> nums) {
    if (nums.empty()) {
        cout << "[]\n";
    }
    for (int i = 0; i < nums.size(); i++) {
        cout << "[";
        for (int j = 0; j < nums[i].size() - 1; j++) {
            cout <<  nums[i][j] << ",";
        }
        cout << nums[i].back() << "]\n";
    }
}
int main(int argc, char* argv[]) {
    Solution solution;
    vector<vector<vector<int>>> input{{{1,2,3},{4,5,6},{7,8,9}}, {{1,2},{3,4}}, {{1}}};
    for (int i = 0; i < input.size(); i++) {
        show(input[i]);
        solution.rotate(input[i]);
        cout << "\n";
        show(input[i]);
        cout << "\n\n";
    }
}