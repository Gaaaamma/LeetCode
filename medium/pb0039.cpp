#include <iostream>
#include <vector>
using namespace std;

/*
#39 Combination Sum
Attempt 1: 
Use backtracking to solve

Complexity: O(-) 

Q: Given an array of distinct integers candidates and a target integer target, 
   return a list of all unique combinations of candidates where the chosen numbers sum to target. 
   You may return the combinations in any order.

   The same number may be chosen from candidates an unlimited number of times. 
   Two combinations are unique if the frequency of at least one of the chosen numbers is different.

   The test cases are generated such that the number of unique combinations 
   that sum up to target is less than 150 combinations for the given input.
*/     
class Solution {
public:
    vector<vector<int>> result;
    vector<int> combination;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        result.clear();
        combination.clear();
        sort(candidates.begin(), candidates.end());
        if (candidates.front() > target) return vector<vector<int>>{};
        int sum = 0;
        backtracking(candidates, sum, target, 0);
        return result;
    }
    void backtracking(vector<int> candidates, int& sum, int target, int index) {
        if (sum == target) {
            result.push_back(combination);
            return;
        } 
        for (int i = index; i < candidates.size(); i++) {
            if (candidates[i] > target)
                continue;
            combination.push_back(candidates[i]);
            sum += candidates[i];
            if (sum <= target) 
                backtracking(candidates, sum, target, i);
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
    vector<pair<vector<int>, int>> input{{{2,3,4,5}, 8}, {{2,3,4}, 16}};
    for (int i = 0; i < input.size(); i++) {
        output(solution.combinationSum(input[i].first, input[i].second));
    }
}