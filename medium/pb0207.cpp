#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

/*
#207 Course Schedule
Attempt 1: 
AOV (Activity of Vertex)

Q: There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
   You are given an array prerequisites where prerequisites[i] = [ai, bi] 
   indicates that you must take course bi first if you want to take course ai.

   For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
   Return true if you can finish all courses. Otherwise, return false.
*/
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> matrix(numCourses, vector<int>(numCourses, 0));
        vector<int> indegree(numCourses, 0);
        for (int i = 0; i < prerequisites.size(); i++) {
            matrix[prerequisites[i][1]][prerequisites[i][0]] = 1;
            indegree[prerequisites[i][0]]++;
        }

        queue<int> handle;
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) handle.push(i);
        }

        unordered_set<int> used;
        while (!handle.empty()) {
            used.insert(handle.front());
            for (int j = 0; j < numCourses; j++) {
                if (matrix[handle.front()][j] == 1) {
                    matrix[handle.front()][j] = 0;
                    indegree[j]--;
                    if (indegree[j] == 0) handle.push(j);
                }
            }
            handle.pop();
        }
        if (used.size() == numCourses) return true;
        return false;
    }
    
};
int main(int argc, char* argv[]) {
    Solution solution;
    vector<pair<int, vector<vector<int>>>> input{{2, {{1,0}, {0,1}}}, {2, {{1,0}}}};
    for (int i = 0; i < input.size(); i++) {
        cout << solution.canFinish(input[i].first, input[i].second) << "\n";
    }
}