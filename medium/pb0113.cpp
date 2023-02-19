#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

/*
#113 Path Sum II
Attempt 1: 
Use postorder traversal (Notation method) to solve

Complexity: O(N) 

Q: Given the root of a binary tree and an integer targetSum, 
   return all root-to-leaf paths where the sum of the node values in the path equals targetSum. 
   Each path should be returned as a list of the node values, not node references.
   A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.
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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return vector<vector<int>>{};
        vector<vector<int>> result;
        vector<int> onePath;
        int sum = 0;
        stack<TreeNode*> treeStack;
        treeStack.push(root);

        while (!treeStack.empty()) {
            TreeNode* traverse = treeStack.top();
            treeStack.pop();
            if (traverse != nullptr) {
                treeStack.push(traverse);
                treeStack.push(nullptr);
                onePath.push_back(traverse->val);
                sum += traverse->val;
                if (traverse->right != nullptr) treeStack.push(traverse->right);
                if (traverse->left != nullptr) treeStack.push(traverse->left);
            } else {
                if (treeStack.top()->left == nullptr && treeStack.top()->right == nullptr && sum == targetSum) {
                    result.push_back(onePath);
                }
                onePath.pop_back();
                sum -= treeStack.top()->val;
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
    vector<pair<vector<int>, int>> input{{{5,4,8,11,null,13,4,7,2,null,null,null,null,5,1}, 22}, {{1,2,3}, 5}, {{1,2}, 0}, {{}, 3}};
    Solution solution;

    for (int i = 0; i < input.size(); i++) {
        vector<vector<int>> result = solution.pathSum(solution.createBT(input[i].first), input[i].second);
        cout << "Testcase " << i + 1 << ":\n";
        for (int j = 0; j < result.size(); j++) {
            output(result[j]);
        }
        cout << "\n";
    }
}