#include <iostream>
#include <vector>
#include <stack>
#include <numeric>
using namespace std;

/*
#322 Coin Change
Attempt 1: 
Use DP to solve

Complexity: O(N^2) 

Q: You are given an integer array coins representing coins of different denominations 
   and an integer amount representing a total amount of money.

   Return the fewest number of coins that you need to make up that amount. 
   If that amount of money cannot be made up by any combination of the coins, return -1.
   
   You may assume that you have an infinite number of each kind of coin.

*/     
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> fewest(amount + 1, -1);
        fewest[0] = 0;
        for (int i = 0; i < coins.size(); i++) {
            for (int j = coins[i]; j <= amount; j++) {
                if (fewest[j] != -1 && fewest[j - coins[i]] != -1) {
                    fewest[j] = min(fewest[j], fewest[j - coins[i]] + 1);
                } else if (fewest[j] == -1 && fewest[j - coins[i]] != -1) {
                    fewest[j] = fewest[j - coins[i]] + 1;
                }
            }
            // show(fewest);
        }
        return fewest.back();
    }
    void show(vector<int>& input) {
        for (int i = 0; i < input.size(); i++) {
            cout << input[i] << " ";
        }
        cout << "\n";
    }
};

int main(int argc, char* argv[]) {
    Solution solution;
    vector<pair<vector<int>, int>> input{{{1,2,5}, 11}, {{2}, 3}, {{1}, 0}, {{2,5,10,1}, 27}};
    for (int i = 0; i < input.size(); i++) {
        cout << solution.coinChange(input[i].first, input[i].second) << "\n";
    }   
}