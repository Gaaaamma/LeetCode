#include <iostream>
#include <algorithm> 
#include <vector>
#include <unordered_map>
using namespace std;

/*
#347 Top K Frequent Elements
Attempt 1: 
(1) Use unordered_map to calculate the frequency = O(N)
(2) Copy unordered_map to vector<pair<int, int>> 
(3) Sort the vector by pair.second = O(NlogN)

Complexity: O(NlogN)

Q: Given an integer array nums and an integer k, 
   return the k most frequent elements. You may return the answer in any order.
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Create frequency
        vector<int> result;
        unordered_map<int, int> freq;
        for (int i = 0; i < nums.size(); i++) {
            if (freq.count(nums[i])) {
                freq[nums[i]]++;
            } else {
                freq[nums[i]] = 1;
            }
        }

        // Find topK
        vector<pair<int, int>> tmp{freq.begin(), freq.end()};
        sort(tmp.begin(), tmp.end(), [](pair<int,int> a, pair<int, int> b){return a.second > b.second;});
        for (int i = 0; i < k; i++) {
            result.push_back(tmp[i].first);
        }
        return result;
    }
};

void output(vector<int> input) {
    if (input.empty()) {
        cout << "[]\n";
        return;
    }

    cout << "[";
    for (int i = 0; i < input.size() - 1; i++) {
        cout << input[i] << ", ";
    }
    cout << input[input.size() - 1] << "]\n";
}

int main(int argc, char* argv[]){
    vector<pair<vector<int>, int>> input{{{1,1,1,2,2,3}, 2}, {{1}, 1}, {{1,2,3,4,5,4,3,2,3,2,3}, 3}};
    Solution solution;

    for (int i = 0; i < input.size(); i++) {
        output(solution.topKFrequent(input[i].first, input[i].second));
    }
}