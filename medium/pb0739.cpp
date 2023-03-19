#include <iostream>
#include <vector>
#include <stack>
#include <numeric>
#include <queue>
using namespace std;

/*
#739 Daily Temperatures
Attempt 1: 
Use stack to solve

Q: Given an array of integers temperatures represents the daily temperatures, 
   return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. 
   If there is no future day for which this is possible, keep answer[i] == 0 instead.
*/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);
        deque<pair<int, int>> temp;
        for (int i = 0; i < temperatures.size(); i++) {
            if (temp.empty() || temp.back().second >= temperatures[i]) {
                temp.push_back({i, temperatures[i]});
            } else {
                while (!temp.empty()) {
                    if (temp.back().second < temperatures[i]) {
                        result[temp.back().first] = i - temp.back().first;
                        temp.pop_back();
                    } else {
                        break;
                    }
                }
                temp.push_back({i, temperatures[i]});
            }
        }

        return result;
    }
};
void show(vector<int> input) {
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
int main(int argc, char* argv[]) {
    Solution solution;
    vector<vector<int>> input{{73,74,75,71,69,72,76,73}, {30,40,50,60}, {30,60,90}, {5,4,3,2,6}};
    for (int i = 0; i < input.size(); i++) {
        show(solution.dailyTemperatures(input[i]));
    }
}