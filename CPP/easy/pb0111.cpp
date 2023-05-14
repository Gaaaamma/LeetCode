#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

/*
#111 Minimum Depth of Binary Tree
Attempt 1: 
Use queue to solve and if there is a node has no child, just return the depth
Complexity: O(N) 

Q: Given a binary tree, find its minimum depth.
   The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
   Note: A leaf is a node with no children.
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
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        int depth = 1;
        queue<TreeNode*> treeQue;
        treeQue.push(root);

        while (!treeQue.empty()) {
            int queSize = treeQue.size();
            for (int i = 0; i < queSize; i++) {
                TreeNode* traverse = treeQue.front();
                if (traverse->left == nullptr && traverse->right == nullptr) return depth;
                if (traverse->left != nullptr) treeQue.push(traverse->left);
                if (traverse->right != nullptr) treeQue.push(traverse->right);
                treeQue.pop();
            }
            depth++;
        }
        return depth;
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
    vector<vector<int>> input{{3,9,20,null,null,15,7}, {1,null,2}, {1}, 
    {0,1,null,3,null,null,null,7,null,null,null,null,null,null,null,15}, {}};

    for (int i = 0; i < input.size(); i++) {
        cout << solution.minDepth(solution.createBT(input[i])) << "\n";
    }
}