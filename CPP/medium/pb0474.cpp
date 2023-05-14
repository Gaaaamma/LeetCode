#include <iostream>
#include <vector>
#include <stack>
#include <numeric>
using namespace std;

/*
#474 Ones and Zeros
Attempt 1: 
Use DP to solve

Complexity: O(N^2) 

Q: You are given an array of binary strings strs and two integers m and n.
   Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.
   A set x is a subset of a set y if all elements of x are also elements of y.


*/     
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> largest(m + 1, vector<int>(n + 1, 0));

        // Recursive way
        for (int i = 0; i < strs.size(); i++) {
            int zeroCount = 0;
            int oneCount = 0;
            countNum(strs[i], zeroCount, oneCount);
            for (int z = m; z >= zeroCount; z--) {
                for (int o = n; o >= oneCount; o--) {
                    largest[z][o] = max(largest[z][o], largest[z - zeroCount][o - oneCount] + 1);
                }
            }
        }
        return largest[m][n];
    }
    
    void countNum(string& str, int& zeroCount, int& oneCount) {
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '0') zeroCount++;
            else oneCount++;
        }
    }
};


int main(int argc, char* argv[]) {
    Solution solution;
    vector<vector<string>> inputA{{"10","0001","111001","1","0"}, {"10","0","1"}};
    vector<pair<int, int>> inputB{{5,3}, {1,1}};
    for (int i = 0; i < inputA.size(); i++) {
        cout << solution.findMaxForm(inputA[i], inputB[i].first, inputB[i].second) << "\n";
    }   
}