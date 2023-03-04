#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
#406 Queue Reconstruction by Height
Attempt 1: 
sort the people by order and continuously insert to solve

Complexity: O(NlogN + N^2) 

Q: You are given an array of people, people, 
   which are the attributes of some people in a queue (not necessarily in order). 
   Each people[i] = [hi, ki] represents the ith person of height hi with exactly ki 
   other people in front who have a height greater than or equal to hi.

   Reconstruct and return the queue that is represented by the input array people. 
   The returned queue should be formatted as an array queue, 
   where queue[j] = [hj, kj] is the attributes of the jth person in the queue 
   (queue[0] is the person at the front of the queue).
*/     
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> result;
        sort(people.begin(), people.end(), [](vector<int> a, vector<int> b){return a[1] < b[1];});
        for (int i = 0; i < people.size(); i++) {
            int index = 0;
            int taller = 0;
            for (index = 0; index < result.size(); index++) {
                if (people[i][0] > result[index][0]) {
                    continue;
                } else if (taller < people[i][1]) {
                    taller++;
                    continue;
                } else {
                    break;
                }
            }
            result.insert(result.begin() + index, people[i]);
        }
        return result; 
    }
};

void output(vector<vector<int>> result) {
    if (result.empty()) {
        cout << "[]\n";
        return;
    }
    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << "[";
        for (int j = 0; j < result[i].size() -1; j++) {
            cout << result[i][j] << ", ";
        }
        cout << result[i].back() << "]";
    }
    cout << "]\n";
}
int main(int argc, char* argv[]) {
    Solution solution;
    vector<vector<vector<int>>> input{{{7,0}, {4,4}, {7,1}, {5,0}, {6,1}, {5,2}}, {{100,0}, {99,1}, {2,2}, {70,2}, {1,2}, {3,2}, {5,2}, {80,2}}};
    for (int i = 0; i < input.size(); i++) {
        output(solution.reconstructQueue(input[i]));
    }
}