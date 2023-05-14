#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

/*
#112 Path Sum
Attempt 1: 
Use postorder traversal (Notation method) to solve

Complexity: O(N) 

Q: Given the root of a binary tree and an integer targetSum, 
   return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.
   A leaf is a node with no children.
*/     
const int null = INT_MAX;
void output(vector<string> nums) {
    if (nums.empty()) {
        cout << "[]\n";
    } else {
        cout << "[";
        for (int i = 0; i < nums.size() - 1; i++) {
            cout << "\"" << nums[i] << "\", " ;
        }
        cout << "\""  <<nums.back() << "\"]\n";
    }
}

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;
        stack<TreeNode*> treeStack;
        int sum = 0;
        treeStack.push(root);

        // Postorder
        while (!treeStack.empty()) {
            TreeNode* traverse = treeStack.top();
            if (traverse != nullptr) {
                treeStack.pop();
                treeStack.push(traverse);
                treeStack.push(nullptr);
                sum += traverse->val;
                if (traverse->right != nullptr) treeStack.push(traverse->right);
                if (traverse->left != nullptr) treeStack.push(traverse->left);
            } else {
                treeStack.pop();
                if (treeStack.top()->left == nullptr && treeStack.top()->right == nullptr) {
                    // Leaf
                    if (sum == targetSum) return true;
                }
                sum -= treeStack.top()->val;
                treeStack.pop();
            }
        }
        return false;
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
    vector<pair<vector<int>, int>> input{{{5,4,8,11,null,13,4,7,2,null,null,null,1}, 22}, {{1,2,3}, 5}, {{}, 3}};
    Solution solution;

    for (int i = 0; i < input.size(); i++) {
        cout << solution.hasPathSum(solution.createBT(input[i].first), input[i].second) << "\n";
    }
}