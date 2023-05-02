#include <iostream>
#include <vector>
#include <unordered_map>
#include <iomanip>
#include <queue>
using namespace std;

/*
#1822 Sign of the Product of an Array
Attempt 1: 
Math

Q: There is a function signFunc(x) that returns:
    - 1 if x is positive.
    - -1 if x is negative.
    - 0 if x is equal to 0.

   You are given an integer array nums. Let product be the product of all values in the array nums.
   Return signFunc(product).
*/

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int counter = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) return 0;
            if (nums[i] < 0) counter++;
        }
        return (counter % 2 == 0) ? 1 : -1;
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
    vector<vector<int>> input{{-1,-2,-3,-4,3,2,1}, {1,5,0,2,-3}, {-1,1,-1,1,-1}, {1,-1,0,1,2,1,-1,2}};
    for (int i = 0; i < input.size(); i++) {
        show1D(input[i]);
        cout << solution.arraySign(input[i]) << "\n\n";
    }
}
