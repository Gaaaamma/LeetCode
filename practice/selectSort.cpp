#include <iostream>
#include <vector>
using namespace std;

void select(vector<int>& input) {
    for (int i = 0; i < input.size() - 1; i++) {
        int max = INT_MIN;
        int index = 0;
        for (int j = 0; j < input.size() - i; j++) {
            if (input[j] > max) {
                max = input[j];
                index = j;
            }
        }
        swap(input[index], input[input.size() - 1 - i]);
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
        select(input[i]);
        show(input[i]);
    }
}