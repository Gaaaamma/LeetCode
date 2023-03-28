#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

/*
#438 Find All Anagrams in a String
Attempt 1: 
Slide Window

Q: Given two strings s and p, return an array of all the start indices of p's anagrams in s. 
   You may return the answer in any order.

   An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
   typically using all the original letters exactly once.
*/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        vector<int> alphabet(26, 0);
        unordered_map<char, int> map;
        int count = 0;
        for (int i = 0; i < p.size(); i++) {
            alphabet[p[i] - 'a']++;
            map[p[i]]++;
            count++;
        }

        int left = 0;
        int right = 0;
        int round = 0;
        for (right = 0; right < s.size(); right++) {
            if (map[s[right]] == 0) {
                while (left < right) {
                    alphabet[s[left] - 'a']++;
                    left++;
                }
                left++;
                round = 0;
            } else if (alphabet[s[right] - 'a'] == 0) {
                while (left < right) {
                    alphabet[s[left] - 'a']++;
                    left++;
                    round--;
                    if (s[left - 1] == s[right]) break;
                }
                alphabet[s[right] - 'a']--;
                round++;
            } else {
                alphabet[s[right] - 'a']--;
                round++;
                if (round == count) {
                    result.push_back(left);
                    alphabet[s[left] - 'a']++;
                    left++;
                    round--;
                }
            }
        }
        return result;
    }
};
void show(const vector<int>& input) {
    for (int i = 0; i < input.size(); i++) {
        cout << input[i] << " ";
    }
    cout << "\n";
}
int main(int argc, char* argv[]) {
    Solution solution;
    vector<pair<string, string>> input{{"abcab", "abc"}, {"aaaba", "a"}, {"cbaebabacd", "abc"}, {"abab", "ab"}};
    for (int i = 0; i < input.size(); i++) {
        show(solution.findAnagrams(input[i].first, input[i].second));
    }
}