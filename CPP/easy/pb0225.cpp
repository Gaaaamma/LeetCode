#include <iostream>
#include <algorithm> 
#include <vector>
#include <queue>
using namespace std;

/*
#225 Implement Stack using Queues
Attempt 1: 
Use only one queue can achieve

Complexity: O(-)

Q: Implement a last-in-first-out (LIFO) stack using only two queues. 
   The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).

   Implement the MyStack class:
   -  void push(int x) Pushes element x to the top of the stack.
   -  int pop() Removes the element on the top of the stack and returns it.
   -  int top() Returns the element on the top of the stack.
   -  boolean empty() Returns true if the stack is empty, false otherwise.

   Notes:
   - You must use only standard operations of a queue, 
     which means that only push to back, peek/pop from front, size and is empty operations are valid.
   - Depending on your language, the queue may not be supported natively. 
     You may simulate a queue using a list or deque (double-ended queue) as long as you use only a queue's standard operations.
*/     

class MyStack {
public:
    int size;
    queue<int> input;  
    MyStack() {
        size = 0;
    }
    
    void push(int x) {
        input.push(x);
        size++;
    }
    
    int pop() {
        int count = size - 1;
        while (count > 0) {
            int tmp = input.front();
            input.pop();
            input.push(tmp);
            count--;
        }
        int result = input.front();
        input.pop();
        size--;
        return result;
    }
    
    int top() {
        int result = pop();
        push(result);
        return result;
    }
    
    bool empty() {
        return input.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

int main(int argc, char* argv[]){
    MyStack* myStack = new MyStack();
    cout << "Empty: " << myStack->empty() << "\n";
    myStack->push(10);
    myStack->push(20);
    myStack->push(30);
    cout << "Empty: " << myStack->empty() << "\n";
    cout << "Top: " << myStack->top() << "\n";
    cout << "Pop: " << myStack->pop() << "\n";
    cout << "Top: " << myStack->top() << "\n";
    cout << "Pop: " << myStack->pop() << "\n";
    cout << "Top: " << myStack->top() << "\n";
    cout << "Pop: " << myStack->pop() << "\n";
    cout << "Empty: " << myStack->empty() << "\n";

}