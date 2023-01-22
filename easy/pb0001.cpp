#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;

/*
#1 TwoSum
Attempt 1: Accepted
Use sort and binary_search to find twoSum
Complexity: O(NlogN)
Runtime: 13 ms (PR 81.19)
Memory: 10.3 MB (PR 73.92)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        vector<int> origin(nums.begin(), nums.end());
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++){
            bool find = false;
            int remain = target - nums.at(i);

            // Use binary search to find `remain`
            if (binary_search(nums.begin(), (nums.begin() + i), remain)) {
                find = true;
            } else if (binary_search((nums.begin() + i + 1), nums.end(), remain)) {
                find = true;
            }

            if (find == true) {
                int findOne = nums.at(i);
                int findTwo = remain;

                if (findOne == findTwo) {
                    int maxTwo = 0;
                    for (int i = 0; i < origin.size(); i++){
                        if (origin.at(i) == findOne) {
                            result.push_back(i);
                            maxTwo++;
                            if (maxTwo == 2) {
                                break;
                            }
                        }
                    }

                } else {
                    for (int i = 0; i < origin.size(); i++) {
                        if (origin.at(i) == findOne) {
                            result.push_back(i);
                            break;
                        }
                    }
                    for (int i = 0; i < origin.size(); i++) {
                        if (origin.at(i) == findTwo) {
                            result.push_back(i);
                            break;
                        }
                    }
                }
                break;
            }
        }

        return result;
    }
};

void output(vector<int> result) {
    cout << "[";
    for(int i = 0; i < result.size(); i++) {
        if((i + 1) == result.size()){
            // the last one
            cout << result.at(i) << "]\n";
        }else{
            cout << result.at(i) << ",";
        }
    }
}

int main(int argc, char* argv[]){
    int arr1[] = {2,7,11,15};
    int arr2[] = {3,2,4};
    int arr3[] = {3,3};

    vector<int> input1(arr1, arr1 + sizeof(arr1) / sizeof(int));
    vector<int> input2(arr2, arr2 + sizeof(arr2) / sizeof(int));
    vector<int> input3(arr3, arr3 + sizeof(arr3) / sizeof(int));

    Solution solution;
    output(solution.twoSum(input1, 9));
    output(solution.twoSum(input2, 6));
    output(solution.twoSum(input3, 6));
}