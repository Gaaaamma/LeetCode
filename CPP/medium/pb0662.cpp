#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

/*
#662 Maximum Width of Binary Tree
Attempt 1: 
level order traversal

Q: Given the root of a binary tree, return the maximum width of the given tree.

   The maximum width of a tree is the maximum width among all levels.
   
   The width of one level is defined as the length between the end-nodes 
   (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes 
   that would be present in a complete binary tree extending down to that level are also counted into the length calculation.
   
   It is guaranteed that the answer will in the range of a 32-bit signed integer.
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
    int widthOfBinaryTree(TreeNode* root) {
        int result = 1;
        queue<pair<TreeNode*, long long>> que;
        que.push({root, 0});
        while (!que.empty()) {
            int queSize = que.size();
            long long base = 0;
            int left = INT_MAX;
            int right = 0;
            for (int i = 0; i < queSize; i++) {
                pair<TreeNode*, long long> judge = que.front();
                que.pop();
                if (judge.first->left) {
                    if (base == 0) base = judge.second * 2 + 1;
                    que.push({judge.first->left, judge.second * 2 + 1 - base});
                    left = (judge.second * 2 + 1 - base < left) ? judge.second * 2 + 1 - base : left;
                    right = (judge.second * 2 + 1 - base > right) ? judge.second * 2 + 1 - base : right;
                }
                if (judge.first->right) {
                    if (base == 0) base = judge.second * 2 + 2;
                    que.push({judge.first->right, judge.second * 2 + 2 - base});
                    left = (judge.second * 2 + 2 - base < left) ? judge.second * 2 + 2 - base : left;
                    right = (judge.second * 2 + 2 - base > right) ? judge.second * 2 + 2 - base : right;
                }
            }
            result = max(result, right - left + 1);
        }
        return result;
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
    vector<vector<int>> input{{1,3,2,5,3,null,9}, {1,3,2,5,null,null,9,6,null,7}, {1,3,2,5}, {1}};
    for (int i = 0; i < input.size(); i++) {
        TreeNode* tree = createBinaryTree(input[i]);
        cout << solution.widthOfBinaryTree(tree) << "\n";
    }
}