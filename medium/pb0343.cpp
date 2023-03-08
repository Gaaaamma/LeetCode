#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
#343 Integer Break
Attempt 1: 
Use DP to solve

Complexity: O(N) 

Q: Given an integer n, break it into the sum of k positive integers, 
   where k >= 2, and maximize the product of those integers.

   Return the maximum product you can get.
*/     
class Solution {
public:
    int integerBreak(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        vector<int> product(n + 1, 0);
        product[2] = 2;
        product[3] = 3;
        product[4] = 4;
        for (int i = 5; i <= n; i++) {
            int tmpMax = max(product[i - 2] * 2, product[i - 3] * 3);
            product[i] = max(tmpMax, product[i - 4] * 4);
        }
        return product[n];
    }
};

int main(int argc, char* argv[]) {
    Solution solution;
    vector<int> input{2,3,4,5,6,15,16,17,58};
    for (int i = 0; i < input.size(); i++) {
        cout << solution.integerBreak(input[i]) << "\n";
    }   
}