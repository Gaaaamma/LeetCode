#include <iostream>
#include <vector>
#include <stack>
#include <numeric>
#include <queue>
using namespace std;

/*
#1143 Longest Common Subsequence 
Attempt 1: 
Use DP to solve

Q: Given two strings text1 and text2, return the length of their longest common subsequence. 
   If there is no common subsequence, return 0.

   A subsequence of a string is a new string generated from the original string 
   with some characters (can be none) deleted without changing the relative order of the remaining characters.
   
   For example, "ace" is a subsequence of "abcde".
   A common subsequence of two strings is a subsequence that is common to both strings.
*/
class Solution {
public:
    void show(vector<int>& input) {
        for (int i = 0; i < input.size(); i++) {
            cout << input[i] << " ";
        }
        cout << "\n";
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> len(text1.size(), vector<int>(text2.size(), 0));
        if (text1[0] == text2[0]) len[0][0] = 1;
        for (int i = 1; i < text1.size(); i++) {
            if (text1[i] == text2[0]) {
                len[i][0] = 1;
            } else {
                len[i][0] = len[i - 1][0];
            }
        }
        for (int j = 1; j < text2.size(); j++) {
            if (text2[j] == text1[0]) {
                len[0][j] = 1;
            } else {
                len[0][j] = len[0][j - 1];
            }
        }   

        for (int i = 1; i < len.size(); i++) {
            for (int j = 1; j < len[i].size(); j++) {
                if (text1[i] == text2[j]) len[i][j] = len[i - 1][j - 1] + 1;
                else len[i][j] = max(len[i - 1][j], len[i][j - 1]);
            }
        }
        
        return len.back().back();
    }
};

int main(int argc, char* argv[]) {
    Solution solution;
    vector<pair<string, string>> input{{"abcde", "ace"}, {"abc", "abc"}, {"abc", "def"}, {"acead", "abcde"}};
    for (int i = 0; i < input.size(); i++) {
        cout << solution.longestCommonSubsequence(input[i].first, input[i].second) << "\n";
    }
}