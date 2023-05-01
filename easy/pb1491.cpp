#include <iostream>
#include <vector>
#include <unordered_map>
#include <iomanip>
#include <queue>
using namespace std;

/*
#1491 Average Salary Excluding Minimum and Maximum Salary
Attempt 1: 
two pointer

Q: You are given an array of unique integers salary where salary[i] is the salary of the ith employee.
   Return the average salary of employees excluding the minimum and maximum salary. 
   Answers within 10-5 of the actual answer will be accepted.
*/

class Solution {
public:
    double average(vector<int>& salary) {
        if (salary.size() <= 2) return 0;
        int minimum = 10000000;
        int maximum = 0;
        double sum = 0.0;
        for (int i = 0; i < salary.size(); i++) {
            sum += salary[i];
            minimum = (salary[i] < minimum) ? salary[i] : minimum;
            maximum = (salary[i] > maximum) ? salary[i] : maximum;
        }
        sum -= minimum;
        sum -= maximum;
        return sum / (salary.size() - 2);
    }
};

template<class T>
void show1D(const vector<T>& input) {
    if (input.empty()) {
        cout << "[]\n";
        return;
    }
    cout << "[";
    for (int i = 0; i < input.size() - 1; i++) {
        cout << input[i] << ",";
    }
    cout << input.back() << "]\n";
}
template<class T>
void show2DGraph(const vector<vector<T>>& input) {
    for (int i = 0; i < input.size(); i++) {
        show1D(input[i]);
    }
}

int main(int argc, char* argv[]) {
    Solution solution;
    vector<vector<int>> input{{1000, 2000, 3000}, {4000,3000,1000,2000}, {1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000}};
    for (int i = 0; i < input.size(); i++) {
        cout << solution.average(input[i]) << "\n";
    }
}
