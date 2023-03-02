#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
#122 Best Time to Buy and Sell Stock II
Attempt 1: 
Use greedy to solve

Complexity: O(N) 

Q: You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

   On each day, you may decide to buy and/or sell the stock. 
   You can only hold at most one share of the stock at any time. 
   However, you can buy it then immediately sell it on the same day.

   Find and return the maximum profit you can achieve.
*/     
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int holdPrice = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] - holdPrice > 0) {
                profit += prices[i] - holdPrice;
            } 
            holdPrice = prices[i];
        }
        return profit;
    }
};


int main(int argc, char* argv[]) {
    Solution solution;
    vector<vector<int>> input{{1,5,7,10}, {10,5,2,1,12}, {20,30,1,5,1,50}};
    for (int i = 0; i < input.size(); i++) {
        cout << solution.maxProfit(input[i]) << "\n";
    }   
}