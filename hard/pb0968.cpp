#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

/*
#968 Binary Tree Cameras
Attempt 1: 
Use greedy / postorder to solve

Complexity: O(-)

Q: You are given the root of a binary tree. 
   We install cameras on the tree nodes where each camera at a node can monitor its parent, itself, and its immediate children.
   Return the minimum number of cameras needed to monitor all nodes of the tree.
*/
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {};
};

const int null = INT_MAX;
class Solution {
public:
    int minCameraCover(TreeNode* root) {
        // postorder
        if (root == nullptr) return 0;
        if (root->left == nullptr && root->right == nullptr) return 1;
        stack<TreeNode*> treeStack;
        treeStack.push(root);
        
        int count = 0;
        while (!treeStack.empty()) {
            TreeNode* traverse = treeStack.top();
            treeStack.pop();
            if (traverse != nullptr) {
                treeStack.push(traverse);
                treeStack.push(nullptr);
                if (traverse->right) treeStack.push(traverse->right);
                if (traverse->left) treeStack.push(traverse->left);
            } else {
                TreeNode* cur = treeStack.top();
                treeStack.pop();
                if (cur->left == nullptr && cur->right == nullptr) {
                    // Leaf do nothing
                    continue;
                }
                int leftVal = -1;
                int rightVal = -1;
                if (cur->left != nullptr) {
                    leftVal  = cur->left->val;
                    cur->left->val = 0;
                } 
                if (cur->right != nullptr) {
                    rightVal = cur->right->val;
                    cur->right->val = 0;
                } 
                if (leftVal == 0 || rightVal == 0) {
                    cur->val = 2;
                    count++;
                } else if (leftVal == 2 || rightVal == 2) {
                    cur->val = 1;
                } else if (leftVal == 1 || rightVal == 1) {
                    continue;
                }
            }
        }
        // Handle root
        if (root->val == 0) {
            count++;
        }
        root->val = 0;
        return count;
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
    vector<vector<int>> input{{0,0,0,0,0}, {0,0,null,0,0}};
    for (int i = 0; i < input.size(); i++) {
        cout << solution.minCameraCover(solution.createBT(input[i])) << "\n";
    }
}