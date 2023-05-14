#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
using namespace std;

/*
#94 Binary Tree Inorder Traversal
Attempt 1: 
Use recursive way to solve

Attempt 2:
Use iterative way to solve

Complexity: O(N) if only output the value

Q: Given the root of a binary tree, 
   return the inorder traversal of its nodes' values.
*/     

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
    
    vector<int> inorderTraversalIter(TreeNode* root) {
        if (root == nullptr) return vector<int>{};
        vector<int> result;
        stack<TreeNode*> treeStack;
        unordered_set<TreeNode*> traversed;
        treeStack.push(root);

        while (!treeStack.empty()) {
            TreeNode* traverse = treeStack.top();
            if (traverse->left != nullptr && !traversed.count(traverse->left)) {
                traverse = traverse->left;
                treeStack.push(traverse);
                continue;
            }
            result.push_back(traverse->val);
            traversed.insert(traverse);
            treeStack.pop();
            if (traverse->right != nullptr && !traversed.count(traverse->right)) {
                traverse = traverse->right;
                treeStack.push(traverse);
            }
        }
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
};

int main(int argc, char* argv[]) {
    vector<vector<int>> input{{5,2,1,6,3,4,9,7,8,10}, {1}, {5,6,2,7,5,3,7,1,9,2}};
    Solution solution;
    for (int i = 0; i < input.size(); i++) {
        cout << "Inorder:\n";
        output(solution.inorderTraversal(solution.createBST(input[i])));
        output(solution.inorderTraversalIter(solution.createBST(input[i])));
    }
}