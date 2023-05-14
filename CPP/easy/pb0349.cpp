#include <iostream>
#include <algorithm> 
#include <vector>
#include <unordered_set>
using namespace std;

/*
#349 Intersection of Two Arrays
Attempt 1: 
Use two unordered_set to solve this problem
1) To keep which number had been judged (Didn't need to judge again)
2) To keep a number is in nums2 or not
We traverse nums1 and check unordered_set2 to see if this number is the intersection

Complexity: O(N)

Q: Given two integer arrays nums1 and nums2, return an array of their intersection. 
   Each element in the result must be unique and you may return the result in any order.
*/     

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        unordered_set<int> judged;
        unordered_set<int> exist;

        // Use nums2 to create exist set 
        for (int i = 0; i < nums2.size(); i++) {
            exist.insert(nums2[i]);
        }

        // Judge nums1
        for (int i = 0; i < nums1.size(); i++) {
            // Haven't judge this number before
            if (judged.count(nums1[i]) == 0) {
                judged.insert(nums1[i]);

                if (exist.count(nums1[i])) {
                    result.push_back(nums1[i]);
                }
            }
        }
        return result;
    }
};

void output(vector<int> nums) {
    if (nums.empty()) {
        cout << "[]\n";
    } else {
        cout << "[";
        for (int i = 0; i < nums.size() - 1; i++) {
            cout << nums[i] << ", ";
        }
        cout << nums[nums.size() - 1] << "]\n";
    }
}

int main(int argc, char* argv[]){
    vector<pair<vector<int>, vector<int> > >input;
    input.push_back(make_pair(vector<int>{1, 2, 2, 1}, vector<int>{2, 2}));
    input.push_back(make_pair(vector<int>{4, 9, 5}, vector<int>{9, 4, 9, 8, 4}));

    Solution solution;
    for (int i = 0; i < input.size(); i++) {
        output(solution.intersection(input[i].first, input[i].second));
    }
}