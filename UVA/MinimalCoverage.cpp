#include<iostream>
#include<vector>
using namespace std;
int solve(int rangeM, vector<pair<int, int>>& interval, vector<pair<int, int>>& answer) {
    if (interval.empty()) return 0;
    sort(interval.begin(), interval.end(), [](pair<int, int> a, pair<int, int> b){return a.first < b.first;});
    
    int left = 0;
    int right = 0;
    int index = -1;
    for (int i = 0; i < interval.size(); i++) {
        if (interval[i].first <= left && interval[i].second > right) {
            index = i;
            right = interval[i].second;
            if (right >= rangeM) break;
        } else if (interval[i].first > left) {
            // insert or break;
            if (index != -1) {
                answer.push_back(interval[index]);
                left = right;
                index = -1;
                i--;
            } else {
                break;
            }
        }
    }
    // Push last one
    if (index != -1) {
        answer.push_back(interval[index]);
        left = right;
    }

    if (left < rangeM) {
        answer.clear();
        return 0;
    } 
    return answer.size();
}

int main() {
    int testcase = 0;
    cin >> testcase;
    for (int i = 0; i < testcase; i++) {
        int rangeM = 0;
        int left = 0;
        int right = 0;
        vector<pair<int ,int>> interval;
        vector<pair<int, int>> answer;

        cin >> rangeM;
        while (cin >> left >> right) {
            if (left == 0 && right == 0) break;
            interval.push_back(pair<int, int>{left, right});
        }

        int count = solve(rangeM, interval, answer);
        cout << count << "\n";
        for (int i = 0; i < answer.size(); i++) {
            cout << answer[i].first << " " << answer[i].second << "\n";
        }
        if (i != testcase - 1) cout << "\n";
    }
}