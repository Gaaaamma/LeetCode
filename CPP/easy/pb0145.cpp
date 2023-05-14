#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
using namespace std;

/*
#145 Binary Tree Postorder Traversal
Attempt 1: 
Use recursive way to solve

Attempt 2:
Use iterative way to solve (stack + unordered_set to check if had traversed)

Complexity: O(N) if only output the value

Q: Given the root of a binary tree, 
   return the postorder traversal of its nodes' values.
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
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == nullptr) return vector<int>{};
        vector<int> result;
        vector<int> left = postorderTraversal(root->left);
        vector<int> right = postorderTraversal(root->right);
        result.insert(result.end(), left.begin(), left.end());
        result.insert(result.end(), right.begin(), right.end());
        result.push_back(root->val);
        return result;
    }
    
    vector<int> postorderTraversalIter(TreeNode* root) {
        if (root == nullptr) return vector<int>{};
        vector<int> result;
        stack<TreeNode*> treeStack;
        unordered_set<TreeNode*> traversed;
        treeStack.push(root);

        // LRD
        while (!treeStack.empty()) {
            TreeNode* traverse = treeStack.top();
            if (traverse->left != nullptr && !traversed.count(traverse->left)) {
                traverse = traverse->left;
                treeStack.push(traverse);
            } else if (traverse->right != nullptr && !traversed.count(traverse->right)) {
                traverse = traverse->right;
                treeStack.push(traverse);
            } else {
                result.push_back(traverse->val);
                traversed.insert(treeStack.top());
                treeStack.pop();
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
        cout << "Postorder:\n";
        output(solution.postorderTraversal(solution.createBST(input[i])));
        output(solution.postorderTraversalIter(solution.createBST(input[i])));
    }
}