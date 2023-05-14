#include <iostream>
#include <algorithm> 
#include <vector>
#include <unordered_map>
using namespace std;

/*
#1 Two Sum
Attempt 2: 
Use unordered_map to solve

Complexity: O(N)

Q: Given an array of integers nums and an integer target, 
   return indices of the two numbers such that they add up to target.

   You may assume that each input would have exactly one solution, and you may not use the same element twice.
   You can return the answer in any order.
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> uomap;

        for (int i = 0; i < nums.size(); i++) {
            int remain = target - nums[i];
            if (uomap.count(remain) == false) {
                // Not find
                uomap.insert({nums[i], i});
            } else {
                // Find
                return vector<int>{i, uomap[remain]};
            }
        }
        return vector<int>{0};
    }
};

void output(vector<int> result) {
    cout << "[";
    for(int i = 0; i < result.size(); i++) {
        if((i + 1) == result.size()){
            // the last one
            cout << result.at(i) << "]\n";
        }else{
            cout << result.at(i) << ",";
        }
    }
}

int main(int argc, char* argv[]){
    int arr1[] = {2,7,11,15};
    int arr2[] = {3,2,4};
    int arr3[] = {3,3};

    vector<int> input1(arr1, arr1 + sizeof(arr1) / sizeof(int));
    vector<int> input2(arr2, arr2 + sizeof(arr2) / sizeof(int));
    vector<int> input3(arr3, arr3 + sizeof(arr3) / sizeof(int));

    Solution solution;
    output(solution.twoSum(input1, 9));
    output(solution.twoSum(input2, 6));
    output(solution.twoSum(input3, 6));
}