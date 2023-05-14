#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

/*
#106 Construct Binary Tree from Inorder and Postorder Traversal
Attempt 1: 
Use recursive method to solve

Complexity: O(N) 

Q: Given two integer arrays inorder and postorder 
   where inorder is the inorder traversal of a binary tree and 
   postorder is the postorder traversal of the same tree, construct and return the binary tree.
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty() && postorder.empty()) return nullptr;
        TreeNode* root = new TreeNode(postorder.back());

        // Find index of root in inorder to get length of left / right tree
        int rootInorderIndex = 0;
        for (int i = 0; i < inorder.size(); i++) {
            if (inorder[i] == postorder.back()) {
                rootInorderIndex = i;
                break;
            }
        }
        vector<int> leftTreeInorder(inorder.begin(), inorder.begin() + rootInorderIndex);
        vector<int> rightTreeInorder(inorder.begin() + rootInorderIndex + 1, inorder.end());

        vector<int> leftTreePostorder(postorder.begin(), postorder.begin() + leftTreeInorder.size());
        vector<int> rightTreePostorder(postorder.begin() + leftTreePostorder.size(), postorder.end() - 1);

        root->left = buildTree(leftTreeInorder, leftTreePostorder);
        root->right = buildTree(rightTreeInorder, rightTreePostorder);
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
    vector<pair<vector<int>, vector<int>>> input{{{9,3,15,20,7}, {9,15,7,20,3}}, {{-1}, {-1}}};
    Solution solution;
    for (int i = 0; i < input.size(); i++) {
        output(solution.inorderTraversal(solution.buildTree(input[i].first, input[i].second)));
    }
}