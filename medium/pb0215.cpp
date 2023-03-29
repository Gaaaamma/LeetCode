#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
#215 Kth Largest Element in an Array
Attempt 1: 
quickSort partition

Q: Given an integer array nums and an integer k, return the kth largest element in the array.
   Note that it is the kth largest element in the sorted order, not the kth distinct element.
   You must solve it in O(n) time complexity.
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int index = 0;
        int left = 0;
        int right = nums.size() - 1;
        int target = nums.size() - k;
        while (true) {
            index = partition(nums, left, right);
            if (index == target) break;
            else if (index < target) left = index + 1;
            else if (index > target) right = index - 1;
        }
        return nums[index];
    }
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left];
        int l = left + 1;
        int r = right;
        while (l <= r) {
            while (l <= right && nums[l] <= pivot) {
                l++;
            }
            while (r >= left && nums[r] > pivot) {
                r--;
            }
            if (l < r) swap(nums[l], nums[r]);
        }
        swap(nums[left], nums[r]);
        return r;
    }
};

int main(int argc, char* argv[]) {
    Solution solution;
    vector<pair<vector<int>, int>> input{{{3,2,1,5,6,4}, 2}, {{3,2,3,1,2,4,5,5,6}, 4}, {{7,6,5,4,3,2,1}, 5}};
    for (int i = 0; i < input.size(); i++) {
        cout << solution.findKthLargest(input[i].first, input[i].second) << "\n";
    }
}