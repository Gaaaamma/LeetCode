#include <iostream>
#include <vector>
#include <stack>
#include <numeric>
#include <queue>
using namespace std;

/*
#392 Is subsequence
Attempt 1: 
Use DP to solve

Q: Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

   A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) 
   of the characters without disturbing the relative positions of the remaining characters. 
   (i.e., "ace" is a subsequence of "abcde" while "aec" is not).
*/
class Solution {
public:
    void show(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            cout << nums[i] << " ";
        }
        cout << "\n";
    }
    bool isSubsequence(string s, string t) {
        if (s.empty()) return true;
        if (s.size() > t.size()) return false;
        vector<vector<int>> len(s.size(), vector<int>(t.size(), 0));
        if (s[0] == t[0]) len[0][0] = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == t[0]) len[i][0] = 1;
            else len[i][0] = len[i - 1][0];
        }
        for (int j = 1; j < t.size(); j++) {
            if (t[j] == s[0]) len[0][j] = 1;
            else len[0][j] = len[0][j - 1];
        }
        for (int i = 1; i < s.size(); i++) {
            for (int j = 1; j < t.size(); j++) {
                if (s[i] == t[j]) len[i][j] = len[i - 1][j - 1] + 1;
                else len[i][j] = max(len[i - 1][j], len[i][j - 1]);
            }
        }
        if (len.back().back() == s.size()) return true;
        return false;
    }
};
int main(int argc, char* argv[]) {
    Solution solution;
    vector<pair<string, string>> input{{"ace", "afetcte"}, {"abcde", "abcd"}, {"", "dfe"}, {"eqg", ""}, {"afet", "affeeg"}};
    for (int i = 0; i < input.size(); i++) {
        cout << solution.isSubsequence(input[i].first, input[i].second) << "\n";
    }
}