#include <iostream>
#include <vector>
#include <stack>
#include <numeric>
using namespace std;

/*
#198 House Robber II
Attempt 1: 
Use DP to solve

Q: You are a professional robber planning to rob houses along a street. 
   
   Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. 
   That means the first house is the neighbor of the last one. 
   Meanwhile, adjacent houses have a security system connected, 
   and it will automatically contact the police if two adjacent houses were broken into on the same night.

   Given an integer array nums representing the amount of money of each house, 
   return the maximum amount of money you can rob tonight without alerting the police.

*/     
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);
        
        int maxNum = 0;
        for (int t = 0; t <= 1; t++) {
            vector<int> input(nums.begin() + t, nums.end() - 1 + t);
            vector<int> maxRob(input.size(), 0);
            maxRob[0] = input[0];
            maxRob[1] = max(input[0], input[1]);
            for (int i = 2; i < input.size(); i++) {
                maxRob[i] = max(maxRob[i - 1], maxRob[i - 2] + input[i]);
            }
            maxNum = max(maxNum, maxRob.back());
        }
        return maxNum;
    }
};
int main(int argc, char* argv[]) {
    Solution solution;
    vector<vector<int>> input{{1,2,3,1}, {2,7,9,3,1}};
    for (int i = 0; i < input.size(); i++) {
        cout << solution.rob(input[i]) << "\n";
    }
}