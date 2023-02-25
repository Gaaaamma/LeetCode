#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
#17 Letter Combinations of a Phone Number
Attempt 1: 
Use backtracking to solve

Complexity: O(-) 

Q: Given a string containing digits from 2-9 inclusive, 
   return all possible letter combinations that the number could represent. 
   Return the answer in any order.
   A mapping of digits to letters (just like on the telephone buttons) is given below. 
   Note that 1 does not map to any letters.
*/     
class Solution {
public:
    vector<string> result;
    string combination;
    unordered_map<char, string> map;
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return vector<string>{};
        result.clear();
        combination.clear();
        map['2'] = "abc";
        map['3'] = "def";
        map['4'] = "ghi";
        map['5'] = "jkl";
        map['6'] = "mno";
        map['7'] = "pqrs";
        map['8'] = "tuv";
        map['9'] = "wxyz";
        backtracking(digits, 0);
        return result;
    }
    void backtracking(string digits, int index) {
        if (index == digits.size()) {
            result.push_back(combination);
            return;
        }
        string pattern = map[digits[index]];
        for (int i = 0; i < pattern.size(); i++) {
            combination += string(1, pattern[i]);
            backtracking(digits, index + 1);
            combination.pop_back();
        }
    }
};
void output2D(vector<vector<int>> result) {
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
void output(vector<string> result) {
    if (result.empty()) {
        cout << "[]\n";
        return;
    }
    cout << "[";
    for (int i = 0; i < result.size() - 1; i++) {
        cout << result[i] << ", ";
    }
    cout << result.back() << "]\n";
}
int main(int argc, char* argv[]) {
    Solution solution;
    vector<string> input{"23", "53", "", "979"};
    for (int i = 0; i < input.size(); i++) {
        output(solution.letterCombinations(input[i]));
    }
}