#include <iostream>
#include <vector>
#include <stack>
#include <numeric>
using namespace std;

/*
#518 Coin Change II
Attempt 1: 
Use DP to solve

Complexity: O(N^2) 

Q: You are given an integer array coins representing coins of different denominations 
   and an integer amount representing a total amount of money.

   Return the number of combinations that make up that amount. 
   If that amount of money cannot be made up by any combination of the coins, return 0.
   
   You may assume that you have an infinite number of each kind of coin.
   The answer is guaranteed to fit into a signed 32-bit integer.

*/     
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> count(amount + 1, 0);
        count[0] = 1;
        for (int i = 0; i < coins.size(); i++) {
            for (int s = 0; s <= amount; s++) {
                if (s >= coins[i]) {
                    count[s] += count[s - coins[i]];
                }
            }
        }
        return count.back();
    }
    void show(vector<int>& count) {
        for (int i = 0; i < count.size(); i++) {
            cout << count[i] << " ";
        }
        cout << "\n";
    }
};

int main(int argc, char* argv[]) {
    Solution solution;
    vector<pair<int, vector<int>>> input{{5, {1,2,5}}, {3, {2}}, {10, {10}}};
    for (int i = 0; i < input.size(); i++) {
        cout << solution.change(input[i].first, input[i].second) << "\n";
    }   
}