#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

/*
#538 Convert BST to Greater Tree
Attempt 1: 
Use reverse inorder traversal to solve

Complexity: O(N) 

Q: Given the root of a Binary Search Tree (BST), convert it to a Greater Tree such that 
   every key of the original BST is changed to the original key plus the sum of all keys greater than the original key in BST.

   As a reminder, a binary search tree is a tree that satisfies these constraints:
   
     - The left subtree of a node contains only nodes with keys less than the node's key.
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
    TreeNode* convertBST(TreeNode* root) {
        if (root == nullptr) return nullptr;
        stack<TreeNode*> treeStack;
        treeStack.push(root);
        int accumulator = 0;
        while (!treeStack.empty()) {
            TreeNode* traverse = treeStack.top();
            treeStack.pop();
            if (traverse != nullptr) {
                if (traverse->left != nullptr) treeStack.push(traverse->left);
                treeStack.push(traverse);
                treeStack.push(nullptr);
                if (traverse->right != nullptr) treeStack.push(traverse->right);
            } else {
                int tmp = treeStack.top()->val;
                treeStack.top()->val += accumulator;
                accumulator += tmp;
                treeStack.pop();
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
    vector<vector<int>> input{{4,2,7,1,3}, {8,2,6,9,7,1,3,10}, {5,2,6,7}};
    
    for (int i = 0; i < input.size(); i++) {
        output(solution.inorderTraversal(solution.convertBST(solution.createBST(input[i]))));
    }
}