#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
#55 Jump Game
Attempt 1: 
Use greedy to solve

Complexity: O(N) 

Q: You are given an integer array nums. 
   You are initially positioned at the array's first index, and each 
   element in the array represents your maximum jump length at that position.

   Return true if you can reach the last index, or false otherwise.
*/     
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int targetIndex = nums.size() - 1;
        for (int i = targetIndex - 1; i >= 0; i--) {
            if (i + nums[i] >= targetIndex)
                targetIndex = i;
        }
        if (targetIndex == 0) return true;
        return false;
    }
};


int main(int argc, char* argv[]) {
    Solution solution;
    vector<vector<int>> input{{2,3,1,1,4}, {3,2,1,0,4}, {2,3,1,0,10}, {6,0,2,3,1,0,10}, {1,1,1,0,4}, {2,0,4,5,0,0,0,1,1,4}, {0}};
    for (int i = 0; i < input.size(); i++) {
        cout << solution.canJump(input[i]) << "\n";
    }   
}