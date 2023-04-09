#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

/*
#79 Word Search
Attempt 1: 
backtracking

Q: Given an m x n grid of characters board and a string word, return true if word exists in the grid.
   The word can be constructed from letters of sequentially adjacent cells, 
   where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.
*/
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] != word[0]) continue;
                vector<vector<bool>> visited(board.size(), vector<bool>(board.front().size(), false));
                if (backtracking(board, visited, word, 0, i, j)) return true;
            }
        }
        return false;
    }
    
    bool backtracking(vector<vector<char>>& board, vector<vector<bool>>& visited, string word, int index, int startI, int startJ) {
        if (board[startI][startJ] != word[index]) return false;
        if (index + 1 == word.size()) return true;
        visited[startI][startJ] = true;
        for (pair<int, int> dirc : direction) {
            int newI = startI + dirc.first;
            int newJ = startJ + dirc.second;
            if (newI < 0 || newI >= board.size() || newJ < 0 || newJ >= board.front().size()) continue;
            if (visited[newI][newJ]) continue;
            if (backtracking(board, visited, word, index + 1, newI, newJ)) return true;
        }
        visited[startI][startJ] = false;
        return false;
    }
private:
    vector<pair<int, int>> direction{{-1,0}, {1,0}, {0,-1}, {0,1}};
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
    vector<pair<vector<vector<char>>, string>> input{{{{'A','B','C','E'}, {'S','F','C','S'}, {'A','D','E','E'}}, "ABCCED"}};
    for (int i = 0; i < input.size(); i++) {
        cout << "Find: " << input[i].second << " == " << solution.exist(input[i].first, input[i].second) << "\n";
        show2DGraph(input[i].first);
        cout << "\n";
    }
}