#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
#155 Min Stack
Attempt 1: 
Monotonic Stack

Q: Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
   Implement the MinStack class:
   
   MinStack() initializes the stack object.

   void push(int val) pushes the element val onto the stack.
   
   void pop() removes the element on the top of the stack.
   
   int top() gets the top element of the stack.
   
   int getMin() retrieves the minimum element in the stack.
   
   You must implement a solution with O(1) time complexity for each function.
*/
class MinStack {
public:
    stack<int> dec;
    vector<int> mStack;
    MinStack() {
        dec = stack<int>();
        mStack.clear();
    }
    
    void push(int val) {
        mStack.push_back(val);
        if (dec.empty() || val <= dec.top()) dec.push(val);
    }
    
    void pop() {
        if (mStack.back() == dec.top()) dec.pop();
        mStack.pop_back();
    }
    
    int top() {
        return mStack.back();
    }
    
    int getMin() {
        return dec.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
int main(int argc, char* argv[]) {
    MinStack* minStack = new MinStack();
    cout << "minStack->push(" << 1 << ")\n";
    minStack->push(1);
    cout << "minStack->push(" << 2 << ")\n";
    minStack->push(2);
    cout << "minStack->push(" << 3 << ")\n";
    minStack->push(3);
    cout << "minStack->getMin(): " << minStack->getMin() << "\n";
    minStack->pop();
    cout << "minStack->pop()\n";
    cout << "minStack->getMin(): " << minStack->getMin() << "\n";

    cout << "minStack->push(" << -1 << ")\n";
    minStack->push(-1);

    cout << "minStack->push(" << -2 << ")\n";
    minStack->push(-2);
    cout << "minStack->getMin(): " << minStack->getMin() << "\n";
    minStack->pop();
    cout << "minStack->pop()\n";

    cout << "minStack->getMin(): " << minStack->getMin() << "\n";
    minStack->pop();
    cout << "minStack->pop()\n";
    cout << "minStack->getMin(): " << minStack->getMin() << "\n";
}