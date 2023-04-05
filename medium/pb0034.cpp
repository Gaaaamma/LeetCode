#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

/*
#34 Find First and Last Position of Element in Sorted Array
Attempt 1: 
binary search

Q: Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
   If target is not found in the array, return [-1, -1].
   You must write an algorithm with O(log n) runtime complexity.
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return vector<int>{-1, -1};
        vector<int> result{-1, -1};
        result[0] = binaryFindFirst(nums, target);
        result[1] = binaryFindLast(nums, target);
        return result;
    }
    
    int binaryFindFirst(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        int left = 0;
        int right = nums.size();
        while (left < right) {
            int middle = left + (right - left) / 2;
            if (nums[middle] == target) {
                if (middle > 0 && nums[middle - 1] == target) right = middle;
                else return middle;

            } else if (nums[middle] < target) {
                left = middle + 1;
            } else if (nums[middle] > target) {
                right = middle;
            }
        }
        return -1;
    }

    int binaryFindLast(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        int left = 0;
        int right = nums.size();
        while (left < right) {
            int middle = left + (right - left) / 2;
            if (nums[middle] == target) {
                if (middle != nums.size() - 1 && nums[middle + 1] == target) left = middle + 1;
                else return middle;

            } else if (nums[middle] < target) {
                left = middle + 1;
            } else if (nums[middle] > target) {
                right = middle;
            }
        }
        return -1;
    }
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

int main(int argc, char* argv[]) {
    Solution solution;
    vector<pair<vector<int>, int>> input{{{1,1,2,3,4,4,5}, 1}, {{1,1,2,3,4,4,5}, 4}, {{1,1,2,3,4,4,5}, 5}, {{1,1,2,3,4,4,5}, 8}};
    for (int i = 0; i < input.size(); i++) {
        cout << input[i].second << " : ";
        show1D(input[i].first);
        show1D(solution.searchRange(input[i].first, input[i].second));
        cout << "\n";
    }
}