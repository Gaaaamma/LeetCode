#include <iostream>
#include <vector>
using namespace std;

/*
#77 Combination
Attempt 1: 
Use backtracking to solve

Complexity: O(N) 

Q: Given two integers n and k, 
   return all possible combinations of k numbers chosen from the range [1, n].
   You may return the answer in any order.
*/     
class Solution {
public:
    vector<int> base;
    vector<vector<int>> combine(int n, int k) {
        base = vector<int>(n, 0);
        for (int i = 0; i < n; i++) {
            base[i] = i + 1;
        }
        vector<vector<int>> result;
        vector<int> output;
        backtracking(0, n, output, k, result);
        return result;
    }
    void backtracking(int left, int right, vector<int>& output, int k, vector<vector<int>>& result) {
        if (k == 0) {
            result.push_back(output);
            return;
        }
        for (int i = left; i < right; i++) {
            output.push_back(base[i]);
            backtracking(i + 1, right, output, k - 1, result);
            output.pop_back();
        }
        return;
    }
};

void output(vector<vector<int>> result) {
    if (result.size() == 0) {
        cout << "[]\n";
        return;
    }
    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << "[";
        for (int j = 0; j < result[i].size() - 1; j++) {
            cout << result[i][j] << ", ";
        }
        if (i != result.size() - 1) {
            cout << result[i].back() << "], ";
        } else {
            cout << result[i].back() << "]]\n";
        }
    }
}

int main(int argc, char* argv[]) {
    Solution solution;
    vector<pair<int, int>> input{{4, 2}, {3, 3}, {5, 1}, {5, 2}, {5, 3}, {5,4}};
    for (int i = 0; i < input.size(); i++) {
        output(solution.combine(input[i].first, input[i].second));
    }
}