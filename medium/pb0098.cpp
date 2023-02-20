#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

/*
#98 Validate Binary Search Tree
Attempt 1: 
Use inorder traversal (Notation method) to solve

Complexity: O(N) 

Q: Given the root of a binary tree, determine if it is a valid binary search tree (BST).
   A valid BST is defined as follows:
   - The left subtreeof a node contains only nodes with keys less than the node's key.
   - The right subtree of a node contains only nodes with keys greater than the node's key.
   - Both the left and right subtrees must also be binary search trees.
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
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;
        vector<int> inorder = inorderTraversal(root);
        for (int i = 1; i < inorder.size(); i++) {
            if (inorder[i] <= inorder[i - 1])
                return false;
        }
        return true;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr) return vector<int>{};
        vector<int> result;
        stack<TreeNode*> treeStack;
        treeStack.push(root);
        while (!treeStack.empty()) {
            TreeNode* traverse = treeStack.top();
            treeStack.pop();
            if (traverse != nullptr) {
                if (traverse->right != nullptr) treeStack.push(traverse->right);
                treeStack.push(traverse);
                treeStack.push(nullptr);
                if (traverse->left != nullptr) treeStack.push(traverse->left);
            } else if (traverse == nullptr) {
                result.push_back(treeStack.top()->val);
                treeStack.pop();
            }
        }
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
    vector<vector<int>> input{{3,2,1,6,0,5}, {3,2,1}, {2,1,3}, {1}, {5,3,7,2,4,6,8}};
    for (int i = 0; i < input.size(); i++) {
        cout << solution.isValidBST(solution.createBT(input[i])) << "\n";
    }
}