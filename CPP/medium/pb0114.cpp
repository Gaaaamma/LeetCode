#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

/*
#114 Flatten Binary Tree to Linked List
Attempt 1: 
recursive

Q: Given the root of a binary tree, flatten the tree into a "linked list":

   - The "linked list" should use the same TreeNode class where the right child pointer points to the next node 
     in the list and the left child pointer is always null.

   - The "linked list" should be in the same order as a pre-order traversal of the binary tree.
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
    void flatten(TreeNode* root) {
        if (root == nullptr || (root->left == nullptr && root->right == nullptr)) return;
        flatten(root->left);
        flatten(root->right);
        if (root->left == nullptr) return;
        TreeNode* last = findLast(root->left);
        TreeNode* tmp = root->right;
        root->right = root->left;
        root->left = nullptr;
        last->right = tmp;
    }
    TreeNode* findLast(TreeNode* root) {
        TreeNode* traverse = root;
        while (traverse->right != nullptr) traverse = traverse->right;
        return traverse;
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
    vector<vector<int>> input{{1,2,5,3,4,null,6}, {1,2,4,3,null,null,5}, {1,2,4,null,3,null,5}};
    for (int i = 0; i < input.size(); i++) {
        TreeNode* tree = createBinaryTree(input[i]);
        cout << "Original: ";
        showBTInorder(tree);
        solution.flatten(tree);
        cout << "Flatten:  ";
        showBTInorder(tree);
        cout << "\n";
    }
}