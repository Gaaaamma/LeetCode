#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

/*
#107 Binary Tree Level Order Traversal II
Attempt 1: 
queue to traverse and use queue.size() to check the number of nodes this level
At the end, use reverse to reverse the result vector

Complexity: O(N) 

Q: Given the root of a binary tree, return the bottom-up level order traversal of its nodes' values. 
   (i.e., from left to right, level by level from leaf to root).
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (root == nullptr) return vector<vector<int>>{};
        queue<TreeNode*> treeQue;
        vector<vector<int>> result;
        treeQue.push(root);

        while (!treeQue.empty()) {
            int queSize = treeQue.size();
            vector<int> oneLevel;
            for (int i = 0; i < queSize; i++) {
                TreeNode* traverse = treeQue.front();
                oneLevel.push_back(traverse->val);
                if (traverse->left != nullptr) treeQue.push(traverse->left);
                if (traverse->right != nullptr) treeQue.push(traverse->right);
                treeQue.pop();
            }
            result.push_back(oneLevel);
        }
        // Reverse result;
        reverse(result.begin(), result.end());
        return result;
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
    TreeNode* createBST(vector<int> nums) {
        TreeNode* head = new TreeNode(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            TreeNode* traverse = head;
            TreeNode* tmp = new TreeNode(nums[i]);
            while (traverse != nullptr) {
                if (tmp->val >= traverse->val && traverse->right != nullptr) {
                    traverse = traverse->right;
                } else if (tmp->val >= traverse->val && traverse->right == nullptr) {
                    traverse->right = tmp;
                    break;
                } else if (tmp->val < traverse->val && traverse->left != nullptr) {
                    traverse = traverse->left;
                } else {
                    traverse->left = tmp;
                    break;
                }
            }
        }
        return head;
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
    vector<vector<int>> input{{3,9,20,null,null,15,7}, {1}, {0,1,null,3,null,null,null,7}};
    for (int i = 0; i < input.size(); i++) {
        vector<vector<int>> answer = solution.levelOrderBottom(solution.createBT(input[i]));
        for (int j = 0; j < answer.size(); j++) {
            output(answer[j]);
        }
        cout << "\n";
    }
    
}