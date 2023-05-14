#include <iostream>
#include <algorithm> 
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

/*
#20 Valid Parentheses
Attempt 1: 
Use stack to solve

Complexity: O(-)

Q: Given a string s containing just the characters '(', ')', '{', '}', '[' and ']'
   determine if the input string is valid.

   An input string is valid if:
   -  Open brackets must be closed by the same type of brackets.
   -  Open brackets must be closed in the correct order.
   -  Every close bracket has a corresponding open bracket of the same type.
*/     
class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> mapping{{'}', '{'}, {']', '['}, {')', '('}};
        stack<char> solve;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
                solve.push(s[i]);
            } else if (solve.empty()) {
                return false;
            } else {
                unordered_map<char, char>::iterator getIt = mapping.find(s[i]);
                if (solve.top() != getIt->second) {
                    return false;
                } else {
                    solve.pop();
                }
            }
        }
        
        if (solve.empty()) {
            return true;
        } else {
            return false;
        }
    }
};

int main(int argc, char* argv[]){
    vector<string> input{"()", "()[]{}", "(]", "{[()]}()[]{()}"};
    Solution solution;
    for (int i = 0; i < input.size(); i++) {
        cout << input[i] << " : " << solution.isValid(input[i]) << "\n";
    }
}