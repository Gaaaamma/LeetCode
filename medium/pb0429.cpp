#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
#429 N-ary Tree Level Order Traversal
Attempt 1: 
Use queue to do level order traversal

Complexity: O(N) 

Q: Given an n-ary tree, 
   return the level order traversal of its nodes' values.

   Nary-Tree input serialization is represented in their level order traversal, 
   each group of children is separated by the null value (See examples).
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
    vector<Node*> children;
    Node(int val) : val(val) {}
    Node(int val, vector<Node*> vec) {
        this->val = val;
        this->children = vec;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (root == nullptr) return vector<vector<int>>{};
        vector<vector<int>> result;
        queue<Node*> treeQue;
        treeQue.push(root);

        while (!treeQue.empty()) {
            int queSize = treeQue.size();
            vector<int> tmp;
            for (int i = 0; i < queSize; i++) {
                Node* traverse = treeQue.front();
                for (int j = 0; j < traverse->children.size(); j++) {
                    treeQue.push(traverse->children[j]);
                }
                tmp.push_back(traverse->val);
                treeQue.pop();
            }
            result.push_back(tmp);
        }
        return result;
    }
};

int main(int argc, char* argv[]) {
    return 0;
}