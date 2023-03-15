#include <iostream>
#include <vector>
using namespace std;
const int BITS = 5000;
void show(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << "\n";
}

int sol(int num) {
    if (num == 0) return 0;
    if (num == 1) return 1;

    vector<vector<int>> table(num + 1, vector<int>(BITS, 0));
    table[1][0] = 1;
    for (int i = 2; i <= num; i++) {
        int flag = 0;
        for (int j = 0; j < BITS; j++) {
            int result = i * table[i - 1][j] + flag;
            table[i][j] = result % 10;
            flag = result / 10;
        }
        // show(table[i]);
    }
    
    int result = 0;
    for (int i = 0; i < table.back().size(); i++) {
        result += table.back()[i];
    }
    return result;
}

int main(int argc, char* argv[]) {
    int num = 0;
    while (cin >> num) {
        cout << sol(num) << "\n";
    }
}

/*
  2 3
  4 1

*/
// 23
//92
//943

//  43