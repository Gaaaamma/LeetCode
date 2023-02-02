#include <iostream>
#include <algorithm> 
#include <vector>
#include <unordered_set>
using namespace std;

/*
#202 Happy Number
Attempt 1: 
Use unordered_set to record a number had already been calculated
If we get the same number again -> this is not a happy number

Complexity: O(-)

Q: Write an algorithm to determine if a number n is happy.
   A happy number is a number defined by the following process:
     - Starting with any positive integer, replace the number by the sum of the squares of its digits.
     - Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
     - Those numbers for which this process ends in 1 are happy.
   Return true if n is a happy number, and false if not.
*/     

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> uoset;
        while (n != 1) {
            n = powerJudge(n);
            if (uoset.count(n)) {
                return false;
            } else {
                uoset.insert(n);
            }
        }
        return true;
    }

    int powerJudge(int num) {
        int val = 0;
        string str = to_string(num);
        for (int i = 0; i < str.size(); i++) {
            val += stoi(string(1, str[i])) * stoi(string(1, str[i]));
        }
        return val;
    }
};

int main(int argc, char* argv[]){
    vector<int> input = {19, 2};

    Solution solution;
    for (int i = 0; i < input.size(); i++) {
        cout << solution.isHappy(input[i]) << "\n";
    }
}