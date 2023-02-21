#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

/*
#236 Lowest Common Ancestor of a Binary Tree
Attempt 1: 
Find the path to the two nodes, and compare to path to find their lowest ancestor

Complexity: O(N) 

Q: Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
   According to the definition of LCA on Wikipedia: 
   “The lowest common ancestor is defined between two nodes p and q as the 
   lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == p || root == q) return root;
        vector<TreeNode*> pPath = postorderPath(root, p);
        vector<TreeNode*> qPath = postorderPath(root, q);
        
        if (pPath.size() > qPath.size()) 
            swap(pPath, qPath);

        for (int i = 0; i < pPath.size(); i++) {
            if (pPath[i] != qPath[i])
                return pPath[i - 1];
        }
        return pPath.back();
    } 
    vector<TreeNode*> postorderPath(TreeNode* root, TreeNode* target) {
        if (root == nullptr) return vector<TreeNode*>{};
        vector<TreeNode*> result;
        stack<TreeNode*> treeStack;
        treeStack.push(root);

        while (!treeStack.empty()) {
            TreeNode* traverse = treeStack.top();
            treeStack.pop();
            if (traverse != nullptr) {
                treeStack.push(traverse);
                result.push_back(treeStack.top());
                treeStack.push(nullptr);
                if (traverse->right != nullptr) treeStack.push(traverse->right);
                if (traverse->left != nullptr) treeStack.push(traverse->left); 
            } else {
                if (treeStack.top() == target)
                    return result;
                result.pop_back();
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
    vector<vector<int>> input{{3,2,1,6,0,5}, {3,2,1,4}, {2,1,3,8}, {1,6,4,7,1}, {5,3,7,2,4,6,8}};
    for (int i = 0; i < input.size(); i++) {
        TreeNode* root = solution.createBT(input[i]);
        cout << solution.lowestCommonAncestor(root, root->left, root->left->left)->val << "\n";
    }
}