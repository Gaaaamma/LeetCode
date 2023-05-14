#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
#55 Jump Game
Attempt 1: 
Use greedy to solve

Complexity: O(N) 

Q: You are given an integer array nums. 
   You are initially positioned at the array's first index, and each 
   element in the array represents your maximum jump length at that position.

   Return true if you can reach the last index, or false otherwise.
*/     
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int cover = 0;
        int count = 0;
        queue<pair<int, int>> que;
        que.push({0, nums[0]});

        while (!que.empty() && cover < nums.size() - 1) {
            int queSize = que.size();
            for (int i = 0; i < queSize; i++) {
                int newCover = que.front().first + que.front().second;
                if (newCover >= nums.size() - 1) {
                    cover = newCover;
                    break;
                }
                if (newCover > cover) {
                    for (int k = cover + 1; k <= newCover; k++) {
                        que.push({k, nums[k]});
                    }
                    cover = newCover;
                }
                que.pop();
            }
            count++;
        }
        return count;
    }
};


int main(int argc, char* argv[]) {
    Solution solution;
    vector<vector<int>> input{{2,3,1,1,4}, {2,3,1,0,10}, {6,0,2,3,1,0,10}, {2,0,4,5,0,0,0,1,1,4}, {0}};
    for (int i = 0; i < input.size(); i++) {
        cout << solution.jump(input[i]) << "\n";
    }   
}