#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/*
#46 Permutations
Attempt 1: 
Use backtracking to solve

Complexity: O(-) 

Q: Given an array nums of distinct integers, 
   return all the possible permutations. You can return the answer in any order.
*/     
class Solution {
public:
    vector<vector<int>> result;
    vector<int> permutation;
    vector<vector<int>> permute(vector<int>& nums) {
        result.clear();
        permutation.clear();
        unordered_set<int> uoset;
        backtracking(nums, uoset, 0);
        return result;
    }
    void backtracking(vector<int>& nums, unordered_set<int>& uoset, int count) {
        if (count == nums.size()) {
            result.push_back(permutation);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (uoset.count(nums[i])) continue;
            permutation.push_back(nums[i]);
            uoset.insert(nums[i]);
            backtracking(nums, uoset, count + 1);
            uoset.erase(nums[i]);
            permutation.pop_back();
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
    vector<vector<int>> input{{1}, {1,2,3}, {3,2,1}, {1,2,3}, {0,1}};
    for (int i = 0; i < input.size(); i++) {
        vector<vector<int>> result = solution.permute(input[i]);
        output2D(result);
    }   
}