#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

/*
#543 Diameter of Binary Tree
Attempt 1: 
recursive

Q: Given the root of a binary tree, return the length of the diameter of the tree.
   The diameter of a binary tree is the length of the longest path between any two nodes in a tree. 
   This path may or may not pass through the root.
   The length of a path between two nodes is represented by the number of edges between them.
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
    int maxValue;
    int diameterOfBinaryTree(TreeNode* root) {
        maxValue = 0;
        diameter(root);
        return maxValue;
    }
    pair<int, int> diameter(TreeNode* root) {
        if (root == nullptr || (root->left == nullptr && root->right == nullptr)) return pair<int, int>{0, 0};
        pair<int, int> left = diameter(root->left);
        pair<int, int> right = diameter(root->right);
        if (root->left) {
            left.first += 1;
            left.second += 1;
        }
        if (root->right) {
            right.first += 1;
            right.second += 1;
        }
        maxValue = max(maxValue, max(left.first, left.second) + max(right.first, right.second));
        return pair<int, int>{max(left.first, left.second), max(right.first, right.second)};
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
    vector<vector<int>> input{{1,3,2,5,3,null,9}, {1,3,2,5,null,null,9,6,null,7}, {1,3,2,5}, {1}, {1,2,3,4,5}, {1,2}};
    for (int i = 0; i < input.size(); i++) {
        TreeNode* tree = createBinaryTree(input[i]);
        cout << solution.diameterOfBinaryTree(tree) << "\n";
    }
}