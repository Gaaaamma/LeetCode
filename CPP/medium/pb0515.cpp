#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
#515 Find Largest Value in Each Tree Row
Attempt 1: 
Use queue to solve and use a variable max to record the maximum number in the row

Complexity: O(N) 

Q: Given the root of a binary tree, 
   return an array of the largest value in each row of the tree (0-indexed).
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
    vector<int> largestValues(TreeNode* root) {
        if (root == nullptr) return vector<int>{};
        vector<int> result;
        queue<TreeNode*> treeQue;
        treeQue.push(root);

        while (!treeQue.empty()) {
            int queSize = treeQue.size();
            int max = INT_MAX * -1 - 1;
            for (int i = 0; i < queSize; i++) {
                TreeNode* traverse = treeQue.front();
                if (traverse->left != nullptr) treeQue.push(traverse->left);
                if (traverse->right != nullptr) treeQue.push(traverse->right);
                if (traverse->val > max) max = traverse->val;
                treeQue.pop();
            }
            result.push_back(max);
        }

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
    vector<vector<int>> input{{3,9,20,null,7,null,null,null,null,1}, {1}, {0,1,null,3,null,null,null,7}};
    for (int i = 0; i < input.size(); i++) {
        output(solution.largestValues(solution.createBT(input[i])));
    }
}