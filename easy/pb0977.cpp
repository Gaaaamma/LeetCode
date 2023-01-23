#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;

/*
#27 SquaresOfSortedArray
Attempt 1: 
(First try) Square all the elements and just call sort to sort = O(NlogN)
(Second try) Two pointers (positive & negative)
Compare positive^2 and negative^2 and judge who can be put to result
| - - - <=negative positive=> - - - |
Complexity: O(N)
*/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // Use the concept of two pointers
        vector<int> result;
        int positive = -1;
        int negative = -1;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= 0) {
                positive = i;
                negative = i - 1;
                break;
            }
        }

        // Edge case
        if (positive == -1) {
            negative = nums.size() - 1;
        }

        // Judge and insert the answer to result
        while ((positive < nums.size() && positive >= 0) && negative >=0) {
            int poSq = nums[positive] * nums[positive];
            int neSq = nums[negative] * nums[negative];

            if (poSq < neSq) {
                result.push_back(poSq);
                positive++;
            } else if (poSq > neSq) {
                result.push_back(neSq);
                negative--;
            } else {
                result.push_back(poSq);
                result.push_back(neSq);
                positive++;
                negative--;
            }
        }

        // Clear
        while (positive < nums.size() && positive >= 0) {
            result.push_back(nums[positive] * nums[positive]);
            positive++;
        }

        while (negative >= 0) {
            result.push_back(nums[negative] * nums[negative]);
            negative--;
        }

        return result;
    }
};

void output(vector<int> nums) {
    for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
        cout << *it << " ";
    }
    cout << "\n";
}

int main(int argc, char* argv[]){
    int arr1[] = {-4,-1,0,3,10};
    int arr2[] = {-7,-3,2,3,11};
    int arr3[] = {-7,-6,-3,-2,-1};
    int arr4[] = {1,3,5,6,7};

    vector<int> input1(arr1, arr1 + sizeof(arr1) / sizeof(int));
    vector<int> input2(arr2, arr2 + sizeof(arr2) / sizeof(int));
    vector<int> input3(arr3, arr3 + sizeof(arr3) / sizeof(int));
    vector<int> input4(arr4, arr4 + sizeof(arr4) / sizeof(int));
    
    Solution solution;
    output(solution.sortedSquares(input1));
    output(solution.sortedSquares(input2));
    output(solution.sortedSquares(input3));
    output(solution.sortedSquares(input4));
}