#include <iostream>
#include <vector>
using namespace std;

/*
#40 Combination Sum II
Attempt 1: 
Use backtracking to solve

Complexity: O(-) 

Q: Given a collection of candidate numbers (candidates) and a target number (target), 
   find all unique combinations in candidates where the candidate numbers sum to target.

   Each number in candidates may only be used once in the combination.
   Note: The solution set must not contain duplicate combinations.
*/     
class Solution {
public:
    vector<vector<int>> result;
    vector<int> combination;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        result.clear();
        combination.clear();
        sort(candidates.begin(), candidates.end());
        if (candidates.front() > target) return result;
        int sum = 0;
        backtracking(candidates, sum, target, 0, true);
        return result;
    }
    void backtracking(vector<int> candidates, int& sum, int target, int index, bool first) {
        if (sum == target) {
            result.push_back(combination);
            return;
        }
        for (int i = index; i < candidates.size(); i++) {
            if (i >= 1 && candidates[i] == candidates[i - 1] && first == false) continue;
            first = false;
            if (candidates[i] > target) continue;
            combination.push_back(candidates[i]);
            sum += candidates[i];
            if (sum <= target)
                backtracking(candidates, sum, target, i + 1, true);
            sum -= candidates[i];
            combination.pop_back();
        }
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
    vector<pair<vector<int>, int>> input{{{1,1,2,5,6,7,8}, 8}, {{2,5,2,1,2}, 5}};
    for (int i = 0; i < input.size(); i++) {
        output(solution.combinationSum2(input[i].first, input[i].second));
    }
}