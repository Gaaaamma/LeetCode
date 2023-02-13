#include <iostream>
#include <vector>
#include <deque>
using namespace std;

/*
#239 Sliding Window Maximum 
Attempt 1: 
Use deque to solve (Create a decreasing queue)

Complexity: O(N)

Q: You are given an array of integers nums, 
   there is a sliding window of size k which is moving from the very left of the array to the very right. 
   You can only see the k numbers in the window. Each time the sliding window moves right by one position.
   Return the max sliding window.
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> solve;
        int left = 0;
        int right = 0;

        for (right = 0; right < k; right++) {
            while (!solve.empty()) {
                if (solve.back() < nums[right])
                    solve.pop_back();
                else 
                    break;
            }
            solve.push_back(nums[right]);
        }
        result.push_back(solve.front());

        // Loop through the nums vec
        for (; right < nums.size(); right++, left++) {
            if (nums[left] == solve.front())
                solve.pop_front();

            while (!solve.empty()) {
                if (solve.back() < nums[right])
                    solve.pop_back();
                else 
                    break;
            }
            solve.push_back(nums[right]);
            result.push_back(solve.front());
        }

        return result;
    }
};

void output(vector<int> nums) {
    if (nums.empty()) {
        cout << "[]";
    } else {
        cout << "[";
        for (int i = 0; i < nums.size() - 1; i++) {
            cout << nums[i] << ", ";
        }
        cout << nums[nums.size() - 1] << "]";
    }
}

int main(int argc, char* argv[]) {
    vector<pair<vector<int>, int>> input{{{1,3,-1,-3,5,3,6,7}, 3}, {{1}, 1}, {{-7,-8,7,5,7,1,6,0}, 4}};
    Solution solution;

    for (int i = 0; i < input.size(); i++) {
        output(input[i].first);
        cout << " = ";
        output(solution.maxSlidingWindow(input[i].first, input[i].second));
        cout << "\n";
    }
}