#include <iostream>
#include <vector>
#include <unordered_map>
#include <iomanip>
using namespace std;

/*
#1431 Kids With the Greatest Number of Candies
Attempt 1: 
Simulation

Q: There are n kids with candies. You are given an integer array candies, where each candies[i] 
   represents the number of candies the ith kid has, and an integer extraCandies, 
   denoting the number of extra candies that you have.

   Return a boolean array result of length n, where result[i] is true if, 
   after giving the ith kid all the extraCandies, they will have 
   the greatest number of candies among all the kids, or false otherwise.
   
   Note that multiple kids can have the greatest number of candies.
*/

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max = 0;
        for (int i = 0; i < candies.size(); i++) {
            if (candies[i] > max) max = candies[i];
        }

        vector<bool> result(candies.size(), false);
        for (int i = 0; i < candies.size(); i++) {
            if (candies[i] + extraCandies >= max) result[i] = true;
        }
        return result;
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
    vector<pair<vector<int>, int>> input{{{2,3,5,1,3},3}, {{4,2,1,1,2},1}};
    for (int i = 0; i < input.size(); i++) {
        show1D(solution.kidsWithCandies(input[i].first, input[i].second));
    }
}
