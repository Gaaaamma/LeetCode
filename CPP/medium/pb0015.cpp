#include <iostream>
#include <algorithm> 
#include <vector>
#include <unordered_set>
using namespace std;

/*
#15 4 Sum
Attempt 1: 
Use two pointer to solve 
1) i from 0 to nums.size() - 3
2) left = i + 1
3) right = nums.size() - 1
The critical point is to avoid the same output

Complexity: O(N^2)

Q: Given an integer array nums, return all the triplets 
   [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

   Notice that the solution set must not contain duplicate triplets.
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int lastI = INT_MAX;
        int lastLeft = INT_MAX;
        int lastRight = INT_MAX;
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                if (nums[i] + nums[left] + nums[right] > 0) {
                    right--;
                    } else if (nums[i] + nums[left] + nums[right] < 0) {
                        left++;
                    } else {
                        if (nums[i] != lastI || nums[left] != lastLeft || nums[right] != lastRight) {
                            result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                            lastI = nums[i];
                            lastLeft = nums[left];
                            lastRight = nums[right];
                        }
                        left++;
                        right--;
                    }
            }
        }
        return result;
    }
};

void output(vector<vector<int>> nums) {
    if (nums.empty()) {
        cout << "[]\n";
    } else {
        cout << "[";
        for (int i = 0; i < nums.size(); i++) {
            cout << "[";
            for (int j = 0; j < nums[i].size() - 1; j++) {
                cout << nums[i][j] << ", ";
            }

            if (i != nums.size() - 1) {
                cout << nums[i][nums[i].size() - 1] << "], ";
            } else {
                // Last one
                cout << nums[i][nums[i].size() - 1] << "]]\n";
            }
        }
    }
}

int main(int argc, char* argv[]){
    vector<vector<int>> inputSet;
    inputSet.push_back(vector<int>{-1, 0, 1, 2, -1, -4});
    inputSet.push_back(vector<int>{0, 1, 1});
    inputSet.push_back(vector<int>{0, 0, 0});
    inputSet.push_back(vector<int>{-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6});

    Solution solution;
    for (int i = 0; i < inputSet.size(); i++) {
        output(solution.threeSum(inputSet[i]));
    }
}