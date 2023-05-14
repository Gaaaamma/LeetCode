#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

/*
#100 Same Tree
Attempt 1: 
Use recursive way to compare two tree
Complexity: O(N) 

Q: Given the roots of two binary trees p and q, write a function to check if they are the same or not.
   Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;
        if ((p == nullptr && q !=nullptr) || (p != nullptr && q ==nullptr)) return false;
        if (!isSameTree(p->left, q->left)) return false;
        if (!isSameTree(p->right, q->right)) return false;
        if (p->val != q->val) return false;
        return true;
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
    vector<pair<vector<int>, vector<int>>> input{{{1,2,3}, {1,2,3}}, {{1,2}, {1,null,2}}, {{1,2,1}, {1,1,2}}};
    Solution solution;

    for (int i = 0; i < input.size(); i++) {
        cout << solution.isSameTree(solution.createBT(input[i].first), solution.createBT(input[i].second)) << "\n";
    }
}