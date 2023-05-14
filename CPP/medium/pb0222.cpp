#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
#222 Count Complete Tree Nodes
Attempt 1: 
Use level order traverse to solve

Complexity: O(N) 

Q: Given the root of a complete binary tree, return the number of the nodes in the tree.
   According to Wikipedia, every level, except possibly the last, 
   is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. 
   It can have between 1 and 2h nodes inclusive at the last level h.
   Design an algorithm that runs in less than O(n) time complexity.
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
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        queue<TreeNode*> treeQue;
        int count = 0;
        treeQue.push(root);
        
        while (!treeQue.empty()) {
            TreeNode* traverse = treeQue.front();
            treeQue.pop();
            count++;
            if (traverse->left != nullptr) treeQue.push(traverse->left);
            if (traverse->right != nullptr) treeQue.push(traverse->right);
        }
        return count;
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
    vector<vector<int>> input{{1,2,3,4,5,6}, {1,2}, {1,2,3,4,5,6,7,8}, {1}, {}};
    Solution solution;

    for (int i = 0; i < input.size(); i++) {
        output(input[i]);
        cout << solution.countNodes(solution.createBT(input[i])) << "\n";
    }
}