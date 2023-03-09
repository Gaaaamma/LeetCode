#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int getMaxProfit(vector<int> weight, vector<int> value, int size) {
        // profit[i][j] stands for
        // i: 0 - i items can be used
        // j: backpack size
        // profit[i][j]: use 0 - i items to make max profit of backpack size j
        vector<vector<int>> profit(weight.size(), vector<int>(size + 1, 0));

        for (int s = 0; s <= size; s++) {
            if (weight[0] > s) continue;
            profit[0][s] = value[0];
        }
        for (int i = 1; i < weight.size(); i++) {
            for (int s = 0; s <= size; s++) {
                if (weight[i] > s) {
                    profit[i][s] = profit[i - 1][s];
                } else {
                    profit[i][s] = max(profit[i - 1][s], profit[i - 1][s - weight[i]] + value[i]);
                }
            }
        }
        return profit.back().back();
    }
};

int main(int argc, char* argv[]) {
    Solution solution;
    vector<pair<vector<int>, vector<int>>> input{{{12,2,1,1,4}, {4,2,2,1,10}}};
    int size = 15;
    for (int i = 0; i < input.size(); i++) {
        cout << solution.getMaxProfit(input[i].first, input[i].second, size) << "\n";
    }
}