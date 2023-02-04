#include <iostream>
#include <algorithm> 
#include <vector>
#include <unordered_map>
using namespace std;

/*
#454 4Sum II
Attempt 1: 
1) Use nums1 & nums2 to create an unordered_map
2) Add num3 & num4 and find if there is the sum in the unordered_map

Complexity: O(N^2)

Q: Given four integer arrays nums1, nums2, nums3, and nums4 all of length n, return the number of tuples (i, j, k, l) such that:
     - 0 <= i, j, k, l < n
     - nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
*/

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> uomap;

        // Use nums1 & nums2 to create an unordered_map
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                int sum = nums1[i] + nums2[j];
                if (uomap.count(sum)) {
                    uomap[sum]++;
                } else {
                    uomap.insert(pair<int, int>(sum, 1));
                }
            }
        }

        // Add num3 & num4 and find if there is the sum in the unordered_map
        int result = 0;
        for (int i = 0; i < nums3.size(); i++) {
            for (int j = 0; j < nums4.size(); j++) {
                int sum = -1 * (nums3[i] + nums4[j]);
                if (uomap.count(sum))
                    result += uomap[sum];
            }
        }
        return result;
    }
};

int main(int argc, char* argv[]){
    vector<int> nums1{1, 2};
    vector<int> nums2{-2, -1};
    vector<int> nums3{-1, 2};
    vector<int> nums4{0, 2};

    Solution solution;
    cout << solution.fourSumCount(nums1, nums2, nums3, nums4) << "\n";
}