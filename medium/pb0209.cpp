#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;

/*
#27 MinimumSizeSubarraySum
Attempt 1: 
(Brute force) since no good idea now = O(N^2) => TLE
Complexity: O()
*/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        for (int i = 1; i <= nums.size(); i++) {
            int slide = groupSum(i, 0, nums);
            
            if (slide >= target) {
                return i;
            }

            // Rowing the slide
            int front = 0;
            for (int j = i; j < nums.size(); j++) {
                slide += nums[j];
                slide -= nums[front];

                if (slide >= target) {
                    return i;
                } else {
                    front ++;
                }
            }
        }
        return 0;
    }

    int groupSum(int scope, int start, vector<int>& nums) {
        int result = 0;
        for (int i = start; i < start + scope; i++) {
            result += nums[i];
        }
        return result;
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