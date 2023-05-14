#include <iostream>
#include <vector>
#include <deque>
using namespace std;

/*
#51 N-Queens
Attempt 1: 

Complexity: O(N)

Q: The n-queens puzzle is the problem of placing n queens on an n x n chessboard 
   such that no two queens attack each other.

   Given an integer n, return all distinct solutions to the n-queens puzzle. 
   You may return the answer in any order.

   Each solution contains a distinct board configuration of the n-queens' placement, 
   where 'Q' and '.' both indicate a queen and an empty space, respectively.
*/

class Solution {
public:
    vector<vector<string>> result;
    vector<vector<string>> solveNQueens(int n) {
        result.clear();
        vector<int> forbid;
        backtracking(n, 0, forbid);
        return result;
    }
    vector<string> createGraph(vector<int> forbid) {
        vector<string> permutation;
        for (int i = 0; i < forbid.size(); i++) {
            string pattern(forbid.size(), '.');
            pattern[forbid[i]] = 'Q';
            permutation.push_back(pattern);
        }
        return permutation;
    }
    void backtracking(int n, int degree, vector<int>& forbid) {
        if (degree == n) {
            // Use forbid to create the graph
            result.push_back(createGraph(forbid));
            return;
        }
        for (int i = 0; i < n; i++) {
            bool possible = true;
            for (int k = 0; k < forbid.size(); k++) {
                if (i == forbid[k] || i == forbid[k] + (degree - k) || i == forbid[k] - (degree - k)) {
                    possible = false;
                    break;
                }
            }
            if (possible == false) continue;
            forbid.push_back(i);
            backtracking(n, degree + 1, forbid);
            forbid.pop_back();
        }
    }
};

void output(vector<vector<string>> result) {
    if (result.empty()) {
        cout << "No possible permutation\n\n";
        return;
    }
    for (int i = 0; i < result.size(); i++) {
        cout << "Sol" << (i + 1) << ":\n";
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << "\n";
        }
        cout << "\n";
    }
}

int main(int argc, char* argv[]) {
    Solution solution;
    vector<int> input{1,3,4,7};

    for (int i = 0; i < input.size(); i++) {
        cout << "Input: " << input[i] << "\n";
        output(solution.solveNQueens(input[i]));
    }

}