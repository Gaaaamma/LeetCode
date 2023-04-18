#include <iostream>
#include <vector>
#include <unordered_map>
#include <iomanip>
using namespace std;

/*
#1768 Merge Strings Alternately
Attempt 1: 
Two pointer

Q: You are given two strings word1 and word2. 
   Merge the strings by adding letters in alternating order, starting with word1. 
   If a string is longer than the other, append the additional letters onto the end of the merged string.
   Return the merged string.
*/

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result = "";
        int indexA = 0;
        int indexB = 0;

        while (indexA < word1.size() && indexB < word2.size()) {
            result.push_back(word1[indexA]);
            result.push_back(word2[indexB]);
            indexA++;
            indexB++;
        }
        if (indexA < word1.size())
            result += word1.substr(indexA);
        else
            result += word2.substr(indexB);
        return result;
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
    vector<pair<string, string>> input{{"abcdefg", "ABCD"}, {"ab", "ABCDE"}, {"abcd", "ABCD"}};
    for (int i = 0; i < input.size(); i++) {
        cout << solution.mergeAlternately(input[i].first, input[i].second) << "\n";
    }
}
