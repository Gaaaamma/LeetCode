#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;

/*
#128 Longest Consecutive Sequence
Attempt 1: 
unordered_set

Q: Given an unsorted array of integers nums, 
   return the length of the longest consecutive elements sequence.
   You must write an algorithm that runs in O(n) time.
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int result = 0;
        unordered_set<int> uoset(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (uoset.count(nums[i] - 1)) continue;
            int round = 0;
            int judge = nums[i];
            while (uoset.count(judge)) {
                judge++;
                round++;
            }
            result = max(result, round);
        }
        return result;
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
template<class T>
void show2DGraph(const vector<vector<T>>& input) {
    for (int i = 0; i < input.size(); i++) {
        show1D(input[i]);
    }
}

int main(int argc, char* argv[]) {
    Solution solution;
    vector<vector<int>> input{{1,5,3,6,1,2}, {4,4,3,10,16,20,19,1,18,17}, {100,4,200,1,3,2}, {0,3,7,2,5,8,4,6,0,1}};
    for (int i = 0; i < input.size(); i++) {
        cout << solution.longestConsecutive(input[i]) << "\n";
    }
}