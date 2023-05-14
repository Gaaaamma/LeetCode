#include <iostream>
#include <algorithm> 
#include <vector>
#include <unordered_map>
using namespace std;

/*
#28 Find the Index of the First Occurrence in a String
Attempt 1: 
Use KMP algorithm to solve
(1) Make getNext (Prefix table)
(2) When comparing haystack & needle, use prefix table to move needlIndex to avoid comparing again.

Complexity: O(N+M)

Q: Given two strings needle and haystack, 
   return the index of the first occurrence of needle in haystack, 
   or -1 if needle is not part of haystack.
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        int* prefix = (int*)malloc(sizeof(int) * needle.size());
        getNext(prefix, needle);

        int needleIndex = 0;
        for (int i = 0; i < haystack.size(); i++) {
            if (haystack[i] == needle[needleIndex]) {
                needleIndex++;
                if (needleIndex == needle.size()) {
                    free(prefix);
                    return i - needle.size() + 1;
                }
            } else {
                if (needleIndex > 0) {
                    needleIndex = prefix[needleIndex - 1];
                    i--;
                }
            }
        }

        free(prefix);
        return - 1;
    }

    void getNext(int* prefix, string needle) {
        prefix[0] = 0;
        for (int i = 1; i < needle.size(); i++) {
            int compIndex = prefix[i - 1];
            while (true) {
                if (needle[i] == needle[compIndex]) {
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
    void showPrefix(int* prefix, string needle) {
        for (int i = 0; i < needle.size(); i++) {
            cout << needle[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < needle.size(); i++) {
            cout << prefix[i] << " ";
        }
        cout << "\n";
    }
};

int main(int argc, char* argv[]){
    vector<pair<string, string>> input;
    input.push_back(make_pair("sadbutsad", "sad"));
    input.push_back(make_pair("leetcode", "leeto"));
    input.push_back(make_pair("abcabcdabcdeabcdefg", "abcd"));
    input.push_back(make_pair("mississip", "issip"));
    input.push_back(make_pair("babbbbbabb", "bbab"));
    input.push_back(make_pair("baaabbbabaa", "babb"));
    input.push_back(make_pair("aabaaabaaac", "aabaaac"));

    Solution solution;
    for (int i = 0; i < input.size(); i++) {
        cout << solution.strStr(input[i].first, input[i].second) << "\n";
    }
}