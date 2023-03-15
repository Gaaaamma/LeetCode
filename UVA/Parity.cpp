#include<iostream>
using namespace std;

string toBinary(int num) {
    if (num == 0) return "0";
    string result = "";
    while (num != 0) {
        result += to_string(num % 2);
        num /= 2;
    }
    reverse(result.begin(), result.end());
    return result;
}
int oneOfBinary(string binary) {
    int result = 0;
    for (int i = 0; i < binary.size(); i++) {
        if (binary[i] == '1')
            result++;
    }
    return result;
} 

int main() {
    int num = 0;
    while (cin >> num) {
        if (num == 0) break;
        cout << "The parity of " << toBinary(num) << " is " << oneOfBinary(toBinary(num)) << " (mod 2).\n";
    }
}