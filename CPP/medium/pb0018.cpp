#include <iostream>
#include <algorithm> 
#include <vector>
#include <unordered_set>
using namespace std;

/*
#18 4 Sum
Attempt 1: 
Use two pointer to solve (Similar to 3Sum [#15], the concept is the same)

Complexity: O(N^3)

Q: Given an array nums of n integers, return an array of all the unique quadruplets 
   [nums[a], nums[b], nums[c], nums[d]] such that:

    - 0 <= a, b, c, d < n
    - a, b, c, and d are distinct.
    - nums[a] + nums[b] + nums[c] + nums[d] == target
    You may return the answer in any order.
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        if (nums.size() < 4) 
            return result;

        for (int i = 0; i < nums.size() - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            for (int j = i + 1; j < nums.size() - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                int left = j + 1;
                int right = nums.size() - 1;
                int lastLeft = INT_MAX;
                int lastRight = INT_MAX;
                while (left < right) {
                    if ((long)nums[i] + (long)nums[j] + (long)nums[left] + (long)nums[right] < target) {
                        left++;
                    } else if ((long)nums[i] + (long)nums[j] + (long)nums[left] + (long)nums[right] > target) {
                        right--;
                    } else {
                        // Same with target => reduce the same
                        if (nums[left] != lastLeft && nums[right] != lastRight) {
                            result.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
                            lastLeft = nums[left];
                            lastRight = nums[right];
                        }
                        left++;
                        right--;
                    }
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
    vector<int> targetSet{0, 8, 0};
    inputSet.push_back(vector<int>{1, 0, -1, 0, -2, 2});
    inputSet.push_back(vector<int>{2, 2, 2, 2, 2,});
    inputSet.push_back(vector<int>{1000000000, 1000000000, 100000000, 100000000});

    Solution solution;
    for (int i = 0; i < inputSet.size(); i++) {
        output(solution.fourSum(inputSet[i], targetSet[i]));
    }
}