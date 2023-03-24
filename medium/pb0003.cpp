#include <iostream>
#include <vector>
#include <stack>
#include <numeric>
#include <queue>
using namespace std;

/*
#3 Longest Substring Without Repeating Characters
Attempt 1: 
Slide Window

Q: Given a string s, find the length of the longest substring without repeating characters.
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;
        int longest = 0;
        int round = 0;
        int left = 0;
        int right = 0;
        vector<bool> used(256, false);
        for (right = 0; right < s.size(); right++) {
            if (used[s[right]] == true) {
                while (left < right) {
                    if (s[left] == s[right]) {
                        left++;
                        break;
                    }
                    used[s[left]] = false;
                    round--;
                    left++;
                }
            } else {
                used[s[right]] = true;
                round++;
                longest = max(longest, round);
            }
        }

        return longest;
    }
};
int main(int argc, char* argv[]) {
    Solution solution;
    vector<string> input{"abcakmn", "abcbmn", ".<>,}{143{", "00112234456", " a b s e"};
    for (int i = 0; i < input.size(); i++) {
        cout << solution.lengthOfLongestSubstring(input[i]) << "\n";
    }
}