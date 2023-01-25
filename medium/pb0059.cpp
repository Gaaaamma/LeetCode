#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;

/*
#59 Spiral Matrix II
Attempt 1: 
Just simulate the procedure of filling the matrix
Complexity: O(N^2)
*/

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<int> row(n, 0);
        vector<vector<int> > matrix(n, row);
        int num = 1;
        int indexI = 0;
        int indexJ = 0;
        for (int size = n; size >= 1; size-=2) {
            fill(matrix, size, indexI, indexJ, num);
            indexI++;
            indexJ++;
        }
        return matrix;
    }

    void fill(vector<vector<int> >& matrix, int length, int i, int j, int& num) {
        // rowUp
        int indexI = i;
        int indexJ = j;
        for (; indexJ < j + length; indexJ++) {
            matrix[indexI][indexJ] = num;
            num++;
        }
        indexJ --;
        num--;


        // column right
        for (; indexI < i + length; indexI++) {
            matrix[indexI][indexJ] = num;
            num++;
        }
        indexI--;
        num--;

        // rowDown
        for (; indexJ >= j; indexJ--) {
            matrix[indexI][indexJ] = num;
            num++;
        }
        indexJ ++;
        num--;

        // column left
        for (; indexI > i ; indexI--) {
            matrix[indexI][indexJ] = num;
            num++;
        }
        indexI++;
    }
};

void output(vector<vector<int> > matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        cout << "[";
        for (int j = 0; j < matrix[i].size(); j++) {
            if (j == matrix[i].size() - 1) {
                cout << matrix[i][j] << "]\n";
            } else {
                cout << matrix[i][j] << ",";
            }
        }
    }
    cout << "\n";
}

int main(int argc, char* argv[]){
    int n1 = 3;
    int n2 = 2;
    int n3 = 10;

    Solution solution;
    output(solution.generateMatrix(n1));
    output(solution.generateMatrix(n2));
    output(solution.generateMatrix(n3));
}