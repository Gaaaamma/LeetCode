#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

/*
#101 Symmetric Tree
Attempt 1: 
Invert root->right tree and you inorder to compare left and right side tree
Complexity: O(N) 

Q: Given the root of a binary tree, 
   check whether it is a mirror of itself (i.e., symmetric around its center).
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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return false;;
        if (root->left == nullptr && root->right ==nullptr) return true;

        root->right = invertTree(root->right);
        vector<int> left = inorderTraversal(root->left);
        vector<int> right = inorderTraversal(root->right);
        if (left.size() != right.size()) return false;
        for (int i = 0; i < left.size(); i++) {
            if (left[i] != right[i])
                return false;
        }
        return true;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr) return vector<int>{null};
        vector<int> result;
        stack<TreeNode*> treeStack;
        treeStack.push(root);
        while (!treeStack.empty()) {
            TreeNode* traverse = treeStack.top();
            if (traverse != nullptr) {
                treeStack.pop();
                if (traverse->right != nullptr) treeStack.push(traverse->right);
                else result.push_back(null);
                treeStack.push(traverse);
                treeStack.push(nullptr);
                if (traverse->left != nullptr) treeStack.push(traverse->left);
                else result.push_back(null);
            } else {
                treeStack.pop();
                result.push_back(treeStack.top()->val);
                treeStack.pop();
            }
        }
        return result;
    }
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return nullptr;
        TreeNode* left= invertTree(root->left);
        TreeNode* right= invertTree(root->right);
        root->left = right;
        root->right = left;
        return root;
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
    vector<vector<int>> input{{1,2,2,2,null,2}};

    for (int i = 0; i < input.size(); i++) {
        cout << solution.isSymmetric(solution.createBT(input[i])) << "\n"; 
    }
}