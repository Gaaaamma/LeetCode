#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;

/*
#209 MinimumSizeSubarraySum
Attempt 1: 
(Brute force) since no good idea now = O(N^2) => TLE
(Slide window) A kind of two pointers
Fast = the end of subArray => Move to find new element
Slow = the start of subArray => Move when sum is enough and try to remove elements
Complexity: O(N)
*/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int result = INT_MAX;
        int sum = 0;
        for (int slow = 0, fast = 0; fast < nums.size(); fast++) {
            sum += nums[fast];

            while (sum >= target) {
                result = result < fast - slow + 1 ? result : fast - slow + 1;
                sum -= nums[slow];
                slow++;
            }
        }
        return result == INT_MAX ? 0 : result;
    }
};

int main(int argc, char* argv[]){
    int arr1[] = {2,3,1,2,4,3};
    int arr2[] = {1,4,4};
    int arr3[] = {1,1,1,1,1,1,1,1};
    int arr4[] = {5};

    vector<int> input1(arr1, arr1 + sizeof(arr1) / sizeof(int));
    vector<int> input2(arr2, arr2 + sizeof(arr2) / sizeof(int));
    vector<int> input3(arr3, arr3 + sizeof(arr3) / sizeof(int));
    vector<int> input4(arr4, arr4 + sizeof(arr4) / sizeof(int));

    Solution solution;
    cout << solution.minSubArrayLen(7, input1) << "\n";
    cout << solution.minSubArrayLen(4, input2) << "\n";
    cout << solution.minSubArrayLen(11, input3) << "\n";
    cout << solution.minSubArrayLen(2, input4) << "\n";
    cout << solution.minSubArrayLen(6, input4) << "\n";
}