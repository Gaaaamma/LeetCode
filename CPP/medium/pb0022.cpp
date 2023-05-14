#include <iostream>
#include <vector>
#include <stack>
#include <numeric>
#include <queue>
using namespace std;

/*
#22 Generate Parentheses
Attempt 1: 
Use backtracking to solve

Q: Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
*/

class Solution {
public:
    string combination;
    vector<string> result;
    vector<string> generateParenthesis(int n) {
        if (n == 1) return vector<string>{"()"};
        combination.clear();
        result.clear();
        combination.reserve(n * 2);
        result.reserve(70);
        backtracking(n, n, 0, 0);
        return result;
    }
    void backtracking(int left, int right, int leftUsed, int rightUsed) {
        if (leftUsed < rightUsed) return;
        if (left == 0 && right == 0 && !combination.empty()) {
            result.push_back(combination);
            return;
        }
        if (left > 0) {
            combination += "(";
            backtracking(left - 1, right, leftUsed + 1, rightUsed);
            combination.pop_back();
        }
        if (right > 0) {
            combination += ")";
            backtracking(left, right - 1, leftUsed, rightUsed + 1);
            combination.pop_back();
        }
        
    }
};
void show(vector<string> input) {
    for (int i = 0; i < input.size(); i++) {
        cout << input[i] << " ";
    }
    cout << "\n";
}
int main(int argc, char* argv[]) {
    Solution solution;
    vector<int> input{1,2,3,4};
    for (int i = 0; i < input.size(); i++) {
        show(solution.generateParenthesis(input[i]));
    }
}