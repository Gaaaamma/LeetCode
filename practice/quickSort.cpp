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
    if (l >= r) return l;
    int pivot = nums[l];
    int findBig = l + 1;
    int findSmall = r;
    while (findBig <= findSmall) {
        while (findBig <= r && nums[findBig] <= pivot) findBig++;
        while (findSmall >= l && nums[findSmall] > pivot) findSmall--;
        if (findBig <= findSmall) swap(nums[findBig], nums[findSmall]);
    }
    swap(nums[l], nums[findSmall]);
    return findSmall;
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