#include <iostream>
#include <vector>
#include <stack>
#include <numeric>
#include <queue>
using namespace std;

/*
#31 Next Permutation
Attempt 1: 
Find rules to swap

Q: A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

   For example, for arr = [1,2,3], the following are all the permutations of 
   arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
   The next permutation of an array of integers is the next lexicographically greater permutation of its integer. 
   More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, 
   then the next permutation of that array is the permutation that follows it in the sorted container. 
   If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).
   
   For example, the next permutation of arr = [1,2,3] is [1,3,2].
   Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
   While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
   Given an array of integers nums, find the next permutation of nums.
   
   The replacement must be in place and use only constant extra memory.
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() == 1) return;
        int judge = INT_MIN;
        int swapIndex = -1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] >= judge) {
                judge = nums[i];
            } else {
                swapIndex = i;
                break;
            }
        }
        if (swapIndex == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        int targetIndex = swapIndex + 1;
        for (int i = swapIndex + 1; i < nums.size(); i++) {
            if (nums[i] > nums[swapIndex] && nums[i] <= nums[targetIndex]) {
                targetIndex = i;
            }
        }
        swap(nums[swapIndex], nums[targetIndex]);
        reverse(nums.begin() + swapIndex + 1, nums.end());
    }
};
void show(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " "; 
    }
    cout << "\n";
}
int main(int argc, char* argv[]) {
    Solution solution;
    vector<vector<int>> input{{1,2,3,4,5}, {5,4,3,2,1}, {1,1,2,2,3}, {3,2,1,2,1}, {1,1,5}, {3,5,4,2,1}};
    for (int i = 0; i < input.size(); i++) {
        solution.nextPermutation(input[i]);
        show(input[i]);
    }
}