#include <iostream>
#include <vector>
#include <stack>
#include <numeric>
using namespace std;

/*
#494 Target Sum
Attempt 1: 
Use DP to solve

Complexity: O(N^2) 

Q: You are given an integer array nums and an integer target.

   You want to build an expression out of nums by adding one of the symbols '+' and '-' before 
   each integer in nums and then concatenate all the integers.
   
   For example, if nums = [2, 1], you can add a '+' before 2 and a '-' 
   before 1 and concatenate them to build the expression "+2-1".
   Return the number of different expressions that you can build, which evaluates to target.
*/     
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // x + y = sum
        // x - y = target
        // x = (sum + target) / 2
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > sum || (sum + target) % 2 == 1) return 0;
        
        int backSize = (sum + target) / 2;
        vector<int> count(backSize + 1 ,0);
        count[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = backSize; j >= nums[i]; j--) {
                count[j] += count[j - nums[i]];
            }
            // show(count);
        }
        return count.back();
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
    vector<pair<vector<int>, int>> input{{{1,1,1,1,1}, 3}, {{1}, 1}};
    for (int i = 0; i < input.size(); i++) {
        cout << solution.findTargetSumWays(input[i].first, input[i].second) << "\n";
    }   
}