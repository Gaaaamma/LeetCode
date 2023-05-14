#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
#860 Lemonade Change
Attempt 1: 
use greedy to solve

Complexity: O(N) 

Q: At a lemonade stand, each lemonade costs $5. 
   Customers are standing in a queue to buy from you and order one at a time (in the order specified by bills). 
   Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill. 
   You must provide the correct change to each customer so that the net transaction is that the customer pays $5.

   Note that you do not have any change in hand at first.

   Given an integer array bills where bills[i] is the bill the ith customer pays, 
   return true if you can provide every customer with the correct change, or false otherwise.
*/     

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int, int> changes{{5, 0},{10, 0},{20, 0}};
        for (int i = 0; i < bills.size(); i++) {
            if (bills[i] == 5) {
                changes[5]++;
            } else if (bills[i] == 10) {
                changes[10]++;
                changes[5]--;
                if (changes[5] < 0) return false;
            } else if (bills[i] == 20) {
                changes[20]++;
                changes[10]--;
                if (changes[10] < 0) {
                    changes[10]++;
                    changes[5] -= 2;
                }
                changes[5]--;
                if (changes[5] < 0 || changes[10] < 0) return false;
            }
        }
        return true;
    }
};
int main(int argc, char* argv[]) {
    Solution solution;
    vector<vector<int>> input{{5,10,5,5,5,20}, {5,10,10}, {5,5,5,10,20,10}};
    for (int i = 0; i < input.size(); i++) {
        cout << solution.lemonadeChange(input[i]) << "\n";
    }
}