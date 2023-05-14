#include <iostream>
#include <algorithm> 
#include <vector>
#include <unordered_map>
using namespace std;

/*
#242 Valid Anagram
Attempt 1: 
Use array (vector) to record how many times a alphabet occur
Complexity: O(N)

Q: Given two strings s and t, return true if t is an anagram of s, and false otherwise.
   An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
   typically using all the original letters exactly once.
*/     

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> alphabet(26, 0);

        for (int i = 0; i < s.size(); i++) {
            alphabet[s[i] - 'a']++;
        }

        for (int i = 0; i < t.size(); i++) {
            alphabet[t[i] - 'a']--;
        }

        // Check alphabet
        for (int i = 0; i < alphabet.size(); i++) {
            if (alphabet[i] !=0) {
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char* argv[]){
    vector<pair<string, string> > input;
    input.push_back(make_pair("anagram", "nagaram"));
    input.push_back(make_pair("rat", "car"));
    
    Solution solution;
    for (int i = 0; i < input.size(); i++) {
        cout << "Q" << (i + 1) << ": " << solution.isAnagram(input[i].first, input[i].second) << "\n";
    }
}