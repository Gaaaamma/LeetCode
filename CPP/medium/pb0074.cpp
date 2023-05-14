#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/*
#74 Search a 2D matrix
Attempt 1: 
Binary Search

Q: You are given an m x n integer matrix matrix with the following two properties:

   Each row is sorted in non-decreasing order.
   The first integer of each row is greater than the last integer of the previous row.
   Given an integer target, return true if target is in matrix or false otherwise.
   
   You must write a solution in O(log(m * n)) time complexity.
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Two tier binary search
        int leftRow = 0;
        int rightRow = matrix.size();
        while (leftRow < rightRow) {
            int middleRow = leftRow + (rightRow - leftRow) / 2;
            if (matrix[middleRow][0] == target) return true;
            else if (matrix[middleRow][0] > target) rightRow = middleRow;
            else if (matrix[middleRow][0] < target) leftRow = middleRow + 1;
        }
        if (leftRow - 1 < 0) return false;
        int left = 0;
        int right = matrix[leftRow - 1].size();
        while (left < right) {
            int middle = left + (right - left) / 2;
            if (matrix[leftRow - 1][middle] == target) return true;
            else if (matrix[leftRow - 1][middle] > target) right = middle;
            else if (matrix[leftRow - 1][middle] < target) left = middle + 1;
        }
        return false;
    }
};
int main(int argc, char* argv[]) {
    Solution solution;
    vector<vector<vector<int>>> input{{{1,2,3,4}, {5,5,6,7}, {8,9,10,11}}, {{10,13,14}, {20,25,26}}};
    vector<int> target{10, 5};
    for (int i = 0; i < input.size(); i++) {
        cout << solution.searchMatrix(input[i], target[i]) << "\n";
    }
    
}