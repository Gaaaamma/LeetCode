#include <iostream>
#include <vector>
#include <stack>
#include <numeric>
#include <queue>
using namespace std;

/*
#309 Best Time to Sell and Buy Stock with Cooldown
Attempt 1: 
Use DP to solve

Q: You are given an array prices where prices[i] is the price of a given stock on the ith day.

   Find the maximum profit you can achieve. You may complete as many transactions as you like 
   (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:
   
   After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
   Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        // [0]=HoldStock, [1]=NoHold_keepSold, [2]=NoHold_SellToday, [3]=Cooldown
        vector<vector<int>> money(prices.size(), vector<int>(4,0));
        money[0][0] = -prices[0];
        money[0][1] = 0;
        money[0][2] = 0;
        money[0][3] = 0;
        // show(money[0]);

        for (int i = 1; i < prices.size(); i++) {
            money[i][0] = max(money[i - 1][0], max(money[i - 1][1] - prices[i], money[i - 1][3] - prices[i]));
            money[i][1] = max(money[i - 1][1], money[i - 1][3]);
            money[i][2] = money[i - 1][0] + prices[i];
            money[i][3] = money[i - 1][2];
            // show(money[i]);
        }
        return *max_element(money.back().begin(), money.back().end());
    }
    void show(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            cout << nums[i] << " ";
        }
        cout << "\n";
    }
};

int main(int argc, char* argv[]) {
    Solution solution;
    vector<vector<int>> input{{2,2,3,4}, {2,7,9,3,1}};
    for (int i = 0; i < input.size(); i++) {
        cout << solution.maxProfit(input[i]) << "\n";
    }
}