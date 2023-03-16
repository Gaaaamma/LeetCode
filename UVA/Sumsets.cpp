#include <iostream>
#include <vector>
using namespace std;

bool solve(vector<int>& nums, int& result) {
    sort(nums.begin(), nums.end());
    for (int t = nums.size() - 1; t >= 0; t--) {
        for (int i = 0; i < nums.size(); i++) {
            if (i == t) continue;
            for (int j = i + 1; j < nums.size(); j++) {
                if (j == t) continue;
                for (int k = j + 1; k < nums.size(); k++) {
                    if (k == t) continue;
                    result = nums[i] + nums[j] + nums[k];
                    if (result == nums[t]) return true;
                }
            }
        }
    }
    return false;
}

int main(int argc, char* argv[]) {
    int n = 0;
    while (cin >> n) {
        if (n == 0) break;
        vector<int> nums(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        int result = 0;
        if (solve(nums, result)) {
            cout << result << "\n";
        } else {
            cout << "no solution\n";
        }
    }   
}