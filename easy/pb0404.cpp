#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

/*
#404 Sum of Left Leaves
Attempt 1: 
Use recursive method to solve

Complexity: O(N) 

Q: Given the root of a binary tree, return the sum of all left leaves.
   A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.
*/     
const int null = INT_MAX;
void output(vector<string> nums) {
    if (nums.empty()) {
        cout << "[]\n";
    } else {
        cout << "[";
        for (int i = 0; i < nums.size() - 1; i++) {
            cout << "\"" << nums[i] << "\", " ;
        }
        cout << "\""  <<nums.back() << "\"]\n";
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
    int sumOfLeftLeaves(TreeNode* root) {
        int result = 0;
        if (root == nullptr || (root->left == nullptr && root->right == nullptr)) return 0;
        if (root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr) 
            result += root->left->val;
        result += sumOfLeftLeaves(root->left);
        result += sumOfLeftLeaves(root->right);
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
    vector<vector<int>> input{{3,9,20,null,null,15,7}, {1}, {1,1,null,1,1}};
    Solution solution;

    for (int i = 0; i < input.size(); i++) {
        cout << solution.sumOfLeftLeaves(solution.createBT(input[i])) << "\n";
    }
}