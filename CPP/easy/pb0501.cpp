#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <queue>
using namespace std;

/*
#501 Find Mode in Binary Search Tree
Attempt 1: 
Use inorder traverse to traverse the tree and use unordered_map to record the frequency

Complexity: O(N) 

Q: Given the root of a binary search tree (BST) with duplicates, 
   return all the mode(s) (i.e., the most frequently occurred element) in it.
   If the tree has more than one mode, return them in any order.

   Assume a BST is defined as follows:
   - The left subtree of a node contains only nodes with keys less than or equal to the node's key.
   - The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
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
    vector<int> findMode(TreeNode* root) {
        if (root->left == nullptr && root->right ==nullptr) return vector<int>{root->val};
        vector<int> result;
        unordered_map<int, int> uomap;
        stack<TreeNode*> treeStack;
        treeStack.push(root);

        while (!treeStack.empty()) {
            TreeNode* traverse = treeStack.top();
            treeStack.pop();
            if (traverse != nullptr) {
                if (traverse->right != nullptr) treeStack.push(traverse->right);
                treeStack.push(traverse);
                treeStack.push(nullptr);
                if (traverse->left != nullptr) treeStack.push(traverse->left);
            } else {
                uomap[treeStack.top()->val]++;
                treeStack.pop();
            }
        }
        
        // Find mode
        int maxNum = 0;
        for (unordered_map<int, int>::iterator it = uomap.begin(); it != uomap.end(); it++) {
            if (it->second > maxNum) {
                result.clear();
                result.push_back(it->first);
                maxNum = it->second;
            } else if (it->second == maxNum) {
                result.push_back(it->first);
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
    vector<vector<int>> input{{1,2,2}, {5,2,7,9,0,10,3,10,2,5}, {10,1,3,7,15,20,3,1,25}};
    for (int i = 0; i < input.size(); i++) {
        output(solution.findMode(solution.createBST(input[i])));
    }
}