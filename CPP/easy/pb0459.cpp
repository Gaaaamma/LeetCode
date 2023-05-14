#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;

/*
#541 Repeated Substring Pattern
Attempt 1: 
1) Find prefix table to know the relation of prefix and suffix
2) Try to use prefix table to find whether the string is constructed by a substring (Get wrong answer many times)
   = Now prefix equals the number of last value in prefix table
   - if prefix + suffix < string.size() => definitely false
   - if prefix + suffix == string.size() => definitely true
   - if prefix + suffix > string.size()
      - if cover.size() < prefix - cover.size() => definitely false
      - Use prefix to match cover and check if prefix can directly construct cover

Complexity: O(N)

Q: Given a string s, 
   check if it can be constructed by taking a substring of it 
   and appending multiple copies of the substring together.
*/     

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        if (s.size() == 1)
            return false;

        // Make prefix
        int* prefix = (int*) malloc(sizeof(int) * s.size());
        getNext(prefix, s);

        // Check prefix
        int lastPrefix = prefix[s.size() - 1];
        int cover = lastPrefix * 2 - s.size();
        if (cover < 0) {
            return false;
        } else if (cover == 0) {
            return true;
        } else {
            string front = s.substr(0, lastPrefix - cover);
            string end = s.substr(lastPrefix - cover, cover);
            if (end.size() < front.size())
                return false;

            for (int i = 0; i < end.size(); i++) {
                if (end[i] != front[i % front.size()])
                    return false;
            }
            return true;
        }
    }

    void getNext(int* prefix, string s) {
        prefix[0] = 0;
        for (int i = 1; i < s.size(); i++) {
            int compIndex = prefix[i - 1];
            while (true) {
                if (s[i] == s[compIndex]) {
                    prefix[i] = compIndex + 1;
                    break;
                }
                if (compIndex == 0) {
                    prefix[i] = 0;
                    break;
                }
                compIndex = prefix[compIndex - 1];
            }
        }
    }

    void showNext(int* prefix, string s) {
        for (int i = 0; i < s.size(); i++) {
            cout << s[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < s.size(); i++) {
            cout << prefix[i] << " ";
        }
        cout << "\n";
    }
};

int main(int argc, char* argv[]){
    vector<string> input{"abab", "aba", "abcabcabcabc", "aaa", "aa", "ab", "abcabcab", "abcabckkkabcabckkk", "abcaakkabcaakk", "abaabaa"};

    Solution solution;
    for (int i = 0; i < input.size(); i++) {
        cout << solution.repeatedSubstringPattern(input[i]) << "\n";
    }
}