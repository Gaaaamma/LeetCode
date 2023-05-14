#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;

/*
#14 Longest Common Prefix
Attempt 1: 
Simulate procedure

Complexity: O(NM) 
N) vec size
M) string size

Q: Write a function to find the longest common prefix string amongst an array of strings.
   If there is no common prefix, return an empty string "".
*/     

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1) return strs[0];
        string result ="";
        for (int i = 0; i < strs[0].size(); i++) {
            for (int j = 1; j < strs.size(); j++) {
                if (i >= strs[j].size() || strs[0][i] != strs[j][i])
                    return result;
            }
            result += strs[0][i];
        }
        return result;
    }    
};

int main(int argc, char* argv[]){
    vector<vector<string>> input{{"flower","flow","flight"}, {"abcdefg","abcd","abcdekm"}, {"z"}};
    
    Solution solution;
    for (int i = 0; i < input.size(); i++) {
        cout << solution.longestCommonPrefix(input[i]) << "\n";
    }
}