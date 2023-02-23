#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

/*
#108 Convert Sorted Array to Binary Search Tree
Attempt 1: 
Use recursive method to solve
Complexity: O(N) 

Q: Given an integer array nums where the elements are sorted in ascending order, 
   convert it to a height-balanced binary search tree.
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) return nullptr;
        int mid = nums.size() / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        vector<int> left(nums.begin(), nums.begin() + mid);
        vector<int> right(nums.begin() + mid + 1, nums.end());
        root->left = sortedArrayToBST(left);
        root->right = sortedArrayToBST(right);
        return root;
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
    vector<vector<int>> input{{4,2,7,1,3}, {2,6,4,1,7,8}, {9,1,4,7,2,5}};
    for (int i = 0; i < input.size(); i++) {
        sort(input[i].begin(), input[i].end());
        output(solution.inorderTraversal(solution.sortedArrayToBST(input[i])));
    }
}