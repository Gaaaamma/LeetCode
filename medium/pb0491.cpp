#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/*
#491 Non-decreasing Subsequences
Attempt 1: 
Use backtracking to solve

Complexity: O(-) 

Q: Given an integer array nums, 
   return all the different possible non-decreasing subsequences of the given array with at least two elements. 
   You may return the answer in any order.
*/     
class Solution {
public:
    vector<vector<int>> result;
    vector<int> combination;
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        result.clear();
        combination.clear();
        backtracking(nums, 0);
        return result;
    }
    void backtracking(vector<int>& nums, int index) {
        unordered_set<int> uoset;
        if (combination.size() >= 2) {
            result.push_back(combination);
        }
        for (int i = index; i < nums.size(); i++) {
            if (i != index && uoset.count(nums[i]))
                continue;
            if (!combination.empty() && nums[i] < combination.back())
                continue;
            uoset.insert(nums[i]);
            combination.push_back(nums[i]);
            backtracking(nums, i + 1);
            combination.pop_back();
        }
    }
};

void output(vector<int> input) {
    if (input.empty()) {
        cout << "[]";
        return;
    }
    cout << "[";
    for (int i = 0; i < input.size() - 1; i++) {
        cout << input[i] << ",";
    }
    cout << input.back() << "]";
}
void output2D(vector<vector<int>> input) {
    if (input.empty()) {
        cout << "[]\n";
        return;
    }
    cout << "[";
    for (int i = 0; i < input.size() - 1; i++) {
        if (input[i].empty()) {
            cout << "[], ";
        } else {
            output(input[i]);
            cout << ", ";
        }
    }
    if (!input.back().empty()) {
        output(input.back());
        cout << "]\n";
    } else {
        cout << "]\n";
    }
}

int main(int argc, char* argv[]) {
    Solution solution;
    vector<vector<int>> input{{1}, {1,2,3}, {3,2,1}, {1,1,1,2,2,3}, {3,3,3,2,2,2,1}, {5,5,6,7,6,5,4,5,6}};
    for (int i = 0; i < input.size(); i++) {
        vector<vector<int>> result = solution.findSubsequences(input[i]);
        output2D(result);
    }   
}