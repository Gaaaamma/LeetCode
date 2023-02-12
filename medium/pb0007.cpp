#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;

/*
#7 Reverse Integer
Attempt 1:
1) Make the integer to string
2) Reverse the string
3) Compare it to UPPERBOUND (2147483648)

Complexity: O(N)

Q: Given a signed 32-bit integer x, return x with its digits reversed. 
   If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
   Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
*/

class Solution {
public:
    int reverse(int x) {
        if (x == 0){
            return 0;
        }
        string UPPERBOUND = "2147483648";
        int isNegative = (x < 0) ? -1 : 1;

        // x is positive now
        string num = to_string(x);
        std::reverse(num.begin(), num.end());
        if (isNegative < 0)
            num.erase(num.size() - 1);

        // Handle 0 start
        int startIndex = 0;
        for (int i = 0; i < num.size(); i++) {
            if (num[i] == '0') {
                startIndex++;
            } else {
                break;
            }
        }
        num = num.substr(startIndex, -1);

        // Compare to UPPERBOUND
        if (num.size() == UPPERBOUND.size()) {
            for (int i = 0; i < num.size(); i++) {
                if (num[i] - UPPERBOUND[i] > 0) return 0;
                else if(num[i] - UPPERBOUND[i] < 0) break;
            }
        }
        return stoi(num) * isNegative;
    }
};
int main(int argc, char* argv[]){
    vector<int> input{123, -123, 0, 2147483647, -2147483648, 1254246231, -1234532439};
    Solution solution;
    for (int i = 0; i < input.size(); i++) {
        cout << input[i] << " : " << solution.reverse(input[i]) << "\n";
    }

}