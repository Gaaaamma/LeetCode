#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

/*
#530 Minimum Absolute Difference in BST
Attempt 1: 
Use inorder traverse result to solve (Since it is Binary Search Tree)

Complexity: O(N) 

Q: Given the root of a Binary Search Tree (BST), 
   return the minimum absolute difference between the values of any two different nodes in the tree.
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
    int getMinimumDifference(TreeNode* root) {
        if (root == nullptr) return -1;
        vector<int> inorder = inorderTraversal(root);

        int minDiff = INT_MAX;
        for (int i = 1; i < inorder.size(); i++) {
            if (abs(inorder[i] - inorder[i - 1]) < minDiff)
                minDiff = abs(inorder[i] - inorder[i - 1]);
        }

        return minDiff; 
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
            } else {
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
    TreeNode* createBST(vector<int> nums) {
        if (nums.empty()) return nullptr;
        TreeNode* root = new TreeNode(nums.front());
        for (int i = 1; i < nums.size(); i++) {
            TreeNode* traverse = root;
            while (true) {
                if (nums[i] >= traverse->val) {
                    if (traverse->right != nullptr) {
                        traverse = traverse->right;
                    } else {
                        traverse->right = new TreeNode(nums[i]);
                        break;
                    }
                } else {
                    if (traverse->left != nullptr) {
                        traverse = traverse->left;
                    } else {
                        traverse->left = new TreeNode(nums[i]);
                        break;
                    }
                }
            }
        }
        return root;
    }
};

int main(int argc, char* argv[]) {
    Solution solution;
    vector<vector<int>> input{{1,2}, {5,2,7,9,0,10,3}, {10,1,3,7,15,20}};
    for (int i = 0; i < input.size(); i++) {
        cout << solution.getMinimumDifference(solution.createBST(input[i])) << "\n";
    }
}