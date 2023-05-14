#include <iostream>
#include <vector>
#include <stack>
#include <numeric>
using namespace std;

/*
#279 Perfect Squares
Attempt 1: 
Use DP to solve

Complexity: O() 

Q: Given an integer n, return the least number of perfect square numbers that sum to n.

   A perfect square is an integer that is the square of an integer; 
   in other words, it is the product of some integer with itself. 
   For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

*/     
class Solution {
public:
    int numSquares(int n) {
        int sqrtN = sqrt(n);
        vector<int> least(n + 1, INT_MAX);
        least[0] = 0;
        
        for (int i = 1; i <= sqrtN; i++) {
            int pow = i * i;
            for (int j = pow; j <= n; j++) {
                least[j] = min(least[j], least[j - pow] + 1);
            }
            // show(least);
        }
        return least.back();
    }

    void show(vector<int>& input) {
        for (int i = 0; i < input.size(); i++) {
            cout << input[i] << " ";
        }
        cout << "\n";
    }
};

int main(int argc, char* argv[]) {
    Solution solution;
    vector<int> input{1,12,13,16,30};
    for (int i = 0; i < input.size(); i++) {
        cout << solution.numSquares(input[i]) << "\n";
    }
}