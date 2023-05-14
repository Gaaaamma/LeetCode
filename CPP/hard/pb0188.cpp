#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

/*
#188 Best Time to Buy and Sell Stocks IV
Attempt 1: Use DP to solve

Q: You are given an array prices where prices[i] is the price of a given stock on the ith day.
   Find the maximum profit you can achieve. You may complete at most two transactions.
   Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
*/
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        // [0] holdOne, [1] sellOne, [2] holeTwo, [3] sellTwo, ...
        vector<vector<int>> maxProfit(prices.size(), vector<int>(k * 2, 0));
        for (int i = 0; i < k * 2; i += 2) {
            maxProfit[0][i] = -prices[0];
        }
        // show(maxProfit);

        for (int i = 1; i < prices.size(); i++) {
            for (int j = 0; j < k * 2; j++) {
                if (j == 0) {
                    maxProfit[i][j] = max(maxProfit[i - 1][j], -prices[i]);
                } else if (j % 2 == 0) {
                    // hold
                    maxProfit[i][j] = max(maxProfit[i - 1][j], maxProfit[i - 1][j - 1] - prices[i]);
                } else if (j % 2 == 1) {
                    // sell
                    maxProfit[i][j] = max(maxProfit[i - 1][j], maxProfit[i - 1][j - 1] + prices[i]);
                }
            }
            // show(maxProfit);
        }
        return *max_element(maxProfit.back().begin(), maxProfit.back().end());
    }
    void show(vector<vector<int>>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums[i].size(); j++) {
                cout << nums[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
};

int main(int argc, char* argv[]) {
    Solution solution;
    vector<pair<int, vector<int>>> input{{2, {2,4,1}}, {7, {3,2,6,5,0,3}}};
    for (int i = 0; i < input.size(); i++) {
        cout << solution.maxProfit(input[i].first, input[i].second) << "\n";
    }
}