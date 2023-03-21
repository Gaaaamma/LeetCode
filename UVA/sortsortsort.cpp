//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <stack>
#include <unordered_map>
using namespace std;

int main() {
    int N = 0;
    int M = 0;
    while (cin >> N >> M) {
        cout << N << " " << M << "\n";
        if (N == 0 && M == 0) break;
        vector<pair<int, int>> nums;
        nums.reserve(N);

        for (int i = 0; i < N; i++) {
            int num = 0;
            cin >> num;
            nums.push_back(pair<int, int>{num, num % M});
        }

        // Solve
        sort(nums.begin(), nums.end(), [](pair<int, int> a, pair<int, int> b){
            if (a.second < b.second) return true;
            else if (a.second == b.second) {
                if (a.first % 2 == 1 && b.first % 2 == 0) {
                    return true;
                } else if (a.first % 2 == 0 && b.first % 2 == 0) {
                    return a.first < b.first;
                } else if (a.first % 2 == 1 && b.first % 2 == 1) {
                    return a.first > b.first;
                }
            }
            return false;
        });
        for (int i = 0; i < nums.size(); i++) {
            cout << nums[i].first << "\n";
        }
    }
}