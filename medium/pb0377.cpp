#include <iostream>
#include <vector>
#include <stack>
#include <numeric>
using namespace std;

/*
#377 Combination Sum IV
Attempt 1: 
Use DP to solve

Complexity: O(NM) 

Q: Given an array of distinct integers nums and a target integer target, 
   return the number of possible combinations that add up to target.
   The test cases are generated so that the answer can fit in a 32-bit integer.

*/     
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> possible(target + 1, 0);
        possible[0] = 1;
        for (int i = 0; i <= target; i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i >= nums[j])
                    possible[i] = possible[i] + possible[i - nums[j]];
            }
        }
        return possible.back();
    }
};

int main(int argc, char* argv[]) {
    Solution solution;
    vector<pair<vector<int>, int32_t>> input{{{1,2,3}, 4}, {{9}, 3}};
    for (int i = 0; i < input.size(); i++) {
        cout << solution.combinationSum4(input[i].first, input[i].second) << "\n";
    }   
}