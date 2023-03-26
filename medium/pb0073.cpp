#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/*
#73 Set Matrix Zeroes
Attempt 1: 
Simulation

Q: Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
   You must do it in place.
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> mSet;
        unordered_set<int> nSet;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == 0) {
                    mSet.insert(i);
                    nSet.insert(j);
                }
            }
        }
        
        for (int m : mSet) {
            for (int j = 0; j < matrix[m].size(); j++)
                matrix[m][j] = 0;
        }
        for (int n : nSet) {
            for (int i = 0; i < matrix.size(); i++)
                matrix[i][n] = 0;
        }
    }
};
void show(vector<vector<int>>& input) {
    for (int i = 0; i < input.size(); i++) {
        for (int j = 0; j < input[i].size(); j++) {
            cout << input[i][j] << " ";
        }
        cout << "\n";
    }
}
int main(int argc, char* argv[]) {
    Solution solution;
    vector<vector<vector<int>>> input{{{1,3,1}, {1,0,1}, {4,2,1}}, {{1,2,3}, {4,5,0}}, {{1,2,0,4,5}}, {{1},{0},{3},{4},{5}}};
    for (int i = 0; i < input.size(); i++) {
        show(input[i]);
        solution.setZeroes(input[i]);
        cout << "\n";
        show(input[i]);
        cout << "\n\n";
    }
}