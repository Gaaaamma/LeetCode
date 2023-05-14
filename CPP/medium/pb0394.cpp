#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
#394 Decode String
Attempt 1: 
Stack

Q: Given an encoded string, return its decoded string.
   
   The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets 
   is being repeated exactly k times. Note that k is guaranteed to be a positive integer.
   
   You may assume that the input string is always valid; there are no extra white spaces, 
   square brackets are well-formed, etc. Furthermore, you may assume that the original data 
   does not contain any digits and that digits are only for those repeat numbers, k. 
   For example, there will not be input like 3a or 2[4].
   
   The test cases are generated so that the length of the output will never exceed 10^5.
*/

class Solution {
public:
    string decodeString(string s) {
        string result = "";
        stack<int> numStack;
        stack<string> strStack;

        string times = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                times += string(1, s[i]);
            } else if (s[i] == '[') {
                numStack.push(stoi(times));
                times = "";
                i++;
                string str = "";
                while (s[i] != ']' && !(s[i] >= '0' && s[i] <= '9')) {
                    str += string(1, s[i]);
                    i++;
                }
                i--;
                strStack.push(str);

            } else if (s[i] == ']') {
                if (numStack.size() == 1) {
                    string append = "";
                    for (int i = 0; i < numStack.top(); i++) {
                        append += strStack.top();
                    }
                    result += append;
                    numStack.pop();
                    strStack.pop();
                } else {
                    string back = "";
                    for (int i = 0; i < numStack.top(); i++) {
                        back += strStack.top();
                    }
                    numStack.pop();
                    strStack.pop();
                    
                    string front = strStack.top();
                    front += back;
                    strStack.pop();
                    strStack.push(front);
                }
            } else {
                // Direct alphabet
                if (strStack.empty()) {
                    result += string(1, s[i]);
                } else {
                    string tmp = strStack.top();
                    strStack.pop();
                    tmp += string(1, s[i]);
                    strStack.push(tmp);
                }
            }
        }

        return result;
    }
};
int main(int argc, char* argv[]) {
    Solution solution;
    vector<string> input{"3[a]2[bc]", "3[a2[c]]", "2[abc]3[cd]ef", "3[a2[c]g]mn"};
    for (int i = 0; i < input.size(); i++) {
        cout << solution.decodeString(input[i]) << "\n";
    }
}