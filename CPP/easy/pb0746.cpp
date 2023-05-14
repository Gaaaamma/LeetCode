#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
#746 Min Cost Climbing Stairs
Attempt 1: 
use DP to solve

Complexity: O(N) 

Q: You are given an integer array cost where cost[i] is the cost of ith step on a staircase. 
   Once you pay the cost, you can either climb one or two steps.

   You can either start from the step with index 0, or the step with index 1.
   Return the minimum cost to reach the top of the floor.
*/     

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> minCost(cost.size() + 1, 0);
        minCost[0] = 0;
        minCost[1] = 0;
        for (int i = 2; i < minCost.size(); i++) {
            minCost[i] = min(minCost[i - 1] + cost[i - 1], minCost[i - 2] + cost[i - 2]);
        }
        return minCost.back();
    }
};

int main(int argc, char* argv[]) {
    Solution solution;
    vector<vector<int>> input{{10,15,20}, {1,100,1,1,1,100,1,1,100,1}, {1,20}, {20,1}};
    for (int i = 0; i < input.size(); i++) {
        cout << solution.minCostClimbingStairs(input[i]) << "\n";
    }
}