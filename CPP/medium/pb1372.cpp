#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

/*
#1372 Longest ZigZag Path in a Binary Tree
Attempt 1: 
recursive

Q: You are given the root of a binary tree.
   A ZigZag path for a binary tree is defined as follow:
   
   - Choose any node in the binary tree and a direction (right or left).
   - If the current direction is right, move to the right child of the current node; otherwise, move to the left child.
   - Change the direction from right to left or from left to right.
   - Repeat the second and third steps until you can't move in the tree.
   
   Zigzag length is defined as the number of nodes visited - 1. (A single node has a length of 0).
   Return the longest ZigZag path contained in that tree.
*/

const int null = INT_MIN;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {};
    TreeNode(int val, TreeNode* left, TreeNode* right) : val(val), left(left), right(right) {};
};

class Solution {
public:
    int maxCount;
    int longestZigZag(TreeNode* root) {
        maxCount = 0;
        zigCount(root);
        return maxCount;
    }
    pair<int, int> zigCount(TreeNode* root) {
        if (root == nullptr) return pair<int, int>{-1, -1};
        if (root->left == nullptr && root->right == nullptr) return pair<int, int>{0, 0};

        int left = 0;
        int right = 0;
        if (root->left) left = zigCount(root->left).second + 1;
        if (root->right) right = zigCount(root->right).first + 1;
        maxCount = max(maxCount, left);
        maxCount = max(maxCount, right);
        return pair<int, int>{left, right};
    }
};

TreeNode* createBinaryTree(const vector<int>& input) {
    if (input.empty()) return nullptr;
    queue<TreeNode*> que;
    TreeNode* root = new TreeNode(input.front());
    que.push(root);

    for (int i = 1; i < input.size(); i += 2) {
        TreeNode* cur = que.front();
        que.pop();
        if (input[i] != null) {
            cur->left = new TreeNode(input[i]);
            que.push(cur->left);
        }
        if (i + 1 < input.size() && input[i + 1] != null) {
            cur->right = new TreeNode(input[i + 1]);
            que.push(cur->right);
        }
    }
    return root;
}
void showBTInorder(TreeNode* root) {
    if (root == nullptr) {
        cout << "[]\n";
        return;
    }
    cout << "[";
    stack<TreeNode*> st;
    st.push(root);
    while (!st.empty()) {
        TreeNode* cur = st.top();
        st.pop();
        if (cur != nullptr) {
            if (cur->right) st.push(cur->right);
            st.push(cur);
            st.push(nullptr);
            if (cur->left) st.push(cur->left);
        } else {
            cout << st.top()->val;
            st.pop();
            if (st.empty()) cout << "]\n";
            else cout << ",";
        }
    }
}
template<class T>
void show1D(const vector<T>& input) {
    if (input.empty()) {
        cout << "[]\n";
        return;
    }
    cout << "[";
    for (int i = 0; i < input.size() - 1; i++) {
        cout << input[i] << ",";
    }
    cout << input.back() << "]\n";
}
template<class T>
void show2DGraph(const vector<vector<T>>& input) {
    for (int i = 0; i < input.size(); i++) {
        show1D(input[i]);
    }
}

int main(int argc, char* argv[]) {
    Solution solution;
    vector<vector<int>> input{{1,null,1,1,1,null,null,1,1,null,1,null,null,null,1,null,1}, {1,1,1,null,1,null,null,1,1,null,1}, {1}};
    for (int i = 0; i < input.size(); i++) {
        TreeNode* tree = createBinaryTree(input[i]);
        cout << solution.longestZigZag(tree) << "\n";
    }
}