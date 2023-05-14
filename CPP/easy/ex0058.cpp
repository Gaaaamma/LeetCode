#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;

/*
#5 Reverse Left Words
Attempt 1: 
Use an extra variable result to store the output

Attemp 2:
Reverse the whole string, then reverse substring

Complexity: O(N)

Q: 字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。
   请定义一个函数实现字符串左旋转操作的功能。
   比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。
   https://leetcode.cn/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof/
*/     

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        reverse(s.begin(), s.end());
        reverse(s.begin(), s.begin() + s.size() - n);
        reverse(s.begin() + s.size() - n, s.end());
        return s;
    }
};

int main(int argc, char* argv[]){
    vector<pair<string, int>> input{{"abcdefg", 2}, {"lrloseumgh", 6}};

    Solution solution;
    for (int i = 0; i < input.size(); i++) {
        cout << solution.reverseLeftWords(input[i].first, input[i].second) << "\n";
    }
}