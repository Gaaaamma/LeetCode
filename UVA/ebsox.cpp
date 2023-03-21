//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <stack>
#include <unordered_map>
#include <unordered_set>
using namespace std;
unordered_map<char, unordered_set<int>> finger;
unordered_set<int> c{1,2,3,6,7,8,9};
unordered_set<int> d{1,2,3,6,7,8};
unordered_set<int> e{1,2,3,6,7};
unordered_set<int> f{1,2,3,6};
unordered_set<int> g{1,2,3};
unordered_set<int> a{1,2};
unordered_set<int> b{1};

unordered_set<int> C{2};
unordered_set<int> D{0,1,2,3,6,7,8};
unordered_set<int> E{0,1,2,3,6,7};
unordered_set<int> F{0,1,2,3,6};
unordered_set<int> G{0,1,2,3};
unordered_set<int> A{0,1,2};
unordered_set<int> B{0,1};

void show(vector<int>& input) {
    for (int i = 0; i < input.size() - 1; i++) {
        cout << input[i] << " ";
    }
    cout << input.back() << "\n";
}
void solve(vector<int>& counter, string song) {
    if (song == "") return;
    for (auto index: finger[song[0]]) {
        counter[index]++;
    }
    for (int i = 1; i < song.size(); i++) {
        for (auto index: finger[song[i]]) {
            if (!finger[song[i - 1]].count(index))
                counter[index]++;
        }
    }
}
int main() {
    // Create finger
    finger['c'] = c;
    finger['d'] = d;
    finger['e'] = e;
    finger['f'] = f;
    finger['g'] = g;
    finger['a'] = a;
    finger['b'] = b;

    finger['C'] = C;
    finger['D'] = D;
    finger['E'] = E;
    finger['F'] = F;
    finger['G'] = G;
    finger['A'] = A;
    finger['B'] = B;

    int testcase = 0;
    string song = "";
    cin >> testcase;
    getline(cin, song);

    for (int i = 0; i < testcase; i++) {
        vector<int> counter(10, 0);
        getline(cin, song);
        solve(counter, song);
        show(counter);
    }
}