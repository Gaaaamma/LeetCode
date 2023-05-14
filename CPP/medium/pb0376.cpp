#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
#376 Wiggle Subsequence
Attempt 1: 
Use greedy to solve

Complexity: O(N) 

Q: A wiggle sequence is a sequence where the differences between successive numbers 
   strictly alternate between positive and negative. 
   The first difference (if one exists) may be either positive or negative. 
   A sequence with one element and a sequence with two non-equal elements are trivially wiggle sequences.

   For example, [1, 7, 4, 9, 2, 5] is a wiggle sequence 
   because the differences (6, -3, 5, -7, 3) alternate between positive and negative.

   In contrast, [1, 4, 7, 2, 5] and [1, 7, 4, 5, 5] are not wiggle sequences. 
   The first is not because its first two differences are positive, and the second is not because its last difference is zero.

   A subsequence is obtained by deleting some elements (possibly zero) 
   from the original sequence, leaving the remaining elements in their original order.

   Given an integer array nums, return the length of the longest wiggle subsequence of nums.
*/     
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        stack<int> compare;
        compare.push(nums[0]);

        int judge = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > compare.top()) {
                if (judge <= 0) {
                    compare.push(nums[i]);
                    judge = 1;
                } else {
                    compare.pop();
                    compare.push(nums[i]);
                }

            } else if (nums[i] < compare.top()) {
                if (judge >= 0) {
                    compare.push(nums[i]);
                    judge = -1;
                } else {
                    compare.pop();
                    compare.push(nums[i]);
                }
            }
        }
        return compare.size();
    }
};


int main(int argc, char* argv[]) {
    Solution solution;
    vector<vector<int>> input{{1,2,3,4,5}, {1,3,2,5,5,6,5}, {5,5,7,10,9,10,9}};
    for (int i = 0; i < input.size(); i++) {
        cout << solution.wiggleMaxLength(input[i]) << "\n";
    }   
}