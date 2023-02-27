#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/*
#47 PermutationsII
Attempt 1: 
Use backtracking to solve

Complexity: O(-) 

Q: Given a collection of numbers, nums, that might contain duplicates, 
   return all possible unique permutations in any order.
*/     
class Solution {
public:
    vector<vector<int>> result;
    vector<int> permutation;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        result.clear();
        permutation.clear();
        sort(nums.begin(), nums.end());
        unordered_set<int> uoset;
        backtracking(nums, uoset);
        return result;
    }
    void backtracking(vector<int>& nums, unordered_set<int>& uoset) {
        if (permutation.size() == nums.size()) {
            result.push_back(permutation);
            return;
        }
        unordered_set<int> selfUsed;
        for (int i = 0; i < nums.size(); i++) {
            if (uoset.count(i)) continue;
            if (i > 0 && nums[i] == nums[i - 1] && selfUsed.count(nums[i])) continue;
            permutation.push_back(nums[i]);
            uoset.insert(i);
            selfUsed.insert(nums[i]);
            backtracking(nums, uoset);
            uoset.erase(i);
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
    vector<vector<int>> input{{1}, {1,1,2}, {1,2,2,2}, {1,2,2,3}};
    for (int i = 0; i < input.size(); i++) {
        vector<vector<int>> result = solution.permuteUnique(input[i]);
        output2D(result);
    }   
}