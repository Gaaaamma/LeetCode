#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

/*
#105 Construct Binary Tree from Preorder and Inorder Traversal
Attempt 1: 
Use recursive method to solve

Complexity: O(N) 

Q: Given two integer arrays preorder and inorder 
   where preorder is the preorder traversal of a binary tree 
   and inorder is the inorder traversal of the same tree, construct and return the binary tree.
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() && inorder.empty()) return nullptr;
        TreeNode* root = new TreeNode(preorder.front());

        // Find index of root in inorder
        int rootInorderIndex = 0;
        for (rootInorderIndex = 0; rootInorderIndex < inorder.size(); rootInorderIndex++) {
            if (inorder[rootInorderIndex] == preorder.front()) 
                break;
        }
        vector<int> leftInorder(inorder.begin(), inorder.begin() + rootInorderIndex);
        vector<int> rightInorder(inorder.begin() + rootInorderIndex + 1, inorder.end());

        vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + 1 + leftInorder.size());
        vector<int> rightPreorder(preorder.begin() + 1 + leftPreorder.size(), preorder.end());

        root->left = buildTree(leftPreorder, leftInorder);
        root->right = buildTree(rightPreorder, rightInorder);
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
    vector<pair<vector<int>, vector<int>>> input{{{3,9,20,15,7}, {9,3,15,20,7}}, {{-1}, {-1}}};
    Solution solution;
    for (int i = 0; i < input.size(); i++) {
        output(solution.inorderTraversal(solution.buildTree(input[i].first, input[i].second)));
    }
}