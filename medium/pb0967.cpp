#include <iostream>
#include <vector>
#include <stack>
#include <numeric>
#include <queue>
using namespace std;

/*
#967 Numbers With Same Consecutive Differences
Attempt 1: 
Use backtracking to solve

Q: Given two integers n and k, return an array of all the integers of 
   length n where the difference between every two consecutive digits is k. You may return the answer in any order.
   Note that the integers should not have leading zeros. Integers as 02 and 043 are not allowed.
*/
class Solution {
public:
    string combination;
    vector<int> result;
    vector<int> numsSameConsecDiff(int n, int k) {
        combination.clear();
        result.clear();
        combination.reserve(n);
        for (int i = 1; i <= 9; i++) {
            combination += to_string(i);
            backtracking(n, k, i, 1);
            combination.pop_back();
        }
        return result;
    }

    void backtracking(int n, int k, int target, int degree) {
        if (degree == n) {
            result.push_back(stoi(combination));
            return;
        }
        int up = target + k;
        int down = target - k;
        if (up < 10) {
            combination += to_string(up);
            backtracking(n, k, up, degree + 1);
            combination.pop_back();
        }
        if (down >= 0 && down != up) {
            combination += to_string(down);
            backtracking(n, k, down, degree + 1);
            combination.pop_back();
        }
    }
};
void show(vector<int> input) {
    for (int i = 0; i < input.size(); i++) {
        cout << input[i] << " ";
    }
    cout << "\n";
}
int main(int argc, char* argv[]) {
    Solution solution;
    vector<pair<int, int>> input{{3, 7}, {2, 1}, {3, 0}, {5,0}, {5,6}};
    for (int i = 0; i < input.size(); i++) {
        show(solution.numsSameConsecDiff(input[i].first, input[i].second));
    }
}