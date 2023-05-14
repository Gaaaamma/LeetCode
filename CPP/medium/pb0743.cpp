#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <map>
#include <iomanip>
using namespace std;

/*
#732 Network Delay Time
Attempt 1: 
Dijkstra

Q: You are given a network of n nodes, labeled from 1 to n. 
   You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), 
   where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.
   
   We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. 
   If it is impossible for all the n nodes to receive the signal, return -1.
*/
class Solution {
public:
    struct Compare {
        bool operator()(pair<int, int> a, pair<int, int> b){
            return a.second > b.second;
        };
    };
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<bool> visited(n + 1, false);
        vector<int> distance(n + 1, INT_MAX);
        vector<int> predecessor(n + 1, -1);
        
        // {src, {dest, cost}}
        multimap<int, pair<int, int>> mmap;
        for (int i = 0; i < times.size(); i++) {
            mmap.insert({times[i][0], {times[i][1], times[i][2]}});
        }
        
        // nodeId, distance
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
        pq.push({k, 0});
        distance[k] = 0;
        
        while (!pq.empty()) {
            pair<int, int> node = pq.top();
            pq.pop();
            if (visited[node.first]) continue;
            visited[node.first] = true;

            // Relax
            pair<multimap<int, pair<int, int>>::iterator, multimap<int, pair<int, int>>::iterator> range = mmap.equal_range(node.first);
            for (auto it = range.first; it != range.second; it++) {
                if (visited[it->second.first]) continue;
                int nowDistance = distance[node.first] + it->second.second;
                if (nowDistance < distance[it->second.first]) {
                    distance[it->second.first] = nowDistance;
                    predecessor[it->second.first] = node.first;
                    pq.push({it->second.first, nowDistance});
                }
            }
        }

        // Show result
        for (int i = 1; i < visited.size(); i++) {
            if (visited[i] == false) return -1;
        }
        return *max_element(distance.begin() + 1, distance.end());
    }
    template<class T>
    void show(vector<T> input) {
        for (int i = 0; i < input.size(); i++) {
            cout << setw(3) << i;
        }
        cout << "\n";
        for (int i = 0; i < input.size(); i++) {
            cout << setw(3) << input[i];
        }
        cout << "\n";
    }
};

int main(int argc, char* argv[]) {
    Solution solution;
    vector<vector<vector<int>>> input{{{2,1,1},{2,3,1},{3,4,1}}, {{1,2,1}}, {{1,2,1}}};
    vector<pair<int,int>> input2{{4,2}, {2,1}, {2,2}};
    for (int i = 0; i < input.size(); i++) {
        cout << solution.networkDelayTime(input[i], input2[i].first, input2[i].second) << "\n";
    }
}