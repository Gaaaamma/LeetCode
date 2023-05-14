#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

/*
#1005 Maximize Sum Of Array After K Negations
Attempt 1: 
Sort the array and use greedy to solve

Complexity: O(NlogN) 

Q: Given an integer array nums and an integer k, modify the array in the following way:

   choose an index i and replace nums[i] with -nums[i].
   
   You should apply this process exactly k times. 
   You may choose the same index i multiple times.

   Return the largest possible sum of the array after modifying it in this way.
*/     

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (k <= 0) break;
            if (nums[i] < 0) {
                nums[i] *= -1;
                k--;
            } else if (nums[i] == 0) {
                k = 0;
                break;
            } else {
                break;
            }
        }
    
        int sum = 0;
        if (k % 2 != 0) {
            sort(nums.begin(), nums.end());
            nums.front() *= -1;
        }
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        return sum;
    }
};
int main(int argc, char* argv[]) {
    Solution solution;
    vector<pair<vector<int>, int>> input{{{-4,-6,-1,4,2,7}, 4}, {{5,1,6,2,7}, 3}, {{-4,-2,0,7,3,2}, 10}};
    for (int i = 0; i < input.size(); i++) {
        cout << solution.largestSumAfterKNegations(input[i].first, input[i].second) << "\n"; 
    }
}