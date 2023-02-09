#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;

/*
#5 Replace Space
Attempt 1: 
Use an extra variable result to store the output

Complexity: O(N)

Q: 请实现一个函数，把字符串 s 中的每个空格替换成"%20"。
   - 输入：s = "We are happy."
   - 输出："We%20are%20happy."
*/     

class Solution {
public:
    string replaceSpace(string s) {
        string result;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                result += "%20";
            } else {
                result += s[i];
            }
        }
        return result;
    }
};

int main(int argc, char* argv[]){
    vector<string> input{"We are happy.", "A B C D"};

    Solution solution;
    for (int i = 0; i < input.size(); i++) {
        cout << solution.replaceSpace(input[i]) << "\n";
    }
}