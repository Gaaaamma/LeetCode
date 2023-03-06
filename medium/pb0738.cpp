#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/*
#738 Monotone Increasing Digits
Attempt 1: 
greedy to solve

Complexity: O(N) 

Q: An integer has monotone increasing digits if and only if each pair of adjacent digits x and y satisfy x <= y.
   Given an integer n, return the largest number that is less than or equal to n with monotone increasing digits.
*/     
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string num = to_string(n);
        if (num.size() == 1) return stoi(num);

        int changeIndex = -1;
        for (int i = 0; i < num.size() - 1; i++) {
            if (num[i] <= num[i + 1]) continue;
            changeIndex = i;
            break;
        }

        while (changeIndex != -1) {
            if (changeIndex == 0) {
                num[changeIndex] -= 1;
                for (int i = changeIndex + 1; i < num.size(); i++) {
                    num[i] = '9';
                }
                break;
            } else if (num[changeIndex] >= num[changeIndex - 1] + 1) {
                num[changeIndex] -= 1;
                for (int i = changeIndex + 1; i < num.size(); i++) {
                    num[i] = '9';
                }
                break;
            }
            changeIndex--;
        }
        return stoi(num);   
    }
};

int main(int argc, char* argv[]) {
    Solution solution;
    vector<int> input{10, 1234, 4321, 11102};
    for (int i = 0; i < input.size(); i++) {
        cout << solution.monotoneIncreasingDigits(input[i]) << "\n";
    }
}