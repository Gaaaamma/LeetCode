#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

/*
#230 Kth Smallest Element in BST
Attempt 1: 
Inorder traversal

Q: Given the root of a binary search tree, and an integer k, 
   return the kth smallest value (1-indexed) of all the values of the nodes in the tree.
*/
const int null = INT_MAX;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {};
};
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        // Inorder
        vector<int> result;
        inorder(root, result);
        return result[k - 1];
    }
    void inorder(TreeNode* root, vector<int>& result) {
        if (root == nullptr) return;
        if (root->left) inorder(root->left, result);
        result.push_back(root->val);
        if (root->right) inorder(root->right, result);
    }
};

TreeNode* createTree(vector<int>& input) {
    TreeNode* head = new TreeNode(input[0]);
    queue<TreeNode*> que;
    que.push(head);
    for (int i = 1; i < input.size(); i += 2) {
        TreeNode* traverse = que.front();
        que.pop();
        if (input[i] != null) {
            traverse->left = new TreeNode(input[i]);
            que.push(traverse->left);
        }
        if (i + 1 < input.size() && input[i + 1] != null) {
            traverse->right = new TreeNode(input[i + 1]);
            que.push(traverse->right);
        }
    }
    return head;
}

int main(int argc, char* argv[]) {
    Solution solution;
    vector<pair<vector<int>, int>> input{{{3,1,4,null,2}, 1}, {{5,3,6,2,4,null,null,1}, 3}};
    for (int i = 0; i < input.size(); i++) {
        cout << solution.kthSmallest(createTree(input[i].first), input[i].second) << "\n";
    }
}