#include <iostream>
#include <vector>
using namespace std;
void show(vector<int>& input) {
    for (int i = 0; i < input.size(); i++) {
        cout << input[i] << " ";
    }
    cout << "\n";
}

// [l, r]
int partition(vector<int>& nums, int l, int r) {
    int slow = l;
    int pivot = nums[r];
    for (int fast = l; fast < r; fast++) {
        if (nums[fast] <= pivot) {
            swap(nums[slow], nums[fast]);
            slow++;
        }
    }
    swap(nums[slow], nums[r]);
    return slow;
}
void quickSort(vector<int>& nums, int l, int r) {
    if (l >= r) return;
    int middle = partition(nums, l, r);
    quickSort(nums, l, middle - 1);
    quickSort(nums, middle + 1, r);
}

int main(int argc, char* argv[]) {
    vector<vector<int>> input{{4,1,6,2,4,7,7,8}, {5,4,3,2,1}, {1}, {1,2,3,4,5}};
    for (int i = 0; i < input.size(); i++) {
        quickSort(input[i], 0, input[i].size() - 1);
        show(input[i]);
    }
}