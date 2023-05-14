#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

/*
#516 Longest Palindromic Subsequence
Attempt 1: 
DP

Q: Given a string s, find the longest palindromic subsequence's length in s.
   A subsequence is a sequence that can be derived from another sequence by 
   deleting some or no elements without changing the order of the remaining elements.
*/
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> length(s.size(), vector<int>(s.size(), 1));
        for (int j = 1; j < length.front().size(); j++) {
            for (int i = j - 1; i >= 0; i--) {
                if (s[i] == s[j]) {
                    if (i + 1 > j - 1) length[i][j] = 2;
                    else length[i][j] = length[i + 1][j - 1] + 2;
                }
                else length[i][j] = max(length[i][j - 1], length[i + 1][j]);
            }
        }
        return length.front().back();
    }
};
template<class T>
void show1D(const vector<T>& input) {
    if (input.empty()) {
        cout << "[]\n";
        return;
    }
    cout << "[";
    for (int i = 0; i < input.size() - 1; i++) {
        cout << input[i] << ",";
    }
    cout << input.back() << "]\n";
}
template<class T>
void show2DGraph(const vector<vector<T>>& input) {
    for (int i = 0; i < input.size(); i++) {
        show1D(input[i]);
    }
}

int main(int argc, char* argv[]) {
    Solution solution;
    vector<string> input{"bbbab", "cbbd"};
    for (int i = 0; i < input.size(); i++) {
        cout << solution.longestPalindromeSubseq(input[i]) << "\n";
    }
}