#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

/*
#450 Delete Node in a BST
Attempt 1: 
Use recursive method to solve

Complexity: O(N) 

Q: Given a root node reference of a BST and a key, 
   delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

   Basically, the deletion can be divided into two stages:
   Search for a node to remove.
   If the node is found, delete the node.
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return nullptr;
        if (root->val == key && root->left == nullptr && root->right == nullptr) return nullptr;

        if (root->val < key) {
            root->right = deleteNode(root->right, key);
        } else if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } else if (root->val == key && root->left != nullptr && root->right == nullptr) {
            return root->left;
        } else if (root->val == key && root->left == nullptr && root->right != nullptr) {
            return root->right;
        } else {
            // Find replace
            TreeNode* parent = root;
            TreeNode* traverse = root->right;
            bool in = false;
            while (traverse->left != nullptr) {
                parent = traverse;
                traverse = traverse->left;
                in = true;
            }
            traverse->left = root->left;
            if (in) {
                parent->left = traverse->right;
                traverse->right =root->right;
            } 
            return traverse;
        }
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
    vector<pair<vector<int>, int>> input{{{4,2,7,1,3}, 2}, {{4,2,7,1,3}, 4}};
    for (int i = 0; i < input.size(); i++) {
        output(solution.inorderTraversal(solution.deleteNode(solution.createBST(input[i].first), input[i].second)));
    }
}