#include <iostream>
#include <vector>
#include <stack>
#include <numeric>
#include <queue>
using namespace std;

/*
#300 Maximum Length of Repeated Subarray
Attempt 1: 
Use DP to solve

Q: Given two integer arrays nums1 and nums2, return the maximum length of a subarray that appears in both arrays.
*/
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int maxLength = 0;
        vector<vector<int>> repeat(nums1.size(), vector<int>(nums2.size(), 0));
        for (int i = 0; i < nums2.size(); i++) {
            if (nums2[i] == nums1[0]) {
                repeat[0][i] = 1;
                maxLength = max(maxLength, repeat[0][i]);
            }
        }
        for (int i = 0; i < nums1.size(); i++) {
            if (nums1[i] == nums2[0]){
                repeat[i][0] = 1;
                maxLength = max(maxLength, repeat[i][0]);
            }
        }
        // show(repeat[0]);
        for (int i = 1; i < nums1.size(); i++) {
            for (int j = 1; j < nums2.size(); j++) {
                if (nums1[i] == nums2[j]) {
                    repeat[i][j] = repeat[i - 1][j - 1] + 1;
                    maxLength = max(maxLength, repeat[i][j]);
                }
            }
            // show(repeat[i]);
        }
        return maxLength;
    }
    void show(vector<int>& input) {
        for (int i = 0; i < input.size(); i++) {
            cout << input[i] << " ";
        }
        cout << "\n";
    }
};

int main(int argc, char* argv[]) {
    Solution solution;
    vector<pair<vector<int>, vector<int>>> input{{{3,2,1,4,7}, {1,2,3,2,1}}, {{0,0,0,0,0}, {0,0,0,0,0,0,0,0}}, {{1,2,3,4}, {5,6,7,8}}};
    for (int i = 0; i < input.size(); i++) {
        cout << solution.findLength(input[i].first, input[i].second) << "\n";
    }
}