#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

/*
#513 Find Bottom Left Tree Value
Attempt 1: 
Use level order traversal to solve
Complexity: O(N) 

Q: Given the root of a binary tree, 
return the leftmost value in the last row of the tree.
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
    int findBottomLeftValue(TreeNode* root) {
        if (root == nullptr) return 0;
        queue<TreeNode*> treeQue;
        treeQue.push(root);
        vector<int> levelVal;

        while (!treeQue.empty()) {
            levelVal.clear();
            int queSize = treeQue.size();
            for (int i = 0; i < queSize; i++) {
                TreeNode* traverse = treeQue.front();
                if (traverse->left != nullptr) treeQue.push(traverse->left);
                if (traverse->right != nullptr) treeQue.push(traverse->right);
                levelVal.push_back(traverse->val);
                treeQue.pop();
            }
        }

        return levelVal.front();
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
        cout << solution.findBottomLeftValue(solution.createBT(input[i])) << "\n";
    }
}