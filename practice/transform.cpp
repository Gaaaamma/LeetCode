#include <iostream>
#include <bitset>
#include <sstream>
using namespace std;

string trim(string num) {
    string result = num;
    for (int i = 0; i < result.size(); i++) {
        if (result[i] != '0') {
            result = result.substr(i, -1);
            break;
        }
    }
    return result;
}
int main() {
    int num = 0;
    stringstream ss;
    while (cin >> num) {
        cout << "Decimal: " << num << "\n";
        cout << "Binary: " << trim(bitset<32>(num).to_string()) << "\n";

        string hexFormat = "0x" + to_string(num);
        ss << hex << hexFormat;
        unsigned long long hexNum = 0;
        ss >> hexNum;
        cout << "Hex: " << hexFormat << "\n";
        cout << "Val: " << hexNum << "\n";
        cout << "ToBinary: " << trim(bitset<32>{hexNum}.to_string()) << "\n";
        ss.str("");
        ss.clear();
    }
}