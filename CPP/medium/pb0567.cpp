#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
using namespace std;

/*
#567 Permutation in String
Attempt 1: 
Slide Window

Q: Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
   In other words, return true if one of s1's permutations is the substring of s2.
*/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> counts(26, 0);
        unordered_set<char> occur;
        for (int i = 0; i < s1.size(); i++) {
            counts[s1[i] - 'a']++;
            occur.insert(s1[i]);
        }
        
        int left = 0;
        int right = 0;
        int round = 0;
        for (right = 0; right < s2.size(); right++) {
            if (occur.count(s2[right]) == false) {
                while (left < right) {
                    counts[s2[left] - 'a']++;
                    left++;
                    round--;
                }
                left++;
            } else {
                if (counts[s2[right] - 'a'] > 0) {
                    counts[s2[right] - 'a']--;
                    round++;
                } else {
                    while (left < right) {
                        if (s2[left] == s2[right]) {
                            left++;
                            break;
                        }
                        counts[s2[left] - 'a']++;
                        round--;
                        left++;
                    }
                }
            }
            if (round == s1.size()) return true;
        }
        return false;
    }
};

int main(int argc, char* argv[]) {
    Solution solution;
    vector<pair<string, string>> input{{"ab", "eidbaooo"}, {"ab", "eidboaoo"}, {"abcde", "abcdae"}, {"aaaa", "aababbaabaabaabaaabaabaaaabaa"}};
    for (int i = 0; i < input.size(); i++) {
        cout << input[i].first << " : " << input[i].second << " => ";
        cout << solution.checkInclusion(input[i].first, input[i].second) << "\n";
    }
}