#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
#110 Balanced Binary Tree
Attempt 1: 
Use recursive way to solve

Complexity: O(N) 

Q: Given a binary tree, determine if it is  height-balanced.
   A height-balanced tree is a Binary Tree 
   that the depth of the two subtrees of every node never differs more than one)
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
        cout << nums.back() << "]\n";
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
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;
        int leftDepth = 0;
        int rightDepth = 0;
        if (!balanceDepth(root->left, leftDepth)) return false;
        if (!balanceDepth(root->right, rightDepth)) return false;
        if (abs(leftDepth - rightDepth) > 1) return false;
        return true;
    }

    bool balanceDepth(TreeNode* root, int& depth) {
        if (root == nullptr) {
            depth = 0;
            return true;
        }
        int leftDepth = 0;
        int rightDepth = 0;
        if (!balanceDepth(root->left, leftDepth)) return false;
        if (!balanceDepth(root->right, rightDepth)) return false;
        if (abs(leftDepth - rightDepth) > 1) return false;
        depth = (leftDepth > rightDepth) ? leftDepth + 1 : rightDepth + 1;
        return true;
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
    vector<vector<int>> input{{3,9,20,null,null,15,7}, {1,2,2,3,3,null,null,4,4}, {}, {1}, {1,2,null,3}, {1,2}};
    Solution solution;

    for (int i = 0; i < input.size(); i++) {
        output(input[i]);
        cout << solution.isBalanced(solution.createBT(input[i])) << "\n";
    }
}