#include <iostream>
#include <vector>
#include <stack>
#include <numeric>
using namespace std;

/*
#1049 Last Stone Weight II
Attempt 1: 
Use DP to solve

Complexity: O(N^2) 

Q: You are given an array of integers stones where stones[i] is the weight of the ith stone.

   We are playing a game with the stones. On each turn, 
   we choose any two stones and smash them together. 
   Suppose the stones have weights x and y with x <= y. The result of this smash is:
    - If x == y, both stones are destroyed, and
    - If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
    
   At the end of the game, there is at most one stone left.
   Return the smallest possible weight of the left stone. If there are no stones left, return 0.
*/     
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int weightSum = accumulate(stones.begin(), stones.end(), 0);
        int backSize = weightSum / 2;
        vector<vector<int>> dp(stones.size(), vector<int>(backSize + 1, 0));
        for (int i = backSize; i >= stones[0]; i--) {
            dp[0][i] = stones[0];
        }
        for (int i = 1; i < stones.size(); i++) {
            for (int s = 1; s <= backSize; s++) {
                if (s < stones[i]) {
                    dp[i][s] = dp[i - 1][s];
                } else {
                    dp[i][s] = max(dp[i - 1][s], dp[i - 1][s - stones[i]] + stones[i]);
                }
            }
        }
        int maxSum = max(dp.back().back(), weightSum - dp.back().back());
        return maxSum - dp.back().back();
    }
};

int main(int argc, char* argv[]) {
    Solution solution;
    vector<vector<int>> input{{1,5,11,5}, {1,2,3,5}, {2,7,4,1,8,1}, {31,26,33,21,40}, {23,54,12,66,24,67,84,23,10,25}};
    for (int i = 0; i < input.size(); i++) {
        cout << solution.lastStoneWeightII(input[i]) << "\n";
    }   
}