#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

int main() {
    string input = "";
    bool first = true;

    // Parsing
    while (getline(cin, input)) {
        for (int i = 0; i < input.size(); i++) {
            if (input[i] == '"' && first) {
                cout << "``";
                first = !first;
            } else if (input[i] == '"' && !first) {
                cout << "''";
                first = !first;
            } else {
                cout << input[i];
            }
        }
        cout << "\n";
    }
}