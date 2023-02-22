#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

/*
#701 Insert into a Binary Search Tree
Attempt 1: 
Simply traverse the Binary Search Tree to find where to insert the node

Complexity: O(N) 

Q: You are given the root node of a binary search tree (BST) 
   and a value to insert into the tree. Return the root node of the BST after the insertion. 
   It is guaranteed that the new value does not exist in the original BST.
   
   Notice that there may exist multiple valid ways for the insertion, 
   as long as the tree remains a BST after insertion. You can return any of them.
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) return new TreeNode(val);
        TreeNode* traverse = root;
        while (true) {
            if (traverse->val > val) {
                if (traverse->left == nullptr) {
                    traverse->left = new TreeNode(val);
                    break;
                } else {
                    traverse = traverse->left;
                }
            }else if (traverse->val < val) {
                if (traverse->right == nullptr) {
                    traverse->right = new TreeNode(val);
                    break;
                } else {
                    traverse = traverse->right;
                }
            }
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
    vector<pair<vector<int>, int>> input{{{4,2,7,1,3}, 6}, {{4,2,7,1,3}, 5}};
    for (int i = 0; i < input.size(); i++) {
        output(solution.inorderTraversal(solution.insertIntoBST(solution.createBST(input[i].first), input[i].second)));
    }
}