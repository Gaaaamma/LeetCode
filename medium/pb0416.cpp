#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
#416 Partition Equal Subset Sum
Attempt 1: 
Use DP to solve

Complexity: O(N^2) 

Q: Given an integer array nums, 
   return true if you can partition the array into two subsets such that the sum of the elements 
   in both subsets is equal or false otherwise.
*/     
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int targetSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            targetSum += nums[i];
        }
        if (targetSum % 2 == 1) return false;
        targetSum /= 2;

        vector<vector<int>> pack(nums.size(), vector<int>(targetSum + 1, 0));
        for (int i = 0; i <= targetSum; i++) {
            if (nums[0] > i) continue;
            pack[0][i] = nums[0];
        }
        for (int i = 1; i < nums.size(); i++) {
            for (int s = 1; s <= targetSum; s++) {
                if (s < nums[i]) {
                    pack[i][s] = pack[i - 1][s];
                } else {
                    pack[i][s] = max(pack[i - 1][s], pack[i - 1][s - nums[i]] + nums[i]);
                }
            }
        }
        if (pack.back().back() != targetSum) return false;
        return true;
    }
};

int main(int argc, char* argv[]) {
    Solution solution;
    vector<vector<int>> input{{1,5,11,5}, {1,2,3,5}};
    for (int i = 0; i < input.size(); i++) {
        cout << solution.canPartition(input[i]) << "\n";
    }   
}