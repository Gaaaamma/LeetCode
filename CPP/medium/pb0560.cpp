#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

/*
#560 Subarray Sum Equals K
Attempt 1: 
Prefix sum

Q: Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
   A subarray is a contiguous non-empty sequence of elements within an array.
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> uomap;
        int sum = 0;
        int counter = 0;
        uomap[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            counter += uomap[sum - k];
            uomap[sum]++;
        }
        return counter;
    }
    // [i, j] = prefix[j] - prefix[i - 1] == k
    // prefix[j] - k == prefix[i - 1]
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
    vector<pair<vector<int>, int>> input{{{1,1,1},2}, {{1,2,3},3}};
    for (int i = 0; i < input.size(); i++) {
        cout << solution.subarraySum(input[i].first, input[i].second) << "\n";
    }
}