#include <iostream>
#include <vector>
#include <stack>
#include <numeric>
#include <queue>
using namespace std;

/*
#300 Longest Increasing Subsequence
Attempt 1: 
Use DP to solve

Q: Given an integer array nums, return the length of the longest strictly increasing subsequence.
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 1) return 1;
        vector<int> longest(nums.size(), 1);
        // show(longest);
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    longest[i] = max(longest[i], longest[j] + 1);
                    // show(longest);
                }
            }
        }
        return *max_element(longest.begin(), longest.end());
    }
    void show(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            cout << nums[i] << " ";
        }
        cout << "\n";
    }
};

int main(int argc, char* argv[]) {
    Solution solution;
    vector<vector<int>> input{{2,2,3,4}, {2,7,9,3,1}, {5,4,3,2,1}, {1,2,3,4,5}, {1}, {1,1,1,1,1}};
    for (int i = 0; i < input.size(); i++) {
        cout << solution.lengthOfLIS(input[i]) << "\n";
    }
}