#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

/*
#43 Group Anagram
Attempt 1: 
unordered_map & multiset

Q: Given an array of strings strs, group the anagrams together. 
   You can return the answer in any order.
   An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
   typically using all the original letters exactly once.
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> buckStr(strs.size(), "");
        for (int i = 0; i < strs.size(); i++) {
            buckStr[i] = bucketSort(strs[i]);
        }
        
        unordered_map<string, multiset<string>> uomap;
        for (int i = 0; i < buckStr.size(); i++) {
            uomap[buckStr[i]].insert(strs[i]);
        }
        
        vector<vector<string>> result;
        result.reserve(strs.size());
        for (pair<string, multiset<string>> item : uomap) {
            vector<string> round;
            for (string s : item.second) {
                round.push_back(s);
            }
            result.push_back(round);
        }
        return result;
    }
    string bucketSort(string& str) {
        vector<int> alpha(26, 0);
        for (int i = 0; i < str.size(); i++) 
            alpha[str[i] - 'a']++;
        
        string result = "";
        for (int i = 0; i < alpha.size(); i++) {
            if (alpha[i] == 0) continue;
            result += string(alpha[i], i + 'a');
        }
        return result;
    }
};


template<class T>
void show1D(const vector<T>& input) {
    if (input.empty()) {
        cout << "[]";
        return;
    }
    cout << "[";
    for (int i = 0; i < input.size() - 1; i++) {
        cout << input[i] << ",";
    }
    cout << input.back() << "]";
}

template<class T>
void show2D(const vector<vector<T>>& input) {
    if (input.empty()) {
        cout << "[[]]\n";
        return;
    }
    cout << "[";
    for (int i = 0; i < input.size() - 1; i++) {
        show1D(input[i]);
        cout << ",";
    }
    show1D(input.back());
    cout << "]\n";
}

int main(int argc, char* argv[]) {
    Solution solution;
    vector<vector<string>> input{{"eat","tea","tan","ate","nat","bat"}, {"a"}, {""}};
    for (int i = 0; i < input.size(); i++) {
        show2D(solution.groupAnagrams(input[i]));
    }
}