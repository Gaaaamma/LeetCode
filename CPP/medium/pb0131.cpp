#include <iostream>
#include <vector>
using namespace std;

/*
#131 Palindrome Partitioning
Attempt 1: 
Use backtracking to solve

Complexity: O(-) 

Q: Given a string s, partition s such that every substring of 
   the partition is a palindrome. 
   Return all possible palindrome partitioning of s.
*/     
class Solution {
public:
    vector<vector<string>> result;
    vector<string> combination;
    vector<vector<string>> partition(string s) {
        result.clear();
        combination.clear();
        if (s.size() == 1) return vector<vector<string>>{{s}};
        backtracking(s, 0);
        return result;
    }
    void backtracking(string s, int index) {
        if (index == s.size()) {
            result.push_back(combination);
            return;
        }

        for (int i = 1; i <= s.size() - index; i++) {
            string word = s.substr(index, i);
            if (checkPalindrome(word)) {
                combination.push_back(word);
                backtracking(s, index + i);
                combination.pop_back();
            }
        }
    }
    bool checkPalindrome(string s) {
        if (s.size() == 1) return true;
        int left = 0;
        int right = s.size() - 1;
        while (left <= right) {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
};
void output2D(vector<vector<string>> result) {
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
    vector<string> input{"abc", "aab", "aaab", "abba"};
    for (int i = 0; i < input.size(); i++) {
        output2D(solution.partition(input[i]));
    }
}