#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
#746 Best Time to Buy and Sell Stock
Attempt 1: 
use greedy to solve

Q: You are given an array prices where prices[i] is the price of a given stock on the ith day.

   You want to maximize your profit by choosing a single day to buy 
   one stock and choosing a different day in the future to sell that stock.
   
   Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
*/     

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int minPrice = INT_MAX;
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < minPrice) minPrice = prices[i];
            if (prices[i] - minPrice > maxProfit) maxProfit = prices[i] - minPrice;
        }
        return maxProfit;
    }
};

int main(int argc, char* argv[]) {
    Solution solution;
    vector<vector<int>> input{{10,15,20,3,11}, {1,39,1,1,1,100,1,1,100,1}, {1,20}, {20,1}};
    for (int i = 0; i < input.size(); i++) {
        cout << solution.maxProfit(input[i]) << "\n";
    }
}