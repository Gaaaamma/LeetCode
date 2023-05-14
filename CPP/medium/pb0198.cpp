#include <iostream>
#include <vector>
#include <stack>
#include <numeric>
using namespace std;

/*
#198 House Robber
Attempt 1: 
Use DP to solve

Q: You are a professional robber planning to rob houses along a street. 
   Each house has a certain amount of money stashed, 
   the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected 
   and it will automatically contact the police if two adjacent houses were broken into on the same night.

   Given an integer array nums representing the amount of money of each house, 
   return the maximum amount of money you can rob tonight without alerting the police.

*/     
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        vector<int> maxRob(nums.size(), 0);
        maxRob[0] = nums[0];
        maxRob[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++) {
            maxRob[i] = max(maxRob[i - 1], nums[i] + maxRob[i - 2]);
            // show(maxRob);
        }
        return maxRob.back();
    }
    void show(vector<int>& input) {
        for (int i = 0; i < input.size(); i++) {
            cout << input[i] << " ";
        }
        cout << "\n";
    }
};

int main(int argc, char* argv[]) {
    Solution solution;
    vector<vector<int>> input{{1,2,3,1}, {2,7,9,3,1}};
    for (int i = 0; i < input.size(); i++) {
        cout << solution.rob(input[i]) << "\n";
    }
}