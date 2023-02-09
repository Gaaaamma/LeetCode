#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;

/*
#541 Reverse String II
Attempt 1: 
Two pointer with simulate procedure
Just do what question ask you to do

Complexity: O(N)

Q: Given a string s and an integer k
   reverse the first k characters for every 2k characters counting from the start of the string.

   If there are fewer than k characters left, 
   reverse all of them. If there are less than 2k but greater than or equal to k characters, 
   then reverse the first k characters and leave the other as original.
*/     

class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i = i + (k * 2)) {
            int left = i;
            int right = i + k - 1;
            if (right >= s.size())
                right = s.size() - 1;
            while (left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }
        return s;
    }
};

int main(int argc, char* argv[]){
    vector<pair<string, int>> inputSet;
    inputSet.push_back(pair<string, int>("abcdefg", 2));
    inputSet.push_back(make_pair("abcd", 2));

    Solution solution;
    for (int i = 0; i < inputSet.size(); i++) {
        cout << solution.reverseStr(inputSet[i].first, inputSet[i].second) << "\n";
    }
}