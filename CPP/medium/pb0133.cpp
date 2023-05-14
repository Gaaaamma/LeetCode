#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

/*
#133 Clone Graph
Attempt 1: 
BFS and unordered_map

Q: Given a reference of a node in a connected undirected graph.
   
   Return a deep copy (clone) of the graph.
   Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.
   
   class Node {
       public int val;
       public List<Node> neighbors;
   }
   
   Test case format:
   For simplicity, each node's value is the same as the node's index (1-indexed). 
   For example, the first node with val == 1, the second node with val == 2, and so on. 
   The graph is represented in the test case using an adjacency list.
   
   An adjacency list is a collection of unordered lists used to represent a finite graph. 
   Each list describes the set of neighbors of a node in the graph.
   
   The given node will always be the first node with val = 1. 
   You must return the copy of the given node as a reference to the cloned graph.
*/
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() : val(0) {};
    Node(int val) : val(val) {};
    Node(int val, vector<Node*> neighbors) : val(val), neighbors(neighbors) {};
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;
        if (node->neighbors.empty()) return new Node(node->val);

        unordered_map<int, Node*> solve;
        solve[node->val] = new Node(node->val);

        vector<bool> visited(101, false);
        queue<Node*> que;
        que.push(node);
        visited[node->val] = true;

        while (!que.empty()) {
            Node* traverse = que.front();
            que.pop();
            
            for (Node* nei : traverse->neighbors) {
                // Add to solve
                if (solve.count(nei->val) == 0) {
                    solve[nei->val] = new Node(nei->val);
                }
                solve[traverse->val]->neighbors.push_back(solve[nei->val]);

                // Push to que
                if (visited[nei->val]) continue;
                visited[nei->val] = true;
                que.push(nei);
            }
        }
        return solve[node->val];
    }
};

Node* createGraph(vector<pair<int, int>>& adj) {
    if (adj.empty()) return nullptr;
    sort(adj.begin(), adj.end(), [](pair<int, int> a, pair<int, int> b){
        return (a.first == b.first) ? a.second < b.second : a.first < b.first;
    });

    unordered_map<int, Node*> solve;
    for (pair<int, int> edge : adj) {
        if (!solve.count(edge.first)) solve[edge.first] = new Node(edge.first);
        if (!solve.count(edge.second)) solve[edge.second] = new Node(edge.second);
        solve[edge.first]->neighbors.push_back(solve[edge.second]);
        solve[edge.second]->neighbors.push_back(solve[edge.first]);
    } 
    return solve[adj.front().first];
}
void show(Node* root) {
    if (root == nullptr) {
        cout << "[]\n";
        return;
    }
    
    vector<bool> visited(101, false);
    queue<Node*> que;
    que.push(root);
    while (!que.empty()) {
        Node* traverse = que.front();
        que.pop();
        visited[traverse->val] = true;
        
        for (Node* dest : traverse->neighbors) {
            cout << "[" << traverse->val << "->" << dest->val << "]\n";
            if (visited[dest->val]) continue;
            que.push(dest);
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
    vector<vector<pair<int , int>>> input{{{1,2}, {1,4}, {2,3}, {3,4}}};
    for (int i = 0; i < input.size(); i++) {
        Node* graph = createGraph(input[i]);
        cout << "Original:\n";
        show(graph);
        cout << "\n";

        Node* clone = solution.cloneGraph(graph);
        cout << "Clone:\n";
        show(clone);
        cout << "\n";
    }
}