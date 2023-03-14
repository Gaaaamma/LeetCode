#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

/*
#123 Best Time to Buy and Sell Stocks III
Attempt 1: Use DP to solve


Q: You are given an array prices where prices[i] is the price of a given stock on the ith day.
   Find the maximum profit you can achieve. You may complete at most two transactions.
   Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // [0]: NoOp, [1]: holdFirst, [2]: sellFirst, [3]: holdSecond, [4]: sellSecond
        vector<vector<int>> maxProfit(prices.size(), vector<int>(5,0));
        maxProfit[0][1] = -prices[0];
        maxProfit[0][3] = -prices[0];

        for (int i = 1; i < prices.size(); i++) {
            maxProfit[i][1] = max(maxProfit[i - 1][1], -prices[i]);
            maxProfit[i][2] = max(maxProfit[i - 1][2], maxProfit[i - 1][1] + prices[i]);
            maxProfit[i][3] = max(maxProfit[i - 1][3], maxProfit[i - 1][2] - prices[i]);
            maxProfit[i][4] = max(maxProfit[i - 1][4], maxProfit[i - 1][3] + prices[i]);
        }
        return *max_element(maxProfit.back().begin(), maxProfit.back().end());
    }
};

int main(int argc, char* argv[]) {
    Solution solution;
    vector<vector<int>> input{{3,3,5,0,0,3,1,4}, {1,2,3,4,5}, {7,6,4,3,1}};
    for (int i = 0; i < input.size(); i++) {
        cout << solution.maxProfit(input[i]) << "\n";
    }
}