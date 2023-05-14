#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
#134 Gas Station
Attempt 1: 
Use greedy to solve

Complexity: O(N) 

Q: There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].
   You have a car with an unlimited gas tank and it costs cost[i] of gas to 
   travel from the ith station to its next (i + 1)th station. 
   You begin the journey with an empty tank at one of the gas stations.

   Given two integer arrays gas and cost, return the starting gas station's index 
   if you can travel around the circuit once in the clockwise direction, 
   otherwise return -1. If there exists a solution, it is guaranteed to be unique
*/     
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> diff(gas.size(), 0);
        for (int i = 0; i < gas.size(); i++) {
            diff[i] = gas[i] - cost[i];
        }

        int sum = 0;
        int startIndex = 0;
        for (int i = 0; i < diff.size(); i++) {
            sum += diff[i];
            if (sum < 0) {
                sum = 0;
                startIndex = i + 1;
            }
        }
        if (startIndex == gas.size()) return -1;
        for (int i = 0; i < startIndex; i++) {
            sum += diff[i];
        }
        if (sum < 0) return -1;
        return startIndex;
    }
};


int main(int argc, char* argv[]) {
    Solution solution;
    vector<pair<vector<int>, vector<int>>> input{{{1,2,3,4,5}, {3,4,5,1,2}}, {{2,3,4}, {3,4,3}}, {{3,1,1}, {1,2,2}}};
    for (int i = 0; i < input.size(); i++) {
        cout << solution.canCompleteCircuit(input[i].first, input[i].second) << "\n";
    }   
}