#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
#144 Binary Tree Preorder Traversal
Attempt 1: 
Use recursive way to solve

Attempt 2:
Use iterative way to solve

Complexity: O(N) if only output the value

Q: Given the root of a binary tree, 
   return the preorder traversal of its nodes' values.
*/     


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
    vector<int> preorderTraversal(TreeNode* head) {
        if (head == nullptr) {
            return vector<int>{};
        }
        vector<int> result;
        vector<int> left = preorderTraversal(head->left);
        vector<int> right = preorderTraversal(head->right);
        result.push_back(head->val);
        result.insert(result.end(), left.begin(), left.end());
        result.insert(result.end(), right.begin(), right.end());       
        return result;
    }
    
    vector<int> preorderTraversalIter(TreeNode* head) {
        vector<int> result;
        if (head == nullptr) return vector<int>{};
        stack<TreeNode*> treeStack;
        treeStack.push(head);

        // DLR
        while (!treeStack.empty()) {
            TreeNode* top = treeStack.top();
            treeStack.pop();
            result.push_back(top->val);
            
            if (top->right != nullptr) treeStack.push(top->right);
            if (top->left != nullptr) treeStack.push(top->left);
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
};

int main(int argc, char* argv[]) {
    vector<vector<int>> input{{5,2,1,6,3,4,9,7,8,10}, {1}, {5,6,2,7,5,3,7,1,9,2}};
    Solution solution;
    for (int i = 0; i < input.size(); i++) {
        cout << "Preorder:\n";
        output(solution.preorderTraversal(solution.createBST(input[i])));
        output(solution.preorderTraversalIter(solution.createBST(input[i])));
        cout << "\n";
    }
}