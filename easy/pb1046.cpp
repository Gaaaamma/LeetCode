#include <iostream>
#include <vector>
#include <unordered_map>
#include <iomanip>
#include <queue>
using namespace std;

/*
#1046 Last Stone Weight
Attempt 1: 
Heap (priority_queue)

Q: You are given an array of integers stones where stones[i] is the weight of the ith stone.
   We are playing a game with the stones. On each turn, we choose the heaviest two stones and smash them together. 
   Suppose the heaviest two stones have weights x and y with x <= y. The result of this smash is:
   
   - If x == y, both stones are destroyed, and
   - If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
   
   At the end of the game, there is at most one stone left.
   Return the weight of the last remaining stone. If there are no stones left, return 0.
*/

struct Compare {
    bool operator()(int a, int b){
        return a < b;
    }
};

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>, Compare> pq(stones.begin(), stones.end());
        while (pq.size() >= 2) {
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();
            
            if (first - second) pq.push(first - second);
        }
        return (pq.empty() == true) ? 0 : pq.top();
    }
};

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
    vector<vector<int>> input{{2,7,4,1,8,1}, {1}, {4,2,4,1,6,2,7,13,2}};
    for (int i = 0; i < input.size(); i++) {
        cout << solution.lastStoneWeight(input[i]) << "\n";
    }
}
