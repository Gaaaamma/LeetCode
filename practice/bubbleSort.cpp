#include <iostream>
#include <vector>
using namespace std;

void bubble(vector<int>& nums) {
    for (int i = 0; i < nums.size() - 1; i++) {
        for (int j = 0; j < nums.size() - 1 - i; j++) {
            if (nums[j] > nums[j + 1]) 
                swap(nums[j], nums[j + 1]);
        }
    }
}
void show(vector<int>& input) {
    for (int i = 0; i < input.size(); i++) {
        cout << input[i] << " ";
    }
    cout << "\n";
}
int main(int argc, char* argv[]) {
    vector<vector<int>> input{{4,1,6,2,4,7,7,8}, {5,4,3,2,1}, {1}};
    for (int i = 0; i < input.size(); i++) {
        bubble(input[i]);
        show(input[i]);
    }
}