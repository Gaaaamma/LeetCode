#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;

/*
#27 RemoveElement
Attempt 2: 
Use the concept of left-right pointer to implement 
Complexity: O(N)
*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            if (nums[right] == val) {
                right--;
                continue;
            }
            if (nums[left] == val) {
                swap(nums[left], nums[right]);
            }
            left++;
        }
        return left;
    }
};

int main(int argc, char* argv[]){
    int arr1[] = {3,2,2,3};
    int val1 = 3;
    int arr2[] = {0,1,2,2,3,0,4,2};
    int val2 = 2;
    int arr3[] = {1,2};
    int val3 = 2;

    vector<int> input1(arr1, arr1 + sizeof(arr1) / sizeof(int));
    vector<int> input2(arr2, arr2 + sizeof(arr2) / sizeof(int));
    vector<int> input3(arr3, arr3 + sizeof(arr3) / sizeof(int));

    Solution solution;
    cout << solution.removeElement(input1, val1) << "\n";
    cout << solution.removeElement(input2, val2) << "\n";
    cout << solution.removeElement(input3, val3) << "\n";
}