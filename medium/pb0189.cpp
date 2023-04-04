#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

/*
#189 Rotate Array
Attempt 1: 
gcd

Q: Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
*/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        if (k == 0) return;
        
        int counts = gcd(nums.size(), k);
        int process = nums.size() / counts;
        for (int i = nums.size() - 1; i > nums.size() - 1 - counts; i--) {
            int round = 0;
            int finalNum = nums[i];
            int index = i;
            while (round != process - 1) {
                int pre = index - k;
                if (pre < 0) pre += nums.size();
                nums[index] = nums[pre];
                index = pre;
                round++;
            }
            nums[index] = finalNum;
        }
    }
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
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
    vector<pair<vector<int>, int>> input{{{1,2,3,4,5,6,7,8}, 1}, {{1,2,3,4,5,6,7,8}, 2}, {{1,2,3,4,5,6,7,8}, 3}, {{1,2,3,4,5,6,7,8}, 12}, {{1,2,3,4,5,6,7,8}, 13}, {{1,2,3,4,5,6,7,8}, 14}, {{1,2,3,4,5,6,7,8}, 15}, {{1,2,3,4,5,6,7,8}, 16}};
    for (int i = 0; i < input.size(); i++) {
        show1D(input[i].first);
        solution.rotate(input[i].first, input[i].second);
        show1D(input[i].first);
        cout << "\n";
    }
}