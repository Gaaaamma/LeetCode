#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;

/*
#383 Ransom Note
Attempt 1: 
Use vector to act as hash table to solve

Complexity: O(N)

Q: Given two strings ransomNote and magazine, 
   return true if ransomNote can be constructed by using the letters from magazine and false otherwise.
   Each letter in magazine can only be used once in ransomNote.
*/     

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // Use ransomNote and magazine to construct the frequency
        const int ALPHABET_SIZE = 26;
        vector<int> ransom(ALPHABET_SIZE, 0);
        vector<int> magz(ALPHABET_SIZE, 0);

        for (int i = 0; i < ransomNote.size(); i++) {
            ransom[ransomNote[i] - 'a']++;
        }

        for (int i = 0; i < magazine.size(); i++) {
            magz[magazine[i] - 'a']++;
        }

        for (int i = 0; i < ALPHABET_SIZE; i++) {
            if (ransom[i] > magz[i])
                return false;
        }

        return true;
    }
};

int main(int argc, char* argv[]){
    vector<pair<string, string> > input;
    input.push_back(make_pair("a", "b"));
    input.push_back(make_pair("aa", "ab"));
    input.push_back(make_pair("aa", "aab"));

    Solution solution;
    for (int i = 0; i < input.size(); i++) {
        cout << "[" << i << "]: " << solution.canConstruct(input[i].first, input[i].second) << "\n";
    }
}