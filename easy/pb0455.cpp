#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

/*
#455 Assign Cookies
Attempt 1: 
Use greedy to solve

Complexity: O(N) 

Q: Assume you are an awesome parent and want to give your children some cookies. 
   But, you should give each child at most one cookie.

   Each child i has a greed factor g[i], which is the minimum size of a cookie 
   that the child will be content with; and each cookie j has a size s[j]. 
   If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content. 
   Your goal is to maximize the number of your content children and output the maximum number.
*/     

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if (s.empty()) return 0;
        int result = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int gIndex = 0;
        int sIndex = 0;
        while (gIndex != g.size() && sIndex != s.size()) {
            if (s[sIndex] >= g[gIndex]) {
                result++;
                sIndex++;
                gIndex++;
            } else {
                sIndex++;
            }
        }
        return result;
    }
};
int main(int argc, char* argv[]) {
    Solution solution;
    vector<pair<vector<int>, vector<int>>> input{{{3,4,5}, {2,6}}, {{1,2,3}, {2,3,4,5}}, {{3,4,5,6,7,8}, {1,2,4,6,9}}};
    for (int i = 0; i < input.size(); i++) {
        cout << solution.findContentChildren(input[i].first, input[i].second) << "\n"; 
    }
}