#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
#96 Unique Binary Search Trees
Attempt 1: 
Use DP to solve

Complexity: O(N^2) 

Q: Given an integer n, return the number of structurally unique BST's 
   (binary search trees) which has exactly n nodes of unique values from 1 to n.
*/     
class Solution {
public:
    int numTrees(int n) {
        if (n == 1) return 1;
        vector<int> count(n + 1, 0);
        count[0] = 1; // Binary Tree can be empty
        count[1] = 1;
        count[2] = 2;
        for (int i = 3; i <= n; i++) {
            for (int r = 1; r <= i; r++) {
                int leftSide = r - 1;
                int rightSide = i - r;
                count[i] += count[leftSide] * count[rightSide];
            }
        }
        return count.back();
    }
};

int main(int argc, char* argv[]) {
    Solution solution;
    vector<int> input{2,3,4,5,6,15,16,17,19};
    for (int i = 0; i < input.size(); i++) {
        cout << solution.numTrees(input[i]) << "\n";
    }   
}