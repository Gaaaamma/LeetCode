#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

/*
#257 Binary Tree Paths
Attempt 1: 
Use posrorder traverse (Notation method) with string pattern to solve
Complexity: O(N) 

Q: Given the root of a binary tree, return all root-to-leaf paths in any order.
   A leaf is a node with no children.
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
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == nullptr) return vector<string>{};
        if (root->left == nullptr && root->right == nullptr) return vector<string>{to_string(root->val)};
        vector<string> result;
        vector<string> pattern;
        stack<TreeNode*> treeStack;
        treeStack.push(root);

        while (!treeStack.empty()) {
            TreeNode* traverse = treeStack.top();
            if (traverse != nullptr) {
                treeStack.pop();
                treeStack.push(traverse);
                treeStack.push(nullptr);
                if (traverse->right != nullptr) treeStack.push(traverse->right);
                if (traverse->left != nullptr) treeStack.push(traverse->left);
                pattern.push_back(to_string(traverse->val) + "->");
            } else {
                treeStack.pop();
                // Check if leaf or not
                if (treeStack.top()->left == nullptr && treeStack.top()->right == nullptr) {
                    // leaf
                    string onePath = "";
                    for (int i = 0; i < pattern.size(); i++) {
                        onePath += pattern[i];
                    }
                    result.push_back(onePath.substr(0, onePath.size() - 2));
                }
                treeStack.pop();
                // Remove pattern
                pattern.pop_back();
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
    vector<vector<int>> input{{3,9,20,null,null,15,7}, {1,2,2,3,3,null,null,4,4}, {}, {1}, {1,2,null,3}, {1,2}};
    Solution solution;

    for (int i = 0; i < input.size(); i++) {
        output(solution.binaryTreePaths(solution.createBT(input[i])));
    }
}