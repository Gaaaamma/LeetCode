#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

/*
#946 Validate Stack Sequences
Attempt 1: 
stack

Q: Given two integer arrays pushed and popped each with distinct values, 
   return true if this could have been the result of a sequence of push and pop operations on an initially empty stack, 
   or false otherwise.
*/
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int push = 0;
        for (int i = 0; i < popped.size(); i++) {
            if (st.empty()) {
                if (push < pushed.size()) {
                    st.push(pushed[push]);
                    push++;
                    i--;
                } else return false;
            } else {
                if (st.top() == popped[i]) st.pop();
                else if (push < pushed.size()) {
                    st.push(pushed[push]);
                    push++;
                    i--;
                } else return false;
            }
        }
        return true;
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
    vector<pair<vector<int>, vector<int>>> input{{{1,2,3,4,5}, {4,5,3,2,1}}, {{1,2,3,4,5}, {4,3,5,1,2}}};
    for (int i = 0; i < input.size(); i++) {
        cout << solution.validateStackSequences(input[i].first, input[i].second) << "\n";
    }
}