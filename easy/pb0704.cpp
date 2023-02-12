#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;

/*
#704 BinarySearch
Attempt 2: 
[first, last)
Complexity: O(logN)
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] > target) right = mid;
            else if (nums[mid] < target) left = mid + 1;
            else return mid;
        }
        return -1;
    }
};

int main(int argc, char* argv[]){
    int arr1[] = {-1,0,3,5,9,12};
    int target1 = 9;
    int arr2[] = {-1,0,3,5,9,12};
    int target2 = 2;

    vector<int> input1(arr1, arr1 + sizeof(arr1) / sizeof(int));
    vector<int> input2(arr2, arr2 + sizeof(arr2) / sizeof(int));

    Solution solution;
    cout << solution.search(input1, target1) << "\n";
    cout << solution.search(input2, target2) << "\n";
}