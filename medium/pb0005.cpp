#include <iostream>
#include <vector>
#include <stack>
#include <numeric>
#include <queue>
using namespace std;

/*
#5 Longest Palindromic Substring
Attempt 1: 
DP

Q: Given a string s, return the longest palindromic substring in s.
*/
class Solution {
public:
    void show(vector<bool>& input) {
        for (int i = 0; i < input.size(); i++) {
            cout << input[i] << " ";
        }
        cout << "\n";
    }
    string longestPalindrome(string s) {
        string result = "";
        vector<vector<bool>> palin(s.size(), vector<bool>(s.size(), false));
        for (int j = 0; j < s.size(); j++) {
            for (int i = j; i >= 0; i--) {
                if (i == j) {
                    palin[i][j] = true;
                    if (j - i + 1 > result.size()) result = s.substr(i, j - i + 1);
                } else if (i == j - 1 && s[i] == s[j]) {
                    palin[i][j] = true;
                    if (j - i + 1 > result.size()) result = s.substr(i, j - i + 1);
                } else if (i == j - 2 && s[i] == s[j]) {
                    palin[i][j] = true;
                    if (j - i + 1 > result.size()) result = s.substr(i, j - i + 1);
                } else if (i < j - 2 && s[i] == s[j] && palin[i + 1][j - 1]) {
                    palin[i][j] = true;
                    if (j - i + 1 > result.size()) result = s.substr(i, j - i + 1);
                }
            }
        }
        return result;
    }
};

int main(int argc, char* argv[]) {
    Solution solution;
    vector<string> input{"dvda", "abc", "ababab", "abcbaabc", "aaaaaa"};
    for (int i = 0; i < input.size(); i++) {
        cout << solution.longestPalindrome(input[i]) << "\n";
    }
}