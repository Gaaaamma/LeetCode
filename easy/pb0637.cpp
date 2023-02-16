#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
#637 Average of Levels in Binary Tree
Attempt 1: 
Use queue to solve and 

Complexity: O(N) 

Q: Given the root of a binary tree, 
   return the average value of the nodes on each level in the form of an array. 
   Answers within 10-5 of the actual answer will be accepted.
*/     

const int null = INT_MAX;
void output(vector<double> nums) {
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
    vector<double> averageOfLevels(TreeNode* root) {
        if (root == nullptr) return vector<double>{};
        vector<double> result;
        queue<TreeNode*> treeQue;
        treeQue.push(root);

        while (!treeQue.empty()) {
            int queSize = treeQue.size();
            double sum = 0.0;
            for (int i = 0; i < queSize; i++) {
                TreeNode* traverse = treeQue.front();
                if (traverse->left != nullptr) treeQue.push(traverse->left);
                if (traverse->right != nullptr) treeQue.push(traverse->right);
                sum += traverse->val;
                treeQue.pop();
            }
            result.push_back(sum / queSize);
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
        output(solution.averageOfLevels(solution.createBT(input[i])));
    }
}