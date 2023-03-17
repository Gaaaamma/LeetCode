#include <iostream>
#include <vector>
#include <stack>
#include <numeric>
#include <queue>
using namespace std;

/*
#1035 Uncrossed Lines
Attempt 1: 
Use DP to solve

Q: You are given two integer arrays nums1 and nums2. 
   We write the integers of nums1 and nums2 (in the order they are given) on two separate horizontal lines.

   We may draw connecting lines: a straight line connecting two numbers nums1[i] and nums2[j] such that:
   
   nums1[i] == nums2[j], and
   the line we draw does not intersect any other connecting (non-horizontal) line.
   Note that a connecting line cannot intersect even at the endpoints (i.e., each number can only belong to one connecting line).
   
   Return the maximum number of connecting lines we can draw in this way.
*/
class Solution {
public:
    void show(vector<int>& input) {
        for (int i = 0; i < input.size(); i++) {
            cout << input[i] << " ";
        }
        cout << "\n";
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> len(nums1.size(), vector<int>(nums2.size(), 0));
        if (nums1[0] == nums2[0]) len[0][0] = 1;
        
        for (int i = 1; i < nums1.size(); i++) {
            if (nums1[i] == nums2[0]) 
                len[i][0] = 1;
            else 
                len[i][0] = len[i - 1][0]; 
        }
        for (int j = 1; j < nums2.size(); j++) {
            if (nums2[j] == nums1[0]) 
                len[0][j] = 1;
            else 
                len[0][j] = len[0][j - 1];
        }
        for (int i = 1; i < nums1.size(); i++) {
            for (int j = 1; j < nums2.size(); j++) {
                if (nums1[i] == nums2[j]) {
                    len[i][j] = len[i - 1][j - 1] + 1;
                } else {
                    len[i][j] = max(len[i - 1][j], len[i][j - 1]);
                } 
            }
        }
        return len.back().back();
    }
};
int main(int argc, char* argv[]) {
    Solution solution;
    vector<pair<vector<int>, vector<int>>> input{{{1,4,2}, {1,2,4}}, {{2,5,1,2,5}, {10,5,2,1,5,2}}, {{1,3,7,1,7,5}, {1,9,2,5,1}}, {{3,3}, {3}}};
    for (int i = 0; i < input.size(); i++) {
        cout << solution.maxUncrossedLines(input[i].first, input[i].second) << "\n";
    }
}