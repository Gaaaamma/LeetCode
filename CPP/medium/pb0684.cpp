#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
using namespace std;

/*
#684 Redundant Connection
Attempt 1: 
Disjoint set

Q: In this problem, a tree is an undirected graph that is connected and has no cycles.
   You are given a graph that started as a tree with n nodes labeled from 1 to n, 
   with one additional edge added. The added edge has two different vertices chosen from 1 to n, 
   and was not an edge that already existed. 
   
   The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that 
   there is an edge between nodes ai and bi in the graph.
   
   Return an edge that can be removed so that the resulting graph is a tree of n nodes. 
   If there are multiple answers, return the answer that occurs last in the input.
*/

class Disjoint {
private:
    vector<int> set;
public:
    Disjoint(int counts) {
        set = vector<int>(counts, -1);
    }
    int find(int index) {
        int traverse = index;
        vector<int> compression;
        while (set[traverse] >= 0) {
            compression.push_back(traverse);
            traverse = set[traverse];
        }
        for (int i = 0; i < compression.size(); i++) {
            set[compression[i]] = traverse;
        }
        return traverse;
    }
    void makeUnion(int indexA, int indexB) {
        int rootA = find(indexA);
        int rootB = find(indexB);
        if (set[rootA] <= set[rootB]) {
            set[rootA] += set[rootB];
            set[rootB] = rootA;
        } else {
            set[rootB] += set[rootA];
            set[rootA] = rootB;
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        Disjoint* dj = new Disjoint(1001);
        for (int i = 0; i < edges.size(); i++) {
            if (dj->find(edges[i][0]) == dj->find(edges[i][1])) return edges[i];
            else dj->makeUnion(edges[i][0], edges[i][1]);
        }
        return vector<int>();
    }
};

void show(const vector<int>& nums) {
    if (nums.empty()) {
        cout << "[]\n";
        return;
    }
    cout << "[";
    for (int i = 0; i < nums.size() - 1; i++) {
        cout << nums[i] << ",";
    }
    cout << nums.back() << "]\n";
}
int main(int argc, char* argv[]) {
    Solution solution;
    vector<vector<vector<int>>> input{{{1,2}, {2,3}, {1,3}}, {{1,2}, {2,3}, {3,4}, {1,4}, {1,5}}};
    for (int i = 0; i < input.size(); i++) {
        show(solution.findRedundantConnection(input[i]));
    }
}