#include <iostream>
#include <vector>
#include <unordered_map>
#include <iomanip>
using namespace std;

/*
#13 Roman to Integer
Attempt 1: 
Simulation

Q: Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

   Symbol       Value
   I             1
   V             5
   X             10
   L             50
   C             100
   D             500
   M             1000

   For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, 
   which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.
   
   Roman numerals are usually written largest to smallest from left to right. 
   However, the numeral for four is not IIII. Instead, the number four is written as IV. 
   Because the one is before the five we subtract it making four. 
   The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:
   
    - I can be placed before V (5) and X (10) to make 4 and 9. 
    - X can be placed before L (50) and C (100) to make 40 and 90. 
    - C can be placed before D (500) and M (1000) to make 400 and 900.
   
   Given a roman numeral, convert it to an integer.
*/

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int result = 0;
        int preV = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            int curV = roman[s[i]];
            if (curV >= preV) result += curV;
            else if (curV < preV) result -= curV;
            preV = curV;
        }
        return result;
    }
};

int main(int argc, char* argv[]) {
    Solution solution;
    vector<string> input{"III", "IV", "IX", "LVIII", "MCMXCIV"};
    for (int i = 0; i < input.size(); i++) {
        cout << setw(7) << input[i];
        cout << " : " << setw(5) << solution.romanToInt(input[i]) << "\n";
    }
}
