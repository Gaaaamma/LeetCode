#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
#435 Non-overlapping Intervals
Attempt 1: 
sort the intervals and use greedy to solve

Complexity: O(NlogN) 

Q: Given an array of intervals intervals where intervals[i] = [starti, endi], 
   return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.
*/     
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() == 1) return 0;
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
            return a[0] < b[0];
        });
        int count = 0;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < intervals[i - 1][1]) {
                count++;
                intervals[i][1] = min(intervals[i][1], intervals[i - 1][1]);
            }
        }
        return count;
    }
};

void output(vector<vector<int>> result) {
    if (result.empty()) {
        cout << "[]\n";
        return;
    }
    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << "[";
        for (int j = 0; j < result[i].size() -1; j++) {
            cout << result[i][j] << ", ";
        }
        cout << result[i].back() << "]";
    }
    cout << "]\n";
}
int main(int argc, char* argv[]) {
    Solution solution;
    vector<vector<vector<int>>> input{{{0,7}, {4,5}, {1,2}, {0,5}, {1,6}, {2,5}}};
    for (int i = 0; i < input.size(); i++) {
        cout << solution.eraseOverlapIntervals(input[i]) << "\n";
    }
}