#include <iostream>
#include <vector>
using namespace std;
void show(vector<int>& input) {
    for (int i = 0; i < input.size(); i++) {
        cout << input[i] << " ";
    }
    cout << "\n";
}
void insert(vector<int>& nums) {
    for (int i = 1; i < nums.size(); i++) {
        int insertNum = nums[i];
        int seat = i - 1;
        while (seat >= 0) {
            if (nums[seat] <= insertNum) {
                break;
            } else {
                nums[seat + 1] = nums[seat];
                seat--;
            } 
        }
        nums[seat + 1] = insertNum;
    }
}

int main(int argc, char* argv[]) {
    vector<vector<int>> input{{4,1,6,2,4,7,7,8}, {5,4,3,2,1}, {1}, {1,2,3,4,5}};
    for (int i = 0; i < input.size(); i++) {
        insert(input[i]);
        show(input[i]);
    }
}