#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;

/*
#5 Replace Space
Attempt 1: 
Use an extra variable result to store the output

Attempt 2:
Use two pointer to solve (No extra variable)

Complexity: O(N)

Q: 请实现一个函数，把字符串 s 中的每个空格替换成"%20"。
   - 输入：s = "We are happy._ _ _ _"
   - 输出："We%20are%20happy."
*/     

class Solution {
public:
    string replaceSpace(string s) {
        int count = 0;
        int oldSize = s.size();
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') 
                count++;
        }
        s.resize(oldSize + count * 2);

        // Replace
        int j = s.size() - 1;
        for (int i = oldSize - 1; i >= 0; i--) {
            if (s[i] != ' ') {
                s[j] = s[i];
                j--;
            } else {
                s[j] = '0';
                s[j - 1] = '2';
                s[j - 2] = '%';
                j = j - 3; 
            }
        }
        return s;
    }
};

int main(int argc, char* argv[]){
    vector<string> input{"We are happy.", "A B C D"};

    Solution solution;
    for (int i = 0; i < input.size(); i++) {
        cout << solution.replaceSpace(input[i]) << "\n";
    }
}