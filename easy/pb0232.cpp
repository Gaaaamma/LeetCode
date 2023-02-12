#include <iostream>
#include <algorithm> 
#include <vector>
#include <stack>
using namespace std;

/*
#232 Implement Queue using Stacks
Attempt 1: 
Use two stack(input/output) to implement queue

Complexity: O(-)

Q: Implement a first in first out (FIFO) queue using only two stacks. 
   The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

   Implement the MyQueue class:

   -  void push(int x) Pushes element x to the back of the queue.
   -  int pop() Removes the element from the front of the queue and returns it.
   -  int peek() Returns the element at the front of the queue.
   -  boolean empty() Returns true if the queue is empty, false otherwise.

   Notes:
   -  You must use only standard operations of a stack, 
      which means only push to top, peek/pop from top, size, and is empty operations are valid.
   -  Depending on your language, the stack may not be supported natively. 
      You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.
*/     

class MyQueue {
public:
    stack<int> input;
    stack<int> output;
    MyQueue() {
        
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        int result = INT_MAX;
        if (output.empty()) {
            // Move all elements in input to output
            while (!input.empty()) {
                int top = input.top();
                output.push(top);
                input.pop();
            }
        }
        result = output.top();
        output.pop();
        return result;
    }
    
    int peek() {
        if (output.empty()) {
            // Move all elements in input to output
            while (!input.empty()) {
                int top = input.top();
                output.push(top);
                input.pop();
            }
        }
        return output.top();
    }
    
    bool empty() {
        if (input.empty() && output.empty()) {
            return true;
        } else {
            return false;
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
int main(int argc, char* argv[]){
    MyQueue* myQueue = new MyQueue;
    cout << "Empty: " << myQueue->empty() << "\n";
    myQueue->push(10);
    myQueue->push(20);
    cout << "Peek: " << myQueue->peek() << "\n";
    cout << "Empty: " << myQueue->empty() << "\n";
    cout << "Pop: " << myQueue->pop() << "\n";
    cout << "Peek: " << myQueue->peek() << "\n";
    cout << "Pop: " << myQueue->pop() << "\n";
    cout << "Empty: " << myQueue->empty() << "\n";
}