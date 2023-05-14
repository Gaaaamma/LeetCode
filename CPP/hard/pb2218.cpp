#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

/*
#2218 Maximum Value of K Coins From Piles
Attempt 1:
prefixSum + DP(backpack)

Q: There are n piles of coins on a table. Each pile consists of a positive number of coins of assorted denominations.
   In one move, you can choose any coin on top of any pile, remove it, and add it to your wallet.
   
   Given a list piles, where piles[i] is a list of integers denoting 
   the composition of the ith pile from top to bottom, and a positive integer k, 
   return the maximum total value of coins you can have in your wallet if you choose exactly k coins optimally.
*/
class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        vector<vector<int>> prefix(piles.size(), vector<int>(2000, 0));
        for (int i = 0; i < piles.size(); i++) {
            int sum = 0;
            int resize = 0;
            for (int j = 0; j < piles[i].size(); j++) {
                sum += piles[i][j];
                prefix[i][j] = sum;
                resize++;
            }
            prefix[i].resize(resize);
        }

        vector<vector<int>> profit(piles.size(), vector<int>(k + 1, 0));
        // init
        for (int i = 1; i < profit[0].size(); i++) {
            if (i - 1 < prefix[0].size()) profit[0][i] = prefix[0][i - 1];
            else profit[0][i] = profit[0][i - 1];
        }

        // transfer
        for (int i = 1; i < profit.size(); i++) {
            for (int j = 1; j < profit[i].size(); j++) {
                for (int t = 1; t <= j; t++) {
                    if (t > prefix[i].size()) break;
                    profit[i][j] = max(profit[i][j], prefix[i][t - 1] + profit[i - 1][j - t]);
                }
                profit[i][j] = max(profit[i][j], profit[i - 1][j]);
            }
        }
        return profit.back().back();
    }
};

int main(int argc, char* argv[]) {
    Solution solution;
    vector<pair<vector<vector<int>>, int>> input{{{{1,100,3},{7,8,9}}, 2}, {{{100},{100},{100},{100},{100},{100},{1,1,1,1,1,1,700}}, 7}};
    for (int i = 0; i < input.size(); i++) {
        cout << solution.maxValueOfCoins(input[i].first, input[i].second) << "\n";
    }
}