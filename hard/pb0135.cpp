#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
#135 Candies
Attempt 1: 
use priority_queue to solve

Complexity: O(-)

Q: There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.

   You are giving candies to these children subjected to the following requirements:
   
   Each child must have at least one candy.
   Children with a higher rating get more candies than their neighbors.
   Return the minimum number of candies you need to have to distribute the candies to the children.
*/

class Solution {
public:
    struct Compare {
        bool operator()(pair<int, int> a, pair<int, int> b) {
            return a.second > b.second;
        };
    };
    int candy(vector<int>& ratings) {
        // [4,3,2,1,2,3]
        //  1 1 1 1 1 1
        //  1 1 1   1 1
        //  1 1       1
        //  1
        // [1,0,1,1,2,2,4,3,3,4,4,4,0,2,5,3,2]
        //  1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 = 17
        //. 1   1   1   1     1   1   1 1 1
        //                              1
        vector<int> candies(ratings.size(), 1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> priQue;
        for (int i = 0; i < ratings.size(); i++) {
            priQue.push({i, ratings[i]});
        }

        while (!priQue.empty()) {
            int index = priQue.top().first;
            int front = index - 1;
            int back = index + 1;
            if (front >= 0 && priQue.top().second > ratings[front]) {
                candies[index] = candies[front] + 1;
            }
            if (back < ratings.size() && priQue.top().second > ratings[back]) {
                candies[index] = max(candies[index], candies[back] + 1);
            }
            priQue.pop();
        }

        // sum up
        int sum = 0;
        for (int num : candies) {
            sum += num;
        }
        return sum;
    }
};


int main(int argc, char* argv[]) {
    Solution solution;
    vector<vector<int>> input{{1,2,3,4,2}, {3,2,1,2}, {1,0,1,1,2}};
    for (int i = 0; i < input.size(); i++) {
        cout << solution.candy(input[i]) << "\n";
    }
}