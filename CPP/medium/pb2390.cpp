#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

/*
#2390 Removing Stars from a String
Attempt 1: 
Two pointers

Q: You are given a string s, which contains stars *.
   In one operation, you can:
   - Choose a star in s.
   - Remove the closest non-star character to its left, as well as remove the star itself.
   Return the string after all stars have been removed.

   Note:
   - The input will be generated such that the operation is always possible.
   - It can be shown that the resulting string will always be unique.

*/
class Solution {
public:
    string removeStars(string s) {
        int left = s.size() - 1;
        int right = s.size() - 1;
        vector<bool> keep(s.size(), true);
        for (right = s.size() - 1; right >= 0; right--, left--) {
            if (s[right] == '*') {
                while (s[left] == '*') left--;
                keep[right] = false;
                keep[left] = false;
            } else {
                if (left < right) left++;
            }
        }

        string result = "";
        for (int i = 0; i < keep.size(); i++) {
            if (keep[i]) result += string(1, s[i]);
        }
        return result;
    }
};

template<class T>
void show1D(const vector<T>& input) {
    if (input.empty()) {
        cout << "[]\n";
        return;
    }
    cout << "[";
    for (int i = 0; i < input.size() - 1; i++) {
        cout << input[i] << ",";
    }
    cout << input.back() << "]\n";
}
template<class T>
void show2DGraph(const vector<vector<T>>& input) {
    for (int i = 0; i < input.size(); i++) {
        show1D(input[i]);
    }
}

int main(int argc, char* argv[]) {
    Solution solution;
    vector<string> input{"leet**cod*e", "erase*****", "abc*def*g*h**"};
    for (int i = 0; i < input.size(); i++) {
        cout << solution.removeStars(input[i]) << "\n";
    }
}