#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

/*
#102 Binary Tree Level Order Traversal
Attempt 1: 
Use queue and knowledge of tree to solve 
(upperBound means how many node should check at this level)

Complexity: O(N) if only output the value

Q: Given the root of a binary tree, 
   return the level order traversal of its nodes' values. (i.e., from left to right, level by level).
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return vector<vector<int>>{};
        vector<vector<int>> result;
        vector<int> tmp;
        result.push_back(vector<int>{root->val});
        
        queue<TreeNode*> treeQue;
        treeQue.push(root);
        int upperBound = 2;
        int count = 0; 

        while (!treeQue.empty()) {
            TreeNode* traverse = treeQue.front();
            if (traverse->left != nullptr) {
                treeQue.push(traverse->left);
                tmp.push_back(traverse->left->val);
            }
            count++;
            if (traverse->right != nullptr) {
                treeQue.push(traverse->right);
                tmp.push_back(traverse->right->val);
            }
            count ++;

            if (count == upperBound) {
                if (!tmp.empty())
                    result.push_back(tmp);
                count = 0;
                upperBound = tmp.size() * 2;
                tmp.clear();
            }
            treeQue.pop();
        }
        return result;
    }
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
    vector<vector<int>> input{{3,9,20,null,null,15,7}, {1}, {0,1,null,3,null,null,null,7}};
    for (int i = 0; i < input.size(); i++) {
        vector<vector<int>> answer = solution.levelOrder(solution.createBT(input[i]));
        for (int j = 0; j < answer.size(); j++) {
            output(answer[j]);
        }
        cout << "\n";
    }
    
}