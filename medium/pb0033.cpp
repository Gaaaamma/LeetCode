#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/*
#33 Search in Rotated Sorted Array
Attempt 1: 
Binary Search

Q: There is an integer array nums sorted in ascending order (with distinct values).

   Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k 
   (1 <= k < nums.length) such that the resulting array is 
   [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). 
   For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
   
   Given the array nums after the possible rotation and an integer target, 
   return the index of target if it is in nums, or -1 if it is not in nums.
   
   You must write an algorithm with O(log n) runtime complexity.
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 1) {
            if (nums[0] == target) return 0;
            return -1;
        }

        int left = 0;
        int right = nums.size();

        while (left < right) {
            int middle = left + (right - left) / 2;
            if (nums[middle] == target) return middle;
            else if (nums[middle] < target) {
                if (nums[right - 1] >= target || nums[left] < nums[middle]) left = middle + 1;
                else right = middle;
            } else if (nums[middle] > target) {
                if (nums[left] <= target || nums[right - 1] > nums[middle]) right = middle;
                else left = middle + 1;
            }
        }
        return -1;

    }
};
int main(int argc, char* argv[]) {
    Solution solution;
    vector<pair<vector<int>, int>> input{{{7,8,1,2,3,4,5,6}, 2}, {{7,8,1,2,3,4,5,6}, 4}, {{7,8,1,2,3,4,5,6}, 8}};
    for (int i = 0; i < input.size(); i++) {
        cout << solution.search(input[i].first, input[i].second) << "\n";
    }
    
}