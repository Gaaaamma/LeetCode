#include <iostream>
#include <vector>
using namespace std;

/*
#90 Subsets II
Attempt 1: 
Use backtracking to solve

Complexity: O(-) 

Q: Given an integer array nums that may contain duplicates, 
   return all possible subsets (the power set).
   The solution set must not contain duplicate subsets. 
   Return the solution in any order.
*/     
class Solution {
public:
    vector<vector<int>> result;
    vector<int> combination;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        result.clear();
        combination.clear();
        sort(nums.begin(), nums.end());
        backtracking(nums, 0);
        return result;
    }
    void backtracking (vector<int>& nums, int index) {
        result.push_back(combination);
        for (int i = index; i < nums.size(); i++) {
            if (i != 0 && nums[i] == nums[i - 1] && i != index)
                continue;
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
    vector<vector<int>> input{{1,1}, {1,2,2}, {0}, {1,2,3,2,1}};
    for (int i = 0; i < input.size(); i++) {
        vector<vector<int>> result = solution.subsetsWithDup(input[i]);
        output2D(result);
    }   
}