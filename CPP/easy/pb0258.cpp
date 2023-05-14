#include <iostream>
#include <vector>
#include <unordered_map>
#include <iomanip>
#include <queue>
using namespace std;

/*
#258 Add Digits
Attempt 1: 
recursive

Q: Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.
*/

class Solution {
public:
    int addDigits(int num) {
        if (num / 10 == 0) return num;
        int sum = 0;
        while (num != 0) {
            sum += num % 10;
            num /= 10;
        }
        return addDigits(sum);
    }
};

template<class T>
void show1D(const vector<T>& input) {
    if (input.empty()) {
        cout << "[]\n";
        return;
    }
    cout << "[";
    for (int i = 0; i < input.size() - 1; i++) {
        cout << input[i] << ",";
    }
    cout << input.back() << "]\n";
}
template<class T>
void show2DGraph(const vector<vector<T>>& input) {
    for (int i = 0; i < input.size(); i++) {
        show1D(input[i]);
    }
}

int main(int argc, char* argv[]) {
    Solution solution;
    vector<int> input{38, 12345, 0, 1, 9};
    for (int i = 0; i < input.size(); i++) {
        cout << input[i] << " : ";
        cout << solution.addDigits(input[i]) << "\n";
    }
}
