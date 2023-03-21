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

struct Robot {
    int x;
    int y;
    int face;
    bool lose;
    Robot(int x, int y, int face) : x(x), y(y), face(face), lose(false) {};
};
vector<char> coordination{'N', 'E', 'S', 'W'};
int main() {
    int gbX, gbY;
    cin >> gbX >> gbY;
    
    vector<vector<bool>> table(gbX + 1, vector<bool>(gbY + 1, false));
    int localX, localY;
    char face;
    string command;
    vector<Robot> robots;
    while (cin >> localX >> localY >> face) {
        vector<char>::iterator faceIt = find(coordination.begin(), coordination.end(), face);
        robots.push_back(Robot(localX, localY, distance(coordination.begin(), faceIt)));
        getline(cin, command);
        getline(cin, command);
        if (command == "") continue;
        for (int i = 0; i < command.size(); i++) {
            if (command[i] == 'L') {
                robots.back().face -= 1;
                if (robots.back().face < 0 ) robots.back().face = 3;
            } else if (command[i] == 'R') {
                robots.back().face = (robots.back().face + 1) % 4;
            } else if (command[i] == 'F') {
                if (robots.back().face == 0) {
                    robots.back().y += 1;
                    if (robots.back().y > gbY) {
                        robots.back().y -= 1;
                        if (table[robots.back().x][robots.back().y] == false) {
                            table[robots.back().x][robots.back().y] = true;
                            robots.back().lose = true;
                            break;
                        }
                    }
                } else if (robots.back().face == 1) {
                    robots.back().x += 1;
                    if (robots.back().x > gbX) {
                        robots.back().x -= 1;
                        if (table[robots.back().x][robots.back().y] == false) {
                            table[robots.back().x][robots.back().y] = true;
                            robots.back().lose = true;
                            break;
                        }
                    }
                } else if (robots.back().face == 2) {
                    robots.back().y -= 1;
                    if (robots.back().y < 0) {
                        robots.back().y += 1;
                        if (table[robots.back().x][robots.back().y] == false) {
                            table[robots.back().x][robots.back().y] = true;
                            robots.back().lose = true;
                            break;
                        }
                    }
                } else if (robots.back().face == 3) {
                    robots.back().x -= 1;
                    if (robots.back().x < 0) {
                        robots.back().x += 1;
                        if (table[robots.back().x][robots.back().y] == false) {
                            table[robots.back().x][robots.back().y] = true;
                            robots.back().lose = true;
                            break;
                        }
                    }
                }
            }
        }
    }

    // show
    for (int i = 0; i < robots.size(); i++) {
        cout << robots[i].x << " " << robots[i].y << " " << coordination[robots[i].face];
        if (robots[i].lose) cout << " LOST\n";
        else cout << "\n";
    }
}