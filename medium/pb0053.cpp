#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
#53 Maximum Subarray
Attempt 1: 
Use greedy to solve

Complexity: O(N) 

Q: Given an integer array nums, find the subarray
   with the largest sum, and return its sum.
*/     
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = -10000;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum > max) max = sum;
            if (sum <= 0) {
                sum = 0;
                continue;
            }
        }
        return max;
    }
};


int main(int argc, char* argv[]) {
    Solution solution;
    vector<vector<int>> input{{-1,-3,2,6,-4,2,3,-7,1}, {-2,1,-3,4,-1,2,1,-5,4}, {5,4,-1,7,8}, {1}, {-4,-5,-7,-2,-3}};
    for (int i = 0; i < input.size(); i++) {
        cout << solution.maxSubArray(input[i]) << "\n";
    }   
}