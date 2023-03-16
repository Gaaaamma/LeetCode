#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
#674 Longest Continuous Increasing Subsequence
Attempt 1: 
use DP to solve

Q: Given an unsorted array of integers nums, 
   return the length of the longest continuous increasing subsequence (i.e. subarray). 
   The subsequence must be strictly increasing.
   
   A continuous increasing subsequence is defined by two indices l and r (l < r) 
   such that it is [nums[l], nums[l + 1], ..., nums[r - 1], nums[r]] and for each l <= i < r, nums[i] < nums[i + 1].
*/     

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size() == 1) return 1;
        vector<int> longest(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) 
                longest[i] = longest[i - 1] + 1;
        }
        return *max_element(longest.begin(), longest.end());
    }
};

int main(int argc, char* argv[]) {
    Solution solution;
    vector<vector<int>> input{{10,15,20,3,11}, {1,39,1,1,1,100,1,1,100,1}, {1,20}, {20,1}, {1}, {1,1,1,1,1}};
    for (int i = 0; i < input.size(); i++) {
        cout << solution.findLengthOfLCIS(input[i]) << "\n";
    }
}