#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/*
#56 Merge Intervals
Attempt 1: 
greedy to solve

Complexity: O(NlogN) 

Q: Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, 
   and return an array of the non-overlapping intervals that cover all the intervals in the input.
*/     
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 1) return intervals;
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
            return a[0] < b[0];
        });
        vector<vector<int>> result;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= intervals[i - 1][1]) {
                intervals[i][0] = intervals[i - 1][0];
                intervals[i][1] = max(intervals[i][1], intervals[i - 1][1]);
            } else {
                // Find a interval
                result.push_back(intervals[i - 1]);
            }
        }
        result.push_back(intervals.back());
        return result;
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
    vector<vector<vector<int>>> input{{{0,3}, {4,5}, {1,2}, {4,5}, {5,6}, {2,5}}};
    for (int i = 0; i < input.size(); i++) {
        output(solution.merge(input[i]));
    }
}