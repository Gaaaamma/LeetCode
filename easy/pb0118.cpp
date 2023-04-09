#include <iostream>
#include <vector>
#include <unordered_map>
#include <iomanip>
using namespace std;

/*
#118 Pascal's Triangle
Attempt 1: 
Simulation

Q: Given an integer numRows, return the first numRows of Pascal's triangle.
   In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 1) return vector<vector<int>>{{1}};
        vector<vector<int>> result{{1},{1,1}};
        for (int i = 3; i <= numRows; i++) {
            vector<int> round(i ,1);
            for (int j = 1; j < round.size() - 1; j++) {
                round[j] = result.back()[j] + result.back()[j - 1];
            }
            result.push_back(round);
        } 
        return result;
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
    vector<int> input{1,2,3,4,5,10};
    for (int i = 0; i < input.size(); i++) {
        cout << input[i] << ":\n";
        show2DGraph(solution.generate(input[i]));
        cout << "\n";
    }
}
