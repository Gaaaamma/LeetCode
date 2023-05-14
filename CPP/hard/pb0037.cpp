#include <iostream>
#include <vector>
#include <deque>
using namespace std;

/*
#51 Sudoku Solver
Attempt 1: 
use backtracking to solve

Complexity: O(-)

Q: Write a program to solve a Sudoku puzzle by filling the empty cells.

   A sudoku solution must satisfy all of the following rules:
   - Each of the digits 1-9 must occur exactly once in each row.
   - Each of the digits 1-9 must occur exactly once in each column.
   - Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
   - The '.' character indicates empty cells.
*/

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtracking(board, 0);
    }
    bool backtracking(vector<vector<char>>& board, int index) {
        if (index == 9 * 9) {
            return true;
        }
        int row = index / 9;
        int column = index % 9;
        if (board[row][column] != '.') {
            return backtracking(board, index + 1);
        } else {
            for (int i = 1; i <= 9; i++) {
                bool existed = false;
                // Check row
                for (int j = 0; j < 9; j++) {
                    if (board[row][j] == char(i + '0')) {
                        existed = true;
                        break;
                    }
                }
                if (existed) continue;

                // Check column
                for (int j = 0; j < 9; j++) {
                    if (board[j][column] == char(i + '0')) {
                        existed = true;
                        break;
                    }
                }
                if (existed) continue;

                // Check matrix
                int rowMod = row % 3;
                int columnMod = column % 3;
                for (int rowMat = row - rowMod; rowMat < row - rowMod + 3; rowMat++) {
                    for (int colMat = column - columnMod; colMat < column - columnMod + 3; colMat++) {
                        if (board[rowMat][colMat] == char(i + '0')) {
                            existed = true;
                            break;
                        }
                    }
                }
                if (existed) continue;
                /*
                0 1 2   / 3 4 5    / 6 7 8
                9 10 11 / 12 13 14 / 15 16 17
                18 19 20/ 21 22 23 / 24 25 26
                row = 2, column = 4
                rowMod = 2, columnMod = 1
                */
                board[row][column] = char(i + '0');
                bool find = backtracking(board, index + 1);
                if (find) return true;
                else board[row][column] = '.';
            }
            return false;
        }
    }
};

void showSudoku(vector<vector<char>> input) {
    cout << "\n";
    for (int i = 0; i < input.size(); i++) {
        for (int j = 0; j < input[i].size(); j++) {
            cout << input[i][j] << "  ";
        }
        cout << "\n";
    }
}
int main(int argc, char* argv[]) {
    Solution solution;
    vector<vector<char>> input{
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}};
    showSudoku(input) ;
    solution.solveSudoku(input);
    showSudoku(input);
}