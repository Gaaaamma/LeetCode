#include <iostream>
#include <algorithm> 
#include <vector>
#include <stack>
using namespace std;

/*
#150 Evaluate Reverse Polish Notation
Attempt 1: 
Use stack to compute postfix representation

Complexity: O(N)

Q: You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.
   Evaluate the expression. Return an integer that represents the value of the expression.

   Note that:
   - The valid operators are '+', '-', '*', and '/'.
   - Each operand may be an integer or another expression.
   - The division between two integers always truncates toward zero.
   - There will not be any division by zero.
   - The input represents a valid arithmetic expression in a reverse polish notation.
   - The answer and all the intermediate calculations can be represented in a 32-bit integer.
*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> solve;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/") {
                // Number => push to stack
                solve.push(stoi(tokens[i]));

            } else {
                // Operator
                int second = solve.top();
                solve.pop();
                int first = solve.top();
                solve.pop();

                if (tokens[i] == "+") solve.push(first + second);
                else if (tokens[i] == "-") solve.push(first - second);
                else if (tokens[i] == "*") solve.push(first * second);
                else if (tokens[i] == "/") solve.push(first / second);
            }
        }
        return solve.top();
    }
};

void output(vector<string> input) {
    if (input.empty()) {
        cout << "[]";
        return;
    }

    cout << "[";
    for (int i = 0; i < input.size() - 1; i++) {
        cout << input[i] << ", ";
    }
    cout << input[input.size() - 1] << "]";
}

int main(int argc, char* argv[]){
    vector<vector<string>> input{{"2","1","+","3","*"}, {"4","13","5","/","+"}, {"10","6","9","3","+","-11","*","/","*","17","+","5","+"}};
    
    Solution solution;
    for (int i = 0; i < input.size(); i++) {
        output(input[i]);
        cout << " = " << solution.evalRPN(input[i]) << "\n";
    }
}