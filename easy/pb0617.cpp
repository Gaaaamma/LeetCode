#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

/*
#617 Merge Two Binary Trees
Attempt 1: 
Use recursive method to solve

Complexity: O(N) 

Q: You are given two binary trees root1 and root2.
   Imagine that when you put one of them to cover the other, 
   some nodes of the two trees are overlapped while the others are not. 
   You need to merge the two trees into a new binary tree. The merge rule is that if two nodes overlap, 
   then sum node values up as the new value of the merged node. 
   Otherwise, the NOT null node will be used as the node of the new tree.

   Return the merged tree.
   Note: The merging process must start from the root nodes of both trees.
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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr) return nullptr;
        if (root1 != nullptr && root2 == nullptr) return root1;
        if (root1 == nullptr && root2 != nullptr) return root2;
        
        TreeNode* root = new TreeNode(root1->val + root2->val);
        root->left = mergeTrees(root1->left, root2->left);
        root->right = mergeTrees(root1->right, root2->right);
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
    vector<pair<vector<int>, vector<int>>> input{{{10, 20, 30}, {1,2}}, {{10, 20, null, 30}, {1, null, 2, null, null, null, 3}}, {{10, 20, 30}, {1}}};
    for (int i = 0; i < input.size(); i++) {
        output(solution.inorderTraversal(solution.mergeTrees(solution.createBT(input[i].first), solution.createBT(input[i].second))));
    }
}