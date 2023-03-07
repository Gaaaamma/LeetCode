#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
#509 Fibonacci Number
Attempt 1: 
use DP to solve

Complexity: O(N) 

Q: The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, 
   such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,
*/     

class Solution {
public:
    int fib(int n) {
        vector<int> fibonacci(31, 0);
        if (n == 0) return 0;
        if (n == 1) return 1;
        fibonacci[1] = 1;
        for (int i = 2; i <= n; i++) {
            fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
        }
        return fibonacci[n];
    }
};

int main(int argc, char* argv[]) {
    Solution solution;
    vector<int> input{1,2,3,4,5,6,10};
    for (int i = 0; i < input.size(); i++) {
        cout << solution.fib(input[i]) << "\n";
    }
}