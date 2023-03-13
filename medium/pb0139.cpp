#include <iostream>
#include <vector>
#include <stack>
#include <numeric>
using namespace std;

/*
#139 Word Break
Attempt 1: 
Use DP to solve

Q: Given a string s and a dictionary of strings wordDict, 
   return true if s can be segmented into a space-separated sequence of one or more dictionary words.
   Note that the same word in the dictionary may be reused multiple times in the segmentation.

*/     
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> canBreak(s.size() + 1, false);
        canBreak[0] = true;
        
        for (int i = 0; i <= s.size(); i++) {
            for (int j = 0; j < wordDict.size(); j++) {
                if (i >= wordDict[j].size() && canBreak[i - wordDict[j].size()] == true 
                    && s.substr(i - wordDict[j].size(), wordDict[j].size()) == wordDict[j]) {
                    canBreak[i] = true;
                }
            }
            // show(canBreak);
        }
        return canBreak.back();
    }
    void show(vector<bool>& input) {
        for (int i = 0; i < input.size(); i++) {
            cout << input[i] << " ";
        }
        cout << "\n";
    }
};

int main(int argc, char* argv[]) {
    Solution solution;
    vector<pair<string, vector<string>>> input{{"leetcode", {"leet", "code"}}, {"applepenapple", {"apple", "pen"}}, {"catsandog", {"cats", "dog", "sand", "and", "cat"}}};
    for (int i = 0; i < input.size(); i++) {
        cout << solution.wordBreak(input[i].first, input[i].second) << "\n";
    }
}