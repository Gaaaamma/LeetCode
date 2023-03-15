#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void show(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << "\n";
}

string bigAdd(vector<int>& num1, vector<int>& num2) {
    string rtn = "";
    vector<int> result;
    
    int flag = 0;
    for (int i = num1.size() - 1; i >= 0; i--) {
        int sum = num1[i] + num2[i] + flag;
        if (sum >= 10) {
            flag = 1;
            sum %= 10;
        } else {
            flag = 0;
        }
        rtn += to_string(sum);
    }

    reverse(rtn.begin(), rtn.end());
    int index = 0;
    for (int i = 0; i < rtn.size(); i++) {
        if (rtn[i] != '0') {
            index = i;
            break;
        }
    }
    return rtn.substr(index, -1);
}

int main(int argc, char* argv[]) {
    int testcase = 0;
    int digits = 0;

    cin >> testcase;
    for (int i = 0; i < testcase; i++) {
        cin >> digits;

        vector<int> num1, num2;
        num1.reserve(digits);
        num2.reserve(digits);
        for (int d = 0; d < digits; d++) {
            int a, b = 0;
            cin >> a >> b;
            num1.push_back(a);
            num2.push_back(b);
        }
        // show(num1);
        // show(num2);
        cout << bigAdd(num1, num2) << "\n";
        if (i != testcase - 1) cout << "\n";
    }
}