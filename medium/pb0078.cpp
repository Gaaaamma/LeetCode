#include <iostream>
#include <vector>
using namespace std;

/*
#78 Subsets
Attempt 1: 
Use backtracking to solve

Complexity: O(-) 

Q: Given an integer array nums of unique elements, return all possible subsets (the power set).
   The solution set must not contain duplicate subsets. Return the solution in any order.
*/     
class Solution {
public:
    vector<vector<int>> result;
    vector<int> combination;
    vector<vector<int>> subsets(vector<int>& nums) {
        result.clear();
        combination.clear();
        backtracking(nums, 0, 0);
        return result;
    }
    void backtracking(vector<int>& nums, int index, int order) {
        result.push_back(combination);
        if (order == nums.size()) return;

        for (int i = index; i < nums.size(); i++) {
            combination.push_back(nums[i]);
            if (order + 1 <= nums.size())
                backtracking(nums, i + 1, order + 1);
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
    vector<vector<int>> input{{1}, {1,2}, {1,2,3}, {5,10,15}};
    for (int i = 0; i < input.size(); i++) {
        vector<vector<int>> result = solution.subsets(input[i]);
        output2D(result);
    }   
}