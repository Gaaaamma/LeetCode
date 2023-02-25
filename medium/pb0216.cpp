#include <iostream>
#include <vector>
using namespace std;

/*
#216 Combination Sum III
Attempt 1: 
Use backtracking to solve

Complexity: O(N) 

Q: Find all valid combinations of k numbers that sum up to n such that the following conditions are true:
   - Only numbers 1 through 9 are used.
   - Each number is used at most once.

   Return a list of all possible valid combinations. 
   The list must not contain the same combination twice, 
   and the combinations may be returned in any order.
*/     
class Solution {
public:
    vector<int> combination;
    vector<vector<int>> result;
    int target;
    vector<vector<int>> combinationSum3(int k, int n) {
        combination.clear();
        result.clear();
        target = n;
        int sum = 0;
        backtracking(k, 1, sum);
        return result;
    }
    void backtracking(int k, int startNum, int& sum) {
        if (k == 0) {
            if (sum == target) 
                result.push_back(combination);
            return;
        }
        for (int i = startNum; i <= 9 - k + 1; i++) {
            combination.push_back(i);
            sum += i;
            if (sum <= target)
                backtracking(k - 1, i + 1, sum);
            sum -= i;
            combination.pop_back();
        }
    }
};

void output(vector<vector<int>> result) {
    if (result.size() == 0) {
        cout << "[]\n";
        return;
    }
    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << "[";
        for (int j = 0; j < result[i].size() - 1; j++) {
            cout << result[i][j] << ", ";
        }
        if (i != result.size() - 1) {
            cout << result[i].back() << "], ";
        } else {
            cout << result[i].back() << "]]\n";
        }
    }
}

int main(int argc, char* argv[]) {
    Solution solution;
    vector<pair<int, int>> input{{3, 10}, {2, 10}, {3, 20}, {4, 20}, {4, 15}};
    for (int i = 0; i < input.size(); i++) {
        output(solution.combinationSum3(input[i].first, input[i].second));
    }
}