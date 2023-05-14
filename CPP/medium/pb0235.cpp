#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

/*
#235 Lowest Common Ancestor of a Binary Tree
Attempt 1: 
Use 

Complexity: O(N) 

Q: Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

   According to the definition of LCA on Wikipedia: “The lowest common ancestor 
   is defined between two nodes p and q as the lowest node in T that has both p and q as descendants 
   (where we allow a node to be a descendant of itself).”
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
        if (root == nullptr) return nullptr;
        else if (root->val < p->val && root->val > q->val) return root;
        else if (root->val > p->val && root->val < q->val) return root;
        else if (root == p || root == q) return root;
        else if (root->val < p->val && root->val < q->val) return lowestCommonAncestor(root->right, p, q);
        else return lowestCommonAncestor(root->left, p, q);
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
    vector<vector<int>> input{{5,3,7,2,4,6,8}};
    for (int i = 0; i < input.size(); i++) {
        TreeNode* root = solution.createBT(input[i]);
        cout << solution.lowestCommonAncestor(root, root->left, root->left->left)->val << "\n";
    }
}