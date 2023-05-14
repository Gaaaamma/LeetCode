#include <iostream>
#include <algorithm> 
#include <vector>
#include <stack>
using namespace std;

/*
#1047 Remove All Adjacent Duplicates In String
Attempt 1: 
use stack to solve

Complexity: O(N)

Q: You are given a string s consisting of lowercase English letters. 
   A duplicate removal consists of choosing two adjacent and equal letters and removing them.

   We repeatedly make duplicate removals on s until we no longer can.
   Return the final string after all such duplicate removals have been made. 
   It can be proven that the answer is unique.
*/     

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> solve;
        for (int i = 0; i < s.size(); i++) {
            if (solve.empty() || s[i] != solve.top()) 
                solve.push(s[i]);
            else 
                solve.pop(); 
            
        }
        // output all elements in the stack
        string result = "";
        int stackSize = solve.size();
        for (int i = 0; i < stackSize; i++) {
            result += solve.top();
            solve.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main(int argc, char* argv[]){
    vector<string> input{"abbaca", "azxxzy", "abcbbcba"};

    Solution solution;
    for (int i = 0; i < input.size(); i++) {
        cout << input[i] << " : " << solution.removeDuplicates(input[i]) << "\n";
    }
    cout << "\n";
}