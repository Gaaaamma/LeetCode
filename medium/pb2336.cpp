#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

/*
#2336 Smallest Number in Infinite Set
Attempt 1: 
priority_queue and unordered_map

Q: You have a set which contains all positive integers [1, 2, 3, 4, 5, ...].
   Implement the SmallestInfiniteSet class:
    - SmallestInfiniteSet() Initializes the SmallestInfiniteSet object to contain all positive integers.
    - int popSmallest() Removes and returns the smallest integer contained in the infinite set.
    - void addBack(int num) Adds a positive integer num back into the infinite set, if it is not already in the infinite set.
   
   Constraints:
    - 1 <= num <= 1000
    - At most 1000 calls will be made in total to popSmallest and addBack.

*/

struct Compare{
    bool operator()(int a, int b) {
        return a > b;
    }
};
class SmallestInfiniteSet {
public:
    unordered_map<int, bool> exist;
    priority_queue<int, vector<int>, Compare> pq;
    SmallestInfiniteSet() {
        exist.clear();
        vector<int> base(1000, 1);
        for (int i = 1; i <= 1000; i++) {
            base[i - 1] = i; 
            exist[i] = true;
        }
        pq = priority_queue<int, vector<int>, Compare>(base.begin(), base.end());
    }
    
    int popSmallest() {
        int result = pq.top();
        exist[result] = false;
        pq.pop();
        return result;
    }
    
    void addBack(int num) {
        if (exist[num] == false) {
            exist[num] = true;
            pq.push(num);
        }
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
    SmallestInfiniteSet* sset = new SmallestInfiniteSet();
    sset->addBack(2); // Already exist
    cout << sset->popSmallest() << "\n";
    cout << sset->popSmallest() << "\n";
    cout << sset->popSmallest() << "\n";
    sset->addBack(1);
    cout << sset->popSmallest() << "\n";
    cout << sset->popSmallest() << "\n";
    cout << sset->popSmallest() << "\n";
}