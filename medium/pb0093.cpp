#include <iostream>
#include <vector>
using namespace std;

/*
#93 Restore IP Addresses
Attempt 1: 
Use backtracking to solve

Complexity: O(-) 

Q: A valid IP address consists of exactly four integers separated by single dots. 
   Each integer is between 0 and 255 (inclusive) and cannot have leading zeros.

   For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses, 
   but "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses.

   Given a string s containing only digits, return all possible valid IP addresses 
   that can be formed by inserting dots into s. 
   You are not allowed to reorder or remove any digits in s. You may return the valid IP addresses in any order.
*/     
class Solution {
public:
    vector<string> result;
    vector<string> combination;
    vector<string> restoreIpAddresses(string s) {
        result.clear();
        combination.clear();
        if (s.size() < 4 || s.size() > 12) return vector<string>{};
        backtracking(s, 0, 0);
        return result;
    }
    void backtracking(string s, int index, int count) {
        if (count == 4 && index == s.size()) {
            result.push_back(generateIp());
            return;
        } else if (count == 4) {
            return;
        }
        for (int i = 1; i <= 3; i++) {
            if (index + i > s.size()) continue;
            string word = s.substr(index, i);
            if (validIp(word)) {
                combination.push_back(word);
                backtracking(s, index + i, count + 1);
                combination.pop_back();
            }
        }
    }
    bool validIp(string s) {
        if (s.size() == 0 || s.size() > 3) return false;
        if (s.size() == 2 || s.size() == 3) {
            if (s[0] == '0') return false;
            if (stoi(s) < 0 || stoi(s) > 255) return false;
        }
        return true;
    }
    string generateIp() {
        string one ="";
        for (int i = 0; i < combination.size() - 1; i++) {
            one += combination[i];
            one += ".";
        }
        one += combination.back();
        return one;
    }
};
void output2D(vector<vector<string>> result) {
    if (result.size() == 0) {
        cout << "[]\n";
        return;
    }
    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << "[";
        for (int j = 0; j < result[i].size() - 1; j++) {
            cout << result[i][j] << ", ";
        }
        if (i != result.size() - 1) {
            cout << result[i].back() << "], ";
        } else {
            cout << result[i].back() << "]]\n";
        }
    }
}
void output(vector<string> result) {
    if (result.empty()) {
        cout << "[]\n";
    }
    cout << "[";
    for (int i = 0; i < result.size() - 1; i++) {
        cout << result[i] << ", ";
    }
    cout << result.back() << "]\n";
}
int main(int argc, char* argv[]) {
    Solution solution;
    vector<string> input{"0000", "0101011", "1112221", "123123"};
    for (int i = 0; i < input.size(); i++) {
        output(solution.restoreIpAddresses(input[i]));
    }
}