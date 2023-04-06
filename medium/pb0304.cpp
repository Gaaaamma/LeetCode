#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
#304 Range Sum Query 2D - Immutable
Attempt 1: 
Prefix Sum 2D

Q: Given a 2D matrix matrix, handle multiple queries of the following type:
   - Calculate the sum of the elements of matrix inside the rectangle defined by 
     its upper left corner (row1, col1) and lower right corner (row2, col2).

   Implement the NumMatrix class:
   -  NumMatrix(int[][] matrix) Initializes the object with the integer matrix matrix.
   -  int sumRegion(int row1, int col1, int row2, int col2) Returns the sum of the elements of matrix 
      inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

   You must design an algorithm where sumRegion works on O(1) time complexity.
*/

class NumMatrix {
private:
    vector<vector<int>> prefix;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        prefix = vector<vector<int>>(matrix.begin(), matrix.end());
        for (int j = 1; j < prefix[0].size(); j++) {
            prefix[0][j] += prefix[0][j - 1];
        }
        for (int i = 1; i < prefix.size(); i++) {
            prefix[i][0] += prefix[i - 1][0];
        }
        for (int i = 1; i < prefix.size(); i++) {
            for (int j = 1; j < prefix[i].size(); j++) {
                prefix[i][j] += prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int result = prefix[row2][col2];
        int upRow = row1 - 1;
        int leftCol = col1 - 1;
        if (upRow >= 0) result -= prefix[upRow][col2];
        if (leftCol >= 0) result -= prefix[row2][leftCol];
        if (upRow >= 0 && leftCol >= 0) result += prefix[upRow][leftCol];
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
    vector<vector<int>> matrix{{3,0,1,4,2}, {5,6,3,2,1}, {1,2,0,1,5}, {4,1,0,1,7}, {1,0,3,0,5}};
    vector<pair<pair<int, int>, pair<int, int>>> input{{{2,1}, {4,3}}, {{1,1}, {2,2}}, {{1,2}, {2,4}}};
    NumMatrix* obj = new NumMatrix(matrix);
    show2DGraph(matrix);
    for (int i = 0; i < input.size(); i++) {
        cout << input[i].first.first << ":" << input[i].first.second << " => " << input[i].second.first << ":" << input[i].second.second << " = ";
        cout << obj->sumRegion(input[i].first.first, input[i].first.second, input[i].second.first, input[i].second.second) << "\n";
    }
}