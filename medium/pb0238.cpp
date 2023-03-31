#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
using namespace std;

/*
#238 Product of Array Except Self
Attempt 1: 
Prefix & Suffix

Q: Given an integer array nums, return an array answer such that 
   answer[i] is equal to the product of all the elements of nums except nums[i].
   The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
   You must write an algorithm that runs in O(n) time and without using the division operation.
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size(), 1);
        vector<int> suffix(nums.size(), 1);
        int product = 1;
        for (int i = 0; i < nums.size(); i++) {
            product *= nums[i];
            prefix[i] = product;
        }
        product = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            product *= nums[i];
            suffix[i] = product;
        }
        nums[0] = suffix[1];
        nums[nums.size() - 1] = prefix[nums.size() - 2];
        for (int i = 1; i < nums.size() - 1; i++) {
            nums[i] = prefix[i - 1] * suffix[i + 1];
        }
        return nums;
    }
};
void show(const vector<int>& nums) {
    if (nums.empty()) {
        cout << "[]\n";
        return;
    }
    cout << "[";
    for (int i = 0; i < nums.size() - 1; i++) {
        cout << nums[i] << ",";
    }
    cout << nums.back() << "]\n";
}
int main(int argc, char* argv[]) {
    Solution solution;
    vector<vector<int>> input{{1,2,3,4,5}, {1,2}, {-1,1,9,0,-1,1}};
    for (int i = 0; i < input.size(); i++) {
        show(solution.productExceptSelf(input[i]));
    }
}