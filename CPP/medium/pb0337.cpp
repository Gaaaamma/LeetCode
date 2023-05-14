#include <iostream>
#include <vector>
#include <stack>
#include <numeric>
#include <queue>
using namespace std;

/*
#337 House Robber III
Attempt 1: 
Use DP to solve

Q: The thief has found himself a new place for his thievery again. 
   There is only one entrance to this area, called root.

   Besides the root, each house has one and only one parent house. 
   After a tour, the smart thief realized that all houses in this place form a binary tree. 
   It will automatically contact the police if two directly-linked houses were broken into on the same night.
   
   Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police.

*/
const int null = INT_MAX;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {};
};

class Solution {
public:
    int rob(TreeNode* root) {
        vector<int> result = robTree(root);
        return max(result[0], result[1]);
    }
    vector<int> robTree(TreeNode* cur) {
        // {no_steal, steal}
        if (cur == nullptr) return vector<int>(2,0);
        vector<int> result(2,0);
        vector<int> left = robTree(cur->left);
        vector<int> right = robTree(cur->right);
        
        int leftMax = max(left[0], left[1]);
        int rightMax = max(right[0], right[1]);
        result[0] = leftMax + rightMax;
        result[1] = left[0] + right[0] + cur->val;
        return result;
    }
    TreeNode* createBT(vector<int> nums) {
        if (nums.empty() || nums[0] == null) return nullptr;
        int index = 0;
        TreeNode* root = new TreeNode(nums[0]);
        queue<TreeNode*> treeQueue;
        treeQueue.push(root);

        while (!treeQueue.empty()) {
            if (nums[index] == null) {
                index++;
                if (index >= nums.size())
                    break;
                continue;
            }

            TreeNode* traverse = treeQueue.front();
            if (index * 2 + 1 < nums.size() && nums[index * 2 + 1] != null) {
                traverse->left = new TreeNode(nums[index * 2 + 1]);
                treeQueue.push(traverse->left);
            }
            if (index * 2 + 2 < nums.size() && nums[index * 2 + 2] != null) {
                traverse->right = new TreeNode(nums[index * 2 + 2]);
                treeQueue.push(traverse->right);
            }
            treeQueue.pop();
            index++;
        }
        return root;
    }
};

int main(int argc, char* argv[]) {
    Solution solution;
    vector<vector<int>> input{{2,2,3,4}, {2,7,9,3,1}};
    for (int i = 0; i < input.size(); i++) {
        cout << solution.rob(solution.createBT(input[i])) << "\n";
    }
}