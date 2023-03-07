#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
#714 Best Time to Buy and Sell Stock with Transaction Fee
Attempt 1: 
Use DP to solve

Complexity: O(N) 

Q: You are given an array prices where prices[i] is the price of a given stock on the ith day, 
   and an integer fee representing a transaction fee.

   Find the maximum profit you can achieve. 
   You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

   Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
*/     
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        // [0]: max money [1]: max money with stock
        dp[0][1] -= prices[0];
        for (int i = 1; i < prices.size(); i++) {
            dp[i][0] = max(dp[i - 1][0], prices[i] + dp[i - 1][1] - fee);
            dp[i][1] = max(dp[i - 1][1], dp[i][0] - prices[i]);
        }
        return max(dp.back()[0], dp.back()[1]);
    }
};


int main(int argc, char* argv[]) {
    Solution solution;
    vector<pair<vector<int>, int>> input{{{1,3,2,8,4,9}, 2}, {{1,3,7,5,10,3}, 3}};
    for (int i = 0; i < input.size(); i++) {
        cout << solution.maxProfit(input[i].first, input[i].second) << "\n";
    }   
}