#include <iostream>
#include <vector>
#include <stack>
#include <numeric>
#include <queue>
using namespace std;

/*
#11 Container With Most Water
Attempt 1: 
Use Two pointer to solve

Q: You are given an integer array height of length n. 
   There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

   Find two lines that together with the x-axis form a container, such that the container contains the most water.
   Return the maximum amount of water a container can store.
   Notice that you may not slant the container.
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int volumn = 0;
        while (left < right) {
            volumn = max(volumn, (right - left) * min(height[left], height[right]));
            if (height[left] < height[right]) left++;
            else right--;
        }
        return volumn;
    }
};
int main(int argc, char* argv[]) {
    Solution solution;
    vector<vector<int>> input{{1,8,6,2,5,4,8,3,7}, {1,1}};
    for (int i = 0; i < input.size(); i++) {
        cout << solution.maxArea(input[i]) << "\n";
    }
}