#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
#452 Minimum Number of Arrows to Burst Balloons
Attempt 1: 
sort the points and use greedy to solve

Complexity: O(NlogN) 

Q: There are some spherical balloons taped onto a flat wall that represents the XY-plane. 
   The balloons are represented as a 2D integer array points where points[i] = [xstart, xend] 
   denotes a balloon whose horizontal diameter stretches between xstart and xend. 
   You do not know the exact y-coordinates of the balloons.

   Arrows can be shot up directly vertically (in the positive y-direction) from different points along the x-axis. 
   A balloon with xstart and xend is burst by an arrow shot at x if xstart <= x <= xend. 
   There is no limit to the number of arrows that can be shot. 
   A shot arrow keeps traveling up infinitely, bursting any balloons in its path.

   Given the array points, return the minimum number of arrows that must be shot to burst all balloons.
*/     
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 0) return 0;
        sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b){
            return a[0] < b[0];
        });
        int arrow = 1;
        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] > points[i - 1][1]) {
                arrow++;
            } else {
                points[i][1] = min(points[i][1], points[i - 1][1]);
            }
        }
        return arrow;
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
        cout << solution.findMinArrowShots(input[i]) << "\n";
    }
}