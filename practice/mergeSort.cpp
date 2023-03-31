#include <iostream>
#include <vector>
using namespace std;

void show(const vector<int>& nums) {
    if (nums.empty()) {
        cout << "[]\n";
        return;
    }
    cout << "[";
    for (int i = 0; i < nums.size() - 1; i++) {
        cout << nums[i] << ",";
    }
    cout << nums.back() << "]\n";
}
void mergeSort(vector<int>& nums, int left, int right) { // [left, right)
    if (left >= right || right == left + 1) return;
    int middle = left + (right - left) / 2;
    mergeSort(nums, left, middle);
    mergeSort(nums, middle, right);
    
    vector<int> leftTmp(nums.begin() + left, nums.begin() + middle);
    vector<int> rightTmp(nums.begin() + middle, nums.begin() + right);
    int lIndex = 0;
    int rIndex = 0;
    for (int i = left; i < right; i++) {
        if (lIndex >= leftTmp.size()) {
            nums[i] = rightTmp[rIndex];
            rIndex++;
            continue;
        }
        if (rIndex >= rightTmp.size()) {
            nums[i] = leftTmp[lIndex];
            lIndex++;
            continue;
        }
        if (leftTmp[lIndex] <= rightTmp[rIndex]) {
            nums[i] = leftTmp[lIndex];
            lIndex++;
        } else {
            nums[i] = rightTmp[rIndex];
            rIndex++;
        }
    }
}

int main() {
    vector<vector<int>> input{{4,2,6,5,1,3,7,9,8}, {3,2,6,5,1,1,2,6,7,8,9}, {9,8,7,6,5,4,3,2,1}, {1}};
    for (int i = 0; i < input.size(); i++) {
        show(input[i]);
        mergeSort(input[i], 0, input[i].size());
        show(input[i]);
        cout << "\n";
    }
}