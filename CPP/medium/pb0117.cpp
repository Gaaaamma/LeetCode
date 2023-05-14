#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
#117 Populating Next Right Pointers in Each Node II
Attempt 1: 
queue to solve
Complexity: O(N) 

Q: Given a Binary Tree
   struct Node {
       int val;
       Node *left;
       Node *right;
       Node *next;
   }
   Populate each next pointer to point to its next right node. 
   If there is no next right node, the next pointer should be set to NULL.
   Initially, all next pointers are set to NULL.
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

struct Node {
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node(int val) : val(val), left(nullptr), right(nullptr), next(nullptr) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) return nullptr;
        queue<Node*> treeQue;
        treeQue.push(root);

        while (!treeQue.empty()) {
            int queSize = treeQue.size();
            for (int i = 0; i < queSize; i++) {
                Node* traverse = treeQue.front();
                if (traverse->left != nullptr) treeQue.push(traverse->left);
                if (traverse->right != nullptr) treeQue.push(traverse->right);
                treeQue.pop();
                if (i != queSize - 1) {
                    traverse->next = treeQue.front();
                } else {
                    traverse->next = nullptr;
                }
            }
        }

        return root;
    }
};

int main(int argc, char* argv[]) {
    return 0;
}