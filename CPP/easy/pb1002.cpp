#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;

/*
#1002 Find Common Characters
Attempt 1: 
Use 2 Dim vector to record the occurence of each alphabet in the words
Check the min number of occurence to judge if this alphabet is legal

Complexity: O(N*M)
N: number of words
M: length of word

Q: Given a string array words, return an array of all characters that show up in all strings within the words 
   (including duplicates). 
   You may return the answer in any order.
*/     

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> result;
        vector<int> tmp(26, 0);
        vector<vector<int> > record(words.size(), tmp);

        // Make data
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].size(); j++) {
                record[i][words[i][j] - 'a']++;
            }
        }

        // Check all alphabet
        for (int i = 0; i < 26; i ++) {
            int minCount = INT_MAX;
            for (int j = 0; j < words.size(); j++) {
                minCount = (record[j][i] < minCount) ? record[j][i] : minCount;
            }

            string str(1, i + 'a');
            for (int k = 0; k < minCount; k++) {
                result.push_back(str);
            }
        }
        return result;
    }
};

void output(vector<string> words) {
    cout << "[";
    for (int i = 0; i < words.size() - 1; i++) {
        cout << words[i] << ",";
    }
    cout << words[words.size() - 1] << "]\n";
}

int main(int argc, char* argv[]){
    string arr1[] = {"bella", "label", "roller"};
    string arr2[] = {"cool", "lock", "cook"};
    string arr3[] = {"aaabbc", "bbc", "bb"};

    vector<string> input1(arr1, arr1 + sizeof(arr1) / sizeof(string));
    vector<string> input2(arr2, arr2 + sizeof(arr2) / sizeof(string));
    vector<string> input3(arr3, arr3 + sizeof(arr3) / sizeof(string));

    Solution solution;
    output(solution.commonChars(input1));
    output(solution.commonChars(input2));
    output(solution.commonChars(input3));
}