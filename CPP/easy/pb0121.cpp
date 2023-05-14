#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
#746 Best Time to Buy and Sell Stock
Attempt 1: 
use DP to solve

Q: You are given an array prices where prices[i] is the price of a given stock on the ith day.

   You want to maximize your profit by choosing a single day to buy 
   one stock and choosing a different day in the future to sell that stock.
   
   Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
*/     

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> profit(prices.size(), vector<int>(2,0));
        profit[0][0] = 0;
        profit[0][1] = -1 * prices[0];
        for (int i = 1; i < prices.size(); i++) {
            profit[i][0] = max(profit[i - 1][0], profit[i - 1][1] + prices[i]);
            profit[i][1] = max(profit[i - 1][1], -prices[i]);
            // show(profit);
        }
        return max(profit.back()[0], profit.back()[1]);
    }
    void show(vector<vector<int>>& input) {
        for (int i = 0; i < input.size(); i++) {
            cout << input[i][0] << " ";
        }
        cout << "\n";
        for (int i = 0; i < input.size(); i++) {
            cout << input[i][1] << " ";
        }
        cout << "\n\n";
    }
};

int main(int argc, char* argv[]) {
    Solution solution;
    vector<vector<int>> input{{10,15,20,3,11}, {1,39,1,1,1,100,1,1,100,1}, {1,20}, {20,1}};
    for (int i = 0; i < input.size(); i++) {
        cout << solution.maxProfit(input[i]) << "\n";
    }
}