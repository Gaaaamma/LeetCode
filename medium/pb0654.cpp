#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

/*
#654 Maximum Binary Tree
Attempt 1: 
Use recursive method to solve

Complexity: O(N) 

Q: You are given an integer array nums with no duplicates. 
   A maximum binary tree can be built recursively from nums using the following algorithm:

   Create a root node whose value is the maximum value in nums.
   Recursively build the left subtree on the subarray prefix to the left of the maximum value.
   Recursively build the right subtree on the subarray suffix to the right of the maximum value.
   Return the maximum binary tree built from nums.
*/     
const int null = INT_MAX;
void output(vector<int> nums) {
    if (nums.empty()) {
        cout << "[]\n";
    } else {
        cout << "[";
        for (int i = 0; i < nums.size() - 1; i++) {
            cout << nums[i] << ", " ;
        }
        cout <<nums.back() << "]\n";
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.empty()) return nullptr;
        if (nums.size() == 1) return new TreeNode(nums.front());

        int maxIndex = 0;
        int maxValue = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > maxValue) {
                maxIndex = i;
                maxValue = nums[i];
            }
        }
        TreeNode* root = new TreeNode(nums[maxIndex]);
        vector<int> left(nums.begin(), nums.begin() + maxIndex);
        vector<int> right(nums.begin() + maxIndex + 1, nums.end());
        root->left = constructMaximumBinaryTree(left);
        root->right = constructMaximumBinaryTree(right);
        return root;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr) return vector<int>{};
        vector<int> result;
        vector<int> left = inorderTraversal(root->left);
        vector<int> right = inorderTraversal(root->right);
        result.insert(result.end(), left.begin(), left.end());
        result.push_back(root->val);
        result.insert(result.end(), right.begin(), right.end());
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
    vector<vector<int>> input{{3,2,1,6,0,5}, {3,2,1}, {1,2,3}, {1}};
    for (int i = 0; i < input.size(); i++) {
        output(solution.inorderTraversal(solution.constructMaximumBinaryTree(input[i])));
    }
}