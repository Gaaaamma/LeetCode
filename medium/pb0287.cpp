#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
using namespace std;

/*
#287 Find the Duplicate Number
Attempt 1: 
Linked List Cycle

Q: Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
   There is only one repeated number in nums, return this repeated number.
   You must solve the problem without modifying the array nums and uses only constant extra space.
*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        fast = nums[fast];

        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
            fast = nums[fast];
        }
        int start = 0;
        while (start != slow) {
            start = nums[start];
            slow = nums[slow];
        }
        return start;
    }
};
int main(int argc, char* argv[]) {
    Solution solution;
    vector<vector<int>> input{{1,2,3,4,3}, {5,1,2,3,4,5}, {4,5,4,3,2,4}};
    for (int i = 0; i < input.size(); i++) {
        cout << solution.findDuplicate(input[i]) << "\n";
    }
}