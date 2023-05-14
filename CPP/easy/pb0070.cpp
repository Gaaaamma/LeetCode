#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
#70 Climbing Stairs
Attempt 1: 
use DP to solve

Complexity: O(N) 

Q: You are climbing a staircase. It takes n steps to reach the top.
   Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/     

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        vector<int> ways(n + 1, 0);
        ways[1] = 1;
        ways[2] = 2;
        for (int i = 3; i <= n; i++) {
            ways[i] = ways[i - 1] + ways[i - 2];
        }
        return ways[n];
    }
};

int main(int argc, char* argv[]) {
    Solution solution;
    vector<int> input{1,2,3,4,5,6,10,20,45};
    for (int i = 0; i < input.size(); i++) {
        cout << solution.climbStairs(input[i]) << "\n";
    }
}