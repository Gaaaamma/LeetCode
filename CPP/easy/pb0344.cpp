#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;

/*
#344 Reverse String
Attempt 1: 
Use two pointer to solve, left =>  <= right
and swap each other
(Can also use algorithm reverse(begin, end))

Complexity: O(N)

Q: Write a function that reverses a string. 
   The input string is given as an array of characters s.
   You must do this by modifying the input array in-place with O(1) extra memory.
*/     

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            char tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;
            left++;
            right--;
        }
        reverse(s.begin(), s.end());
    }
};

void output(vector<char> s) {
    cout << "[";
    for (int i = 0; i < s.size() - 1; i++) {
        cout << s[i] << ", ";
    }
    cout << s[s.size() - 1] << "]\n";
}

int main(int argc, char* argv[]){
    vector<vector<char>> inputSet;
    inputSet.push_back(vector<char>{'h','e','l','l','o'});
    inputSet.push_back(vector<char>{'H','a','n','n','a','h'});


    Solution solution;
    for (int i = 0; i < inputSet.size(); i++) {
        solution.reverseString(inputSet[i]);
        output(inputSet[i]);
    }
}